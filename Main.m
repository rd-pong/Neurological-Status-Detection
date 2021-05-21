%%%%%%%
% This is the main script for debugging
%%%%%%%

%% %%%%%%%%%%%%%%%%%%%%Read in and pre-process%%%%%%%%%%%%%%%%%%%%%%%
%% Preliminaries
% Add toolbox folder to path
clear; clc; close all;
addpath 'wfdb-app-toolbox-0-10-0\mcode'

%% Read in and construct data to stack using for-loop
X_stack = [];
Y_stack = [];

for i = 1:20 % for each subject
    [X_AccTempEDA, Y] = AccTempEDAToMatrix(char('nonEEGdataset/Subject' + string(i) + '_AccTempEDA'), 0);
    [X_SpO2HR] = SpO2HRToMatrix(char('nonEEGdataset/Subject' + string(i) + '_SpO2HR'), 0);
    X_stack = [
            X_AccTempEDA X_SpO2HR(1:height(X_AccTempEDA), :); 
            X_stack];
    Y_stack = [Y; Y_stack];
end
XY = [X_stack array2table(Y_stack)];

%% LEGACY/DEBUG ONLY --- Read in and construct data to stack
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

%% Alternatively, load pre-processed data from storage (.mat)
clear; clc; close all;
% load('Matrix Storage.mat');
load('Matrix Storage XY.mat');
addpath 'Models'

%% %%%%%%%%%%%%%%%%%%%%Classification%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Train & Test
addpath 'Models'
[trainedClassifier_knn, validationAccuracy_knn] = trainClassifier_knn(XY);
[trainedClassifier_rf, validationAccuracy_rf] = trainClassifier_rf(XY);
[trainedClassifier_svm, validationAccuracy_svm] = trainClassifier_svm(XY);
[net, validationAccuracy_nn] = trainClassifier_nn(XY);

%% Prepare trained classification model for Coder/Conversion 
% saveLearnerForCoder(trainedModel,'RF_model'); % Full model
% To save a compact model
saveLearnerForCoder(trainedClassifier_knn.ClassificationKNN,'model_knn');
saveLearnerForCoder(trainedClassifier_rf.ClassificationEnsemble,'model_rf');
saveLearnerForCoder(trainedClassifier_svm.ClassificationSVM,'model_svm');
genFunction(net, 'model_nn', 'MatrixOnly','yes'); % save network for coder

%% %%%%%%%%%%%%%%%%%%%%Predict%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% See 'Code Convert' Folder