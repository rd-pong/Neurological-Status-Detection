function [X, Y] = AccTempEDAToMatrix(location, debug_fig)
    %% Dataset preview

    % return specifications for signals in WFDB records
    [siginfo, Fs, sigClass] = wfdbdesc(location);

    % Read in signal, sample frequency and sampling intervals
    [sig_5, Fs, tm] = rdsamp(location);

    % Reads a WFDB annotation (ann-->time stamp location, comments-->status description)
    [ann, ~, ~, ~, ~, comments] = rdann(location, 'atr');

    if debug_fig
        % Plot 2D version of signal and labels
        figure

        for i = 1:5
            signal = sig_5(:, i);
            subplot(5, 1, i); plot(tm, signal); ylabel(siginfo(i).Description); xlabel('time/sec');
            hold on; grid on;
            plot(tm(ann), signal(ann, 1), 'ro', 'MarkerSize', 4)

            % add separation line between different status
            for i = 1:length(ann)
                xline(tm(ann(i)), '--r');
            end

        end

        for i = 1:length(ann)
            txt = string(comments(i));
            text(tm(ann(i)), signal(ann(i)), txt);
        end

    end

    %% windowing and Returning Metrics

    % Set parameters to: 6 second window, 50% overlap (window shift = 3)
    % seconds), using ideal rectanfular window

    L = 48; % actual window size in sample
    n = 0:(L - 1); % window range
    R = 24; % window shift
    window1 = 1; %Rectangular window
    window2 = 0; %Hamming window

    % sig_5(:, 1) --> accelaration on x
    [tm_frame, frame_mean_acx, frame_max_acx, frame_min_acx, frame_change_acx] = td_analysis(sig_5(:, 1), tm, Fs, L, R, window1, debug_fig);
    [~, frame_mean_acy, frame_max_acy, frame_min_acy, frame_change_acy] = td_analysis(sig_5(:, 2), tm, Fs, L, R, window1, debug_fig);
    [~, frame_mean_acz, frame_max_acz, frame_min_acz, frame_change_acz] = td_analysis(sig_5(:, 3), tm, Fs, L, R, window1, debug_fig);
    [~, frame_mean_temp, frame_max_temp, frame_min_temp, frame_change_temp] = td_analysis(sig_5(:, 4), tm, Fs, L, R, window1, debug_fig);
    [~, frame_mean_EDA, frame_max_EDA, frame_min_EDA, frame_change_EDA] = td_analysis(sig_5(:, 5), tm, Fs, L, R, window1, debug_fig);
    % td_analysis(s, Fs, L, R, window2);

    %% get status mark
    % Convert 'ann' by sample to ann by time.
    % 1. divide by 8 (sample rate) --> seconds
    % 2. divide by 3 (tm_frame inverval) --> tm_frame index
    % 3. round to nearest 3 to match with tm_frame index
    ann_tm = round(ann / 8/3);

    status_mark = zeros(length(tm_frame), 1); % 0 relax
    status_mark(ann_tm(2):ann_tm(3) - 1) = 1; % 1 physical stress
    status_mark(ann_tm(4):ann_tm(5) - 1) = 2; % 2 emotional stress
    status_mark(ann_tm(5):ann_tm(6) - 1) = 3; % 3 cognitive stress
    status_mark(ann_tm(7):ann_tm(8) - 1) = 2; % 2 emotional stress

    if debug_fig
        figure;
        plot(tm_frame, status_mark); hold on;
        plot(tm_frame, frame_mean)
    end

    %% Return
    table_name = {...
            'acx_mean', 'acx_max', 'acx_min', 'acx_change', ...
            'acy_mean', 'acy_max', 'acy_min', 'acy_change', ...
            'acz_mean', 'acz_max', 'acz_min', 'acz_change', ...
            'temp_mean', 'temp_max', 'temp_min', 'temp_change', ...
            'EDA_mean', 'EDA_max', 'EDA_min', 'EDA_change'};
        
    X = table(frame_mean_acx, frame_max_acx, frame_min_acx, frame_change_acx, ...
            frame_mean_acy, frame_max_acy, frame_min_acy, frame_change_acy, ...
            frame_mean_acz, frame_max_acz, frame_min_acz, frame_change_acz, ...
            frame_mean_temp, frame_max_temp, frame_min_temp, frame_change_temp, ...
            frame_mean_EDA, frame_max_EDA, frame_min_EDA, frame_change_EDA, ...
            'VariableNames', table_name);

    Y = status_mark;
    end
