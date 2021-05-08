% Neural Network Train & Test
% https://www.mathworks.com/help/deeplearning/ug/crab-classification.html

%% Preparing the Data
clear; clc; close all;
load('Matrix Storage XY.mat')

% input matrix X
X_array = table2array(X_stack);
X = X_array';

% target matrix T
Y_array = Y_stack;
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

fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));
fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);

%% Saving
% Saving the network weights and biases
net.IW;
net.LW;
net.b;

% save network for coder
% genFunction(net, 'NN_model', 'MatrixOnly','yes');
