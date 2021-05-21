%%%%%%%
% This is the main script for debugging
%%%%%%%

%% Preliminaries
% Add toolbox folder to path
clear; clc; close all;
addpath 'wfdb-app-toolbox-0-10-0\mcode'


%% Read in and construct data to stack using for-loop
X_stack = [];
Y_stack = [];

for i = 1:20
    [X_AccTempEDA, Y] = AccTempEDAToMatrix(char('nonEEGdataset/Subject' + string(i) + '_AccTempEDA'), 0);
    [X_SpO2HR] = SpO2HRToMatrix(char('nonEEGdataset/Subject' + string(i) + '_SpO2HR'), 0);
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

%% %%%%%%%%%%%%%%%%%%%%Classification%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% kNN Train & Test
mdl = fitcknn(X_stack, Y_stack, 'NumNeighbors', 3, 'Standardize', 1);
% label = predict(mdl, [X20_AccTempEDA X20_SpO2HR(1:height(X20_AccTempEDA), :)]);
label = predict(mdl, X_stack);

% success rate count
correct_mark = zeros(length(label), 1);
for i = 1:length(label)

    if label(i) == Y_stack(i)
        correct_mark(i) = 1;
    else
        correct_mark(i) = 0;
    end

end
success_rate = sum(correct_mark) / length(label)

% rloss below seems to equals 1-success_rate above
rloss = resubLoss(mdl)

%% Classification Model (use 'Classification Learner' app)
% Classification Model can be generated using 'Classification Learner'
% Evaluate confusion matrix using Classificaton Learner

% Classification Model Using script

% Accuracy using resubloss


%% Prepare trained classification model for Coder/Conversion 
% use above code to train model named 'mdl'
% saveLearnerForCoder(mdl,'RF_model');

% Classification Learning APP and export compact model, then call below
% Refer to MATLAB doc: Code Generation and Classification Learner App
saveLearnerForCoder(trainedModel.ClassificationEnsemble,'RF_model');

%% LEGACY/DEBUG ONLY - Evaluate Classification Model - Cross Validation
% X = X_stack;
% Y = num2cell(Y_stack);
% cp = classperf(Y)
% for i = 1:10
%     [train,test] = crossvalind('LeaveMOut',Y,5);
%     mdl = fitcknn(X(train,:),Y(train),'NumNeighbors',3);
%     predictions = predict(mdl,X(test,:));
%     classperf(cp,predictions,test);
% end

%% %%%%%%%%%%%%%%%%%%%%Neural Network%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %% Neural Network Train & Test
% % reorganize training data/label
% X_array = table2array(X_stack);
% Y_array = Y_stack;
% Y_array_flag = [];
% for i = 1: length(Y_array)
%     if Y_array(i) == 0
%         Y_array_flag = [Y_array_flag; [1 0 0 0]];
%     elseif Y_array(i) == 1
%         Y_array_flag = [Y_array_flag; [0 1 0 0]];
%     elseif Y_array(i) == 2
%         Y_array_flag = [Y_array_flag; [0 0 1 0]];
%     elseif Y_array(i) == 3
%         Y_array_flag = [Y_array_flag; [0 0 0 1]];
%     end
% end
% 
% % design/train network
% net = fitnet(10,'traingdx');
% net.adaptParam.lr=0.3; % learning rate
% net.trainParam.mc = 0.2; % momentum
% [net,tr] = train(net, X_array', Y_array_flag');
% 
% % test network
% y = net(X_array'); % net is not a function, its just the 'net' we trained above
% perf = perform(net,y,Y_array_flag');
% 
% % Saving the network weights and biases
% net.IW;
% net.LW;
% net.b;
% 
% % save network for coder
% % genFunction(net, 'NN_model', 'MatrixOnly','yes');
% 
% %% Get final prediction of NN as 0, 1, 2, 3, rather than [1, 0, 0, 0], [0, 1, 0, 0], ...
% % get result (4*14497-->1*14497)
% Y_predict = [];
% for i = 1: length(y)
%     column_buff = y(:, i);
%     max_idx = find(column_buff == max(column_buff(:)))-1;
%     Y_predict = [max_idx; Y_predict];
% end
% 
% %% Confusion Matrix
% figure; plotconfusion(Y_array_flag', y);
% 
% correct_mark = zeros(length(Y_stack), 1);
% for i = 1:length(Y_stack)
% 
%     if Y_predict(i) == Y_stack(i)
%         correct_mark(i) = 1;
%     else
%         correct_mark(i) = 0;
%     end
% 
% end
% success_rate = sum(correct_mark) / length(Y_stack)