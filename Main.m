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

%% Read in AccTempEDA
[X1_AccTempEDA, Y1] = AccTempEDAToMatrix('nonEEGdataset/Subject1_AccTempEDA', 0);
[X2_AccTempEDA, Y2] = AccTempEDAToMatrix('nonEEGdataset/Subject2_AccTempEDA', 0);
[X3_AccTempEDA, Y3] = AccTempEDAToMatrix('nonEEGdataset/Subject3_AccTempEDA', 0);
[X4_AccTempEDA, Y4] = AccTempEDAToMatrix('nonEEGdataset/Subject4_AccTempEDA', 0);
[X5_AccTempEDA, Y5] = AccTempEDAToMatrix('nonEEGdataset/Subject5_AccTempEDA', 0);
[X6_AccTempEDA, Y6] = AccTempEDAToMatrix('nonEEGdataset/Subject6_AccTempEDA', 0);
[X7_AccTempEDA, Y7] = AccTempEDAToMatrix('nonEEGdataset/Subject7_AccTempEDA', 0);
[X8_AccTempEDA, Y8] = AccTempEDAToMatrix('nonEEGdataset/Subject8_AccTempEDA', 0);
[X9_AccTempEDA, Y9] = AccTempEDAToMatrix('nonEEGdataset/Subject9_AccTempEDA', 0);
[X10_AccTempEDA, Y10] = AccTempEDAToMatrix('nonEEGdataset/Subject10_AccTempEDA', 0);
[X11_AccTempEDA, Y11] = AccTempEDAToMatrix('nonEEGdataset/Subject11_AccTempEDA', 0);
[X12_AccTempEDA, Y12] = AccTempEDAToMatrix('nonEEGdataset/Subject12_AccTempEDA', 0);
[X13_AccTempEDA, Y13] = AccTempEDAToMatrix('nonEEGdataset/Subject13_AccTempEDA', 0);
[X14_AccTempEDA, Y14] = AccTempEDAToMatrix('nonEEGdataset/Subject14_AccTempEDA', 0);
[X15_AccTempEDA, Y15] = AccTempEDAToMatrix('nonEEGdataset/Subject15_AccTempEDA', 0);
[X16_AccTempEDA, Y16] = AccTempEDAToMatrix('nonEEGdataset/Subject16_AccTempEDA', 0);
[X17_AccTempEDA, Y17] = AccTempEDAToMatrix('nonEEGdataset/Subject17_AccTempEDA', 0);
[X18_AccTempEDA, Y18] = AccTempEDAToMatrix('nonEEGdataset/Subject18_AccTempEDA', 0);
[X19_AccTempEDA, Y19] = AccTempEDAToMatrix('nonEEGdataset/Subject19_AccTempEDA', 0);
[X20_AccTempEDA, Y20] = AccTempEDAToMatrix('nonEEGdataset/Subject20_AccTempEDA', 0);

%% Read in SpO2HR
[X1_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject1_SpO2HR', 0);
[X2_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject2_SpO2HR', 0);
[X3_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject3_SpO2HR', 0);
[X4_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject4_SpO2HR', 0);
[X5_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject5_SpO2HR', 0);
[X6_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject6_SpO2HR', 0);
[X7_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject7_SpO2HR', 0);
[X8_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject8_SpO2HR', 0);
[X9_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject9_SpO2HR', 0);
[X10_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject10_SpO2HR', 0);
[X11_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject11_SpO2HR', 0);
[X12_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject12_SpO2HR', 0);
[X13_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject13_SpO2HR', 0);
[X14_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject14_SpO2HR', 0);
[X15_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject15_SpO2HR', 0);
[X16_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject16_SpO2HR', 0);
[X17_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject17_SpO2HR', 0);
[X18_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject18_SpO2HR', 0);
[X19_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject19_SpO2HR', 0);
[X20_SpO2HR] = SpO2HRToMatrix('nonEEGdataset/Subject20_SpO2HR', 0);

%% Train & Test
X_stack = [
        X1_AccTempEDA X1_SpO2HR(1:height(X1_AccTempEDA), :);
        X2_AccTempEDA X2_SpO2HR(1:height(X2_AccTempEDA), :);
        X3_AccTempEDA X3_SpO2HR(1:height(X3_AccTempEDA), :);
        X4_AccTempEDA X4_SpO2HR(1:height(X4_AccTempEDA), :);
        X5_AccTempEDA X5_SpO2HR(1:height(X5_AccTempEDA), :);
        X6_AccTempEDA X6_SpO2HR(1:height(X6_AccTempEDA), :);
        X7_AccTempEDA X7_SpO2HR(1:height(X7_AccTempEDA), :);
        X8_AccTempEDA X8_SpO2HR(1:height(X8_AccTempEDA), :);
        X9_AccTempEDA X9_SpO2HR(1:height(X9_AccTempEDA), :);
        X10_AccTempEDA X10_SpO2HR(1:height(X10_AccTempEDA), :);
        X11_AccTempEDA X11_SpO2HR(1:height(X11_AccTempEDA), :);
        X12_AccTempEDA X12_SpO2HR(1:height(X12_AccTempEDA), :);
        X13_AccTempEDA X13_SpO2HR(1:height(X13_AccTempEDA), :);
        X14_AccTempEDA X14_SpO2HR(1:height(X14_AccTempEDA), :);
        X15_AccTempEDA X15_SpO2HR(1:height(X15_AccTempEDA), :);
        X16_AccTempEDA X16_SpO2HR(1:height(X16_AccTempEDA), :);
        X17_AccTempEDA X17_SpO2HR(1:height(X17_AccTempEDA), :);
        X18_AccTempEDA X18_SpO2HR(1:height(X18_AccTempEDA), :);
        X19_AccTempEDA X19_SpO2HR(1:height(X19_AccTempEDA), :)];
Y_stack = [Y1; Y2; Y3; Y4; Y5; Y6; Y7; Y8; Y9; Y10; Y11; Y12; Y13; Y14; Y15; Y16; Y17; Y18; Y19];

mdl = fitcknn(X_stack, Y_stack, 'NumNeighbors', 3, 'Standardize', 1);
label = predict(mdl, [X20_AccTempEDA X20_SpO2HR(1:height(X20_AccTempEDA), :)]);

correct_mark = zeros(length(label), 1);

for i = 1:length(label)

    if label(i) == Y20(i)
        correct_mark(i) = 1;
    else
        correct_mark(i) = 0;
    end

end

success_rate = sum(correct_mark) / length(label)
XY = [X_stack array2table(Y_stack)];
% [label,score,cost] = predict(mdl, X2)
