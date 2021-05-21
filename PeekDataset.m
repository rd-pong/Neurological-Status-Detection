%%%%%%%%%%%%
% Use this file to peek how signals look like in the dataset
%%%%%%%%%%%%%

%% Preliminaries
% Add toolbox folder to path
addpath 'wfdb-app-toolbox-0-10-0\mcode'
clear; clc; close all;

%% set parameters
location1 = 'nonEEGdataset/Subject1_AccTempEDA';
location2 = 'nonEEGdataset/Subject1_SpO2HR';

%% Read in _AccTempEDA
% return specifications for signals in WFDB records
[siginfo1, Fs1, sigClass1] = wfdbdesc(location1);

% Read in signal, sample frequency and sampling intervals
[sig_1, Fs1, tm1] = rdsamp(location1);

% Reads a WFDB annotation (ann-->time stamp location, comments-->status description)
[ann1, ~, ~, ~, ~, comments1] = rdann(location1, 'atr');

%% Read in SpO2HR
% 'nonEEGdataset/Subject1_SpO2HR'

% return specifications for signals in WFDB records
[siginfo2, Fs2, sigClass2] = wfdbdesc(location2);

% Read in signal, sample frequency and sampling intervals
[sig2, Fs2, tm2] = rdsamp(location2);

%% Plot together
figure

% _AccTempEDA
for i = 1:5
    signal1 = sig_1(:, i);
    subplot(7, 1, i); plot(tm1, signal1); ylabel(siginfo1(i).Description);
    hold on; grid on;
    plot(tm1(ann1), signal1(ann1, 1), 'ro', 'MarkerSize', 4)

    % add separation line between different status
    for i = 1:length(ann1)
        xline(tm1(ann1(i)), '--r');
    end

end

for i = 1:length(ann1)
    txt = string(comments1(i));
    text(tm1(ann1(i)), signal1(ann1(i)), txt);
end

% SpO2HR
for i = 1:2
    signal = sig2(:, i);
    subplot(7, 1, i+5); plot(tm2, signal); ylabel(siginfo2(i).Description); xlabel('time/sec');
    hold on; grid on;
end