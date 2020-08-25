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

%% Read in
[X1, Y1] = databaseToMatrix('nonEEGdataset/Subject1_AccTempEDA', 0);
[X2, Y2] = databaseToMatrix('nonEEGdataset/Subject2_AccTempEDA', 0);
[X3, Y3] = databaseToMatrix('nonEEGdataset/Subject3_AccTempEDA', 0);
[X4, Y4] = databaseToMatrix('nonEEGdataset/Subject4_AccTempEDA', 0);
[X5, Y5] = databaseToMatrix('nonEEGdataset/Subject5_AccTempEDA', 0);
[X6, Y6] = databaseToMatrix('nonEEGdataset/Subject6_AccTempEDA', 0);
[X7, Y7] = databaseToMatrix('nonEEGdataset/Subject7_AccTempEDA', 0);
[X8, Y8] = databaseToMatrix('nonEEGdataset/Subject8_AccTempEDA', 0);
[X9, Y9] = databaseToMatrix('nonEEGdataset/Subject9_AccTempEDA', 0);
[X10, Y10] = databaseToMatrix('nonEEGdataset/Subject10_AccTempEDA', 0);
[X11, Y11] = databaseToMatrix('nonEEGdataset/Subject11_AccTempEDA', 0);
[X12, Y12] = databaseToMatrix('nonEEGdataset/Subject12_AccTempEDA', 0);
[X13, Y13] = databaseToMatrix('nonEEGdataset/Subject13_AccTempEDA', 0);
[X14, Y14] = databaseToMatrix('nonEEGdataset/Subject14_AccTempEDA', 0);
[X15, Y15] = databaseToMatrix('nonEEGdataset/Subject15_AccTempEDA', 0);
[X16, Y16] = databaseToMatrix('nonEEGdataset/Subject16_AccTempEDA', 0);
[X17, Y17] = databaseToMatrix('nonEEGdataset/Subject17_AccTempEDA', 0);
[X18, Y18] = databaseToMatrix('nonEEGdataset/Subject18_AccTempEDA', 0);
[X19, Y19] = databaseToMatrix('nonEEGdataset/Subject19_AccTempEDA', 0);

%% Train & Test
X_stack = [X1;X2;X3;X4;X5;X6;X7;X8;X9;X10;X11;X12;X13;X14;X15;X16;X17;X18;X19];
Y_stack = [Y1;Y2;Y3;Y4;Y5;Y6;Y7;Y8;Y9;Y10;Y11;Y12;Y13;Y14;Y15;Y16;Y17;Y18;Y19];

mdl = fitcknn(X_stack, Y_stack, 'NumNeighbors',4,'Standardize',1);
label = predict(mdl,X11);

correct_mark = zeros(length(label), 1);
for i = 1:length(label)
    if label(i) == Y11(i)
        correct_mark(i) = 1;
    else
        correct_mark(i) = 0;
    end
end

success_rate = sum(correct_mark)/length(label)
% [label,score,cost] = predict(mdl, X2)