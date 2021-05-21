function [net, c] = trainClassifier_nn(trainingData)
% [net, validationAccuracy] = trainClassifier(trainingData)
% returns a trained classifier and its accuracy.
%
%  Input:
%      trainingData: a table containing the same predictor and response
%       columns as imported into the app.
%
%  Output:
%      net: a struct containing the trained classifier. The
%       struct contains various fields with information about the trained
%       classifier.
%
%      c: a double containing the accuracy in percent. In
%       the app, the History list displays this overall accuracy score for
%       each model.
%

%%%%%%%%%%
% Neural Network Train & Test
% https://www.mathworks.com/help/deeplearning/ug/crab-classification.html
%%%%%%%%%%
%% Preliminaries

% uncomment following to manually Set X Y here
% clear; clc; close all;
% load('Matrix Storage XY.mat')
% X = X_stack; % or X = X_stack_max;
% Y = Y_stack;

predictorNames = {'acx_max', 'acy_max', 'acz_max', 'temp_max', 'EDA_max', 'SPO2_max', 'HR_max'};
X = trainingData(:, predictorNames);
Y = trainingData.Y_stack;
%% Prepare the Data

% input matrix X
X_array = table2array(X);
X = X_array';

% target matrix T
Y_array = Y;
Y_array_flag = [];
for i = 1: length(Y_array)
    if Y_array(i) == 0
        Y_array_flag = [Y_array_flag; [1 0 0 0]];
    elseif Y_array(i) == 1
        Y_array_flag = [Y_array_flag; [0 1 0 0]];
    elseif Y_array(i) == 2
        Y_array_flag = [Y_array_flag; [0 0 1 0]];
    elseif Y_array(i) == 3
        Y_array_flag = [Y_array_flag; [0 0 0 1]];
    end
end
T = Y_array_flag';

%% build and train network
net = patternnet(10, 'trainbr');
net = configure(net,X,T);

net.divideParam.trainRatio=0.95;
% net.divideParam.valRatio=0.05;
net.divideParam.testRatio=0.05;

% train NN
[net,tr] = train(net, X, T);

%% test network
testX = X(:,tr.testInd);
testT = T(:,tr.testInd);

testY = net(testX);
testIndices = vec2ind(testY);

% plot confusion matrix
plotconfusion(testT,testY)

% print accuracy
[c,cm] = confusion(testT,testY);

c = 1-c; % correctness 
fprintf('Percentage Correct Classification   : %f%%\n', 100*c);
fprintf('Percentage Incorrect Classification : %f%%\n', 100*(1-c));

%% Saving
% Saving the network weights and biases
net.IW;
net.LW;
net.b;

% save network for coder
% genFunction(net, 'NN_model', 'MatrixOnly','yes');
