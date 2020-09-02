%% Preliminaries
% WFDB App Toolbox Demo
% wfdbdemo

% Add toolbox folder to path
addpath 'wfdb-app-toolbox-0-10-0\mcode'
clear; clc; close all;

% % Read in signal, Fs and sampling intervals, construct into 'struct'
% sig_struct = ([]);
% for i = 1:5
%     a = 'nonEEGdataset/Subject' + string(i) + '_AccTempEDA';
%     [sig_5, Fs, tm] = rdsamp(char('nonEEGdataset/Subject' + string(i) + '_AccTempEDA'));
%     sig_struct.('sub'+string(i)) = sig_5;
% end

%% Read in and stack using for-loop
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
% [X3_AccTempEDA, Y3] = AccTempEDAToMatrix('nonEEGdataset/Subject3_AccTempEDA', 0);
% [X4_AccTempEDA, Y4] = AccTempEDAToMatrix('nonEEGdataset/Subject4_AccTempEDA', 0);
% [X5_AccTempEDA, Y5] = AccTempEDAToMatrix('nonEEGdataset/Subject5_AccTempEDA', 0);
% [X6_AccTempEDA, Y6] = AccTempEDAToMatrix('nonEEGdataset/Subject6_AccTempEDA', 0);
% [X7_AccTempEDA, Y7] = AccTempEDAToMatrix('nonEEGdataset/Subject7_AccTempEDA', 0);
% [X8_AccTempEDA, Y8] = AccTempEDAToMatrix('nonEEGdataset/Subject8_AccTempEDA', 0);
% [X9_AccTempEDA, Y9] = AccTempEDAToMatrix('nonEEGdataset/Subject9_AccTempEDA', 0);
% [X10_AccTempEDA, Y10] = AccTempEDAToMatrix('nonEEGdataset/Subject10_AccTempEDA', 0);
% [X11_AccTempEDA, Y11] = AccTempEDAToMatrix('nonEEGdataset/Subject11_AccTempEDA', 0);
% [X12_AccTempEDA, Y12] = AccTempEDAToMatrix('nonEEGdataset/Subject12_AccTempEDA', 0);
% [X13_AccTempEDA, Y13] = AccTempEDAToMatrix('nonEEGdataset/Subject13_AccTempEDA', 0);
% [X14_AccTempEDA, Y14] = AccTempEDAToMatrix('nonEEGdataset/Subject14_AccTempEDA', 0);
% [X15_AccTempEDA, Y15] = AccTempEDAToMatrix('nonEEGdataset/Subject15_AccTempEDA', 0);
% [X16_AccTempEDA, Y16] = AccTempEDAToMatrix('nonEEGdataset/Subject16_AccTempEDA', 0);
% [X17_AccTempEDA, Y17] = AccTempEDAToMatrix('nonEEGdataset/Subject17_AccTempEDA', 0);
% [X18_AccTempEDA, Y18] = AccTempEDAToMatrix('nonEEGdataset/Subject18_AccTempEDA', 0);
% [X19_AccTempEDA, Y19] = AccTempEDAToMatrix('nonEEGdataset/Subject19_AccTempEDA', 0);
% [X20_AccTempEDA, Y20] = AccTempEDAToMatrix('nonEEGdataset/Subject20_AccTempEDA', 0);
% 
% [X1_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject1_SpO2HR', 0);
% [X2_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject2_SpO2HR', 0);
% [X3_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject3_SpO2HR', 0);
% [X4_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject4_SpO2HR', 0);
% [X5_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject5_SpO2HR', 0);
% [X6_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject6_SpO2HR', 0);
% [X7_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject7_SpO2HR', 0);
% [X8_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject8_SpO2HR', 0);
% [X9_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject9_SpO2HR', 0);
% [X10_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject10_SpO2HR', 0);
% [X11_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject11_SpO2HR', 0);
% [X12_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject12_SpO2HR', 0);
% [X13_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject13_SpO2HR', 0);
% [X14_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject14_SpO2HR', 0);
% [X15_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject15_SpO2HR', 0);
% [X16_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject16_SpO2HR', 0);
% [X17_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject17_SpO2HR', 0);
% [X18_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject18_SpO2HR', 0);
% [X19_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject19_SpO2HR', 0);
% [X20_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject20_SpO2HR', 0);
% 
% % Split data
% X_stack = [
%         X1_AccTempEDA X1_SpO2HR(1:height(X1_AccTempEDA), :);
%         X2_AccTempEDA X2_SpO2HR(1:height(X2_AccTempEDA), :);
%         X3_AccTempEDA X3_SpO2HR(1:height(X3_AccTempEDA), :);
%         X4_AccTempEDA X4_SpO2HR(1:height(X4_AccTempEDA), :);
%         X5_AccTempEDA X5_SpO2HR(1:height(X5_AccTempEDA), :);
%         X6_AccTempEDA X6_SpO2HR(1:height(X6_AccTempEDA), :);
%         X7_AccTempEDA X7_SpO2HR(1:height(X7_AccTempEDA), :);
%         X8_AccTempEDA X8_SpO2HR(1:height(X8_AccTempEDA), :);
%         X9_AccTempEDA X9_SpO2HR(1:height(X9_AccTempEDA), :);
%         X10_AccTempEDA X10_SpO2HR(1:height(X10_AccTempEDA), :);
%         X11_AccTempEDA X11_SpO2HR(1:height(X11_AccTempEDA), :);
%         X12_AccTempEDA X12_SpO2HR(1:height(X12_AccTempEDA), :);
%         X13_AccTempEDA X13_SpO2HR(1:height(X13_AccTempEDA), :);
%         X14_AccTempEDA X14_SpO2HR(1:height(X14_AccTempEDA), :);
%         X15_AccTempEDA X15_SpO2HR(1:height(X15_AccTempEDA), :);
%         X16_AccTempEDA X16_SpO2HR(1:height(X16_AccTempEDA), :);
%         X17_AccTempEDA X17_SpO2HR(1:height(X17_AccTempEDA), :);
%         X18_AccTempEDA X18_SpO2HR(1:height(X18_AccTempEDA), :);
%         X19_AccTempEDA X19_SpO2HR(1:height(X19_AccTempEDA), :)];
% Y_stack = [Y1; Y2; Y3; Y4; Y5; Y6; Y7; Y8; Y9; Y10; Y11; Y12; Y13; Y14; Y15; Y16; Y17; Y18; Y19];
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
net.IW	
net.LW	
net.b

% save network for coder
genFunction(net, 'NN_model', 'MatrixOnly','yes');

%% Get final prediction as 0, 1, 2, 3, rather than [1, 0, 0, 0], [0, 1, 0, 0], ...
% get result (4*14497-->1*14497)
y_distance_to_1 = abs(y - ones(size(y)));
y_predict = [];
for i = 1: length(y)
    column_buff = y_distance_to_1(:, 1)
    min_idx = find(column_buff == min(column_buff(:))) - 1;
    y_predict = [min_idx y_predict];
end

