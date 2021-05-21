clear; clc; close all;
%test0 = load('feature_data.mat').output0;
test1 = load('feature_data.mat').output1;

%%
% To avoid "The value of X must not be an object" in MATLAB Coder, change
% the type of input feature array from TABLE to ARRAY
% output1 = table2array(output1); output2 = table2array(output2);

[label, score] = SVM_full(test1);

