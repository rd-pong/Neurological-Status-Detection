clear; clc; close all;

%test0 = load('feature_data.mat').output0;
test1 = load('feature_data.mat').output1;
[label, score] = RF_full(test1)