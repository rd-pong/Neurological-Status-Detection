clear; clc; close all;
% test = load('feature_data.mat').output0;
test = load('feature_data.mat').output1;

%%
Y = NN_full(test);