function [X] = SpO2HRToMatrix(location, debug_fig)
%% Dataset preview

% 'nonEEGdataset/Subject1_SpO2HR'

% return specifications for signals in WFDB records
[siginfo, Fs, sigClass] = wfdbdesc(location);

% Read in signal, sample frequency and sampling intervals
[sig_5, Fs, tm] = rdsamp(location);

if debug_fig
    % Plot 2D version of signal and labels
    figure
    for i = 1:2
        signal = sig_5(:, i);
        subplot(5, 1, i); plot(tm, signal); ylabel(siginfo(i).Description); xlabel('time/sec');
        hold on; grid on;
    end
end

%% windowing and Returning Metrics
% Fs=1 in this case
% Set parameters to: 6 second window, 50% overlap (window shift = 3)
% seconds), using ideal rectanfular window

L = 6; % actual window size in sample
n = 0:(L - 1); % window range
R = 3; % window shift
window1 = 1; %Rectangular window
window2 = 0; %Hamming window

% sig_5(:, 1) --> accelaration on x
[tm_frame, frame_mean, frame_max, frame_min, frame_change] = td_analysis(sig_5(:, 1), tm, Fs, L, R, window1, debug_fig);

% td_analysis(s, Fs, L, R, window2);

%% Return
X = table(frame_mean, frame_max, frame_min, frame_change);
end