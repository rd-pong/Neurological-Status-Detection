%% Preliminaries
% Add toolbox folder to path
addpath 'wfdb-app-toolbox-0-10-0\mcode'
clear; clc; close all;

%% Read in and construct data to stack using for-loop
X_stack = [];
Y_stack = [];

for i = 1:20
    [X_AccTempEDA, Y] = AccTempEDAToMatrix(char('nonEEGdataset/Subject' + string(i) + '_AccTempEDA'), 0);
    [X_SpO2HR] = SpO2HRToMatrix(char('nonEEGdataset/Subject' + string(i) + '_AccTempEDA'), 0);
    X_stack = [
            X_AccTempEDA X_SpO2HR(1:height(X_AccTempEDA), :); 
            X_stack];
    Y_stack = [Y; Y_stack];
end
XY = [X_stack array2table(Y_stack)];

%% LEGACY/DEBUG ONLY --- Read in AccTempEDA / SpO2HR
% [X1_AccTempEDA, Y1] = AccTempEDAToMatrix('nonEEGdataset/Subject1_AccTempEDA', 0);
% [X2_AccTempEDA, Y2] = AccTempEDAToMatrix('nonEEGdataset/Subject2_AccTempEDA', 0);
% ...
% [X20_AccTempEDA, Y20] = AccTempEDAToMatrix('nonEEGdataset/Subject20_AccTempEDA', 0);
% 
% [X1_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject1_SpO2HR', 0);
% [X2_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject2_SpO2HR', 0);
% ...
% [X20_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject20_SpO2HR', 0);
% 
% % Split data
% X_stack = [
%         X1_AccTempEDA X1_SpO2HR(1:height(X1_AccTempEDA), :);
%         X2_AccTempEDA X2_SpO2HR(1:height(X2_AccTempEDA), :);
%         ...;
%         X19_AccTempEDA X19_SpO2HR(1:height(X19_AccTempEDA), :)];
% Y_stack = [Y1; Y2; ...; Y19];
% XY = [X_stack array2table(Y_stack)];

%% kNN Train & Test
mdl = fitcknn(X_stack, Y_stack, 'NumNeighbors', 3, 'Standardize', 1);
label = predict(mdl, [X20_AccTempEDA X20_SpO2HR(1:height(X20_AccTempEDA), :)]);

% success rate count
correct_mark = zeros(length(label), 1);
for i = 1:length(label)

    if label(i) == Y20(i)
        correct_mark(i) = 1;
    else
        correct_mark(i) = 0;
    end

end
success_rate = sum(correct_mark) / length(label)

% 
rloss = resubLoss(mdl)

%% Classification Model 
% Classification Model can be generated using 'Classification Learner'
% Evaluate confusion matrix & Learner using Classificaton Learner

%% LEGACY 
% % Evaluate/Comparison Classification Model - Confusion Matrix
% % Randomize the measurements and groups in the data.
% rng(0,'twister'); % For reproducibility
% numObs = height(X_stack);
% p = randperm(numObs);
% X_stack = X_stack(p,:);
% Y_stack = Y_stack(p);
% 
% % Train a classifier by using measurements in the first portion of the data.
% portion_mark = floor(numObs/30);
% training = X_stack(1:portion_mark,:);
% trainingSpecies = Y_stack(1:portion_mark);
% %-----------Change Model BELOW----------------
% Mdl = fitcdiscr(training, trainingSpecies);
% 
% %-----------Change Model ABOVE---------------
% 
% % Predict labels for the measurements in the second half of the data by using the trained classifier.
% sample = X_stack(portion_mark+1:end,:);
% grouphat = predict(Mdl,sample);
% 
% % Specify the group order and display the confusion matrix for the resulting classification.
% group = Y_stack(portion_mark+1:end);
% [C,order] = confusionmat(group,grouphat);
% cm = confusionchart(grouphat,group)

%% TODO: Evaluate Classification Model - Cross Validation
X = X_stack;
Y = num2cell(Y_stack);
cp = classperf(Y)
for i = 1:10
    [train,test] = crossvalind('LeaveMOut',Y,5);
    mdl = fitcknn(X(train,:),Y(train),'NumNeighbors',3);
    predictions = predict(mdl,X(test,:));
    classperf(cp,predictions,test);
end

%% Prepare trained classification model for Coder/Conversion 
% use above code to train model named 'mdl'
% saveLearnerForCoder(mdl,'RF_model');

% Classification Learning APP and export compact model, then call below
% Refer to MATLAB doc: Code Generation and Classification Learner App
saveLearnerForCoder(trainedModel.ClassificationEnsemble,'RF_model');

%% Neural Network Train & Test
% reorganize training data/label
X_array = table2array(X_stack);
Y_array = Y_stack;
Y_array_flag = [];
for i = 1: length(Y_array)
    if Y_array(i) == 0
        Y_array_flag = [[1 0 0 0]; Y_array_flag];
    elseif Y_array(i) == 1
        Y_array_flag = [[0 1 0 0]; Y_array_flag];
    elseif Y_array(i) == 2
        Y_array_flag = [[0 0 1 0]; Y_array_flag];
    elseif Y_array(i) == 3
        Y_array_flag = [[0 0 0 1]; Y_array_flag];
    end
end

% design/train network
net = fitnet(10,'traingd');
view(net)
[net,tr] = train(net, X_array', Y_array_flag');

% test network
y = net(X_array'); % net is not a function, its just the 'net' we trained above
perf = perform(net,y,Y_array_flag')

% Saving the network weights and biases
net.IW;
net.LW;
net.b;

% save network for coder
genFunction(net, 'NN_model', 'MatrixOnly','yes');

%% Get final prediction of NN as 0, 1, 2, 3, rather than [1, 0, 0, 0], [0, 1, 0, 0], ...
% get result (4*14497-->1*14497)
y_distance_to_1 = abs(y - ones(size(y)));
y_predict = [];
for i = 1: length(y)
    column_buff = y_distance_to_1(:, 1)
    min_idx = find(column_buff == min(column_buff(:))) - 1;
    y_predict = [min_idx y_predict];
end

