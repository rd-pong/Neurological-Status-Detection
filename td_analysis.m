function [tm_frame, frame_mean, frame_max, frame_min, frame_change] = td_analysis(s, tm, Fs, L, R, window_type, debug_fig)
%
% return mean min max change along with frame indexing given tm/sampling intervals
%
% L     window size
% n     window range
% R     window shift
% window1 = 1; --> Rectangular window
% window2 = 0; --> Hamming window
% debug_fig set below to 1, if want to show debug figures 


%%

% Window setup
n=0:(L-1); % window range temp
if window_type == 0
    w=0*(n<0)+1*(n>=0&n<=(L-1))+0*(n>(L-1)); %Rectangular window
else 
	w=0.54*(n>=0&n<=(L-1))-0.46*cos(2*pi*n/(L-1)).*(n>=0&n<=(L-1)); %Hamming window
end

% calculate the total number of frames (dividing sig_length by frame_length)
signal_length=length(s); 
frame_number=floor((signal_length-L)/R)+1; 

% Initialization
frame_mean = [zeros(frame_number, 1)];
frame_max = [zeros(frame_number, 1)];
frame_change = [zeros(frame_number, 1)];
frame_min = [zeros(frame_number, 1)];
tm_frame = [zeros(frame_number, 1)];

for i=1:frame_number
    frame_index=(i-1)*R+(1:L);
    framesignal1=s(frame_index).*w';
    
    % frame start time stamp using 'tm'£¬ time stamp by frame
    tm_frame(i) = tm(frame_index(1));
    
    % mean
    frame_mean(i) = mean(framesignal1);
    % max
    frame_max(i) = max(framesignal1);
    % min
    frame_min(i) = min(framesignal1);
    % change
    frame_change(i) = framesignal1(1) - framesignal1(end);
    
end

%% Debug Plots

if debug_fig
    figure
    subplot(411)
    plot(0:(1/Fs):((signal_length-1)/Fs),s)
    ylabel('Waveform')

    subplot(412)
    plot((1:frame_number)*R/Fs,frame_mean)
    ylabel({'frame mean'})

    subplot(413)
    plot((1:frame_number)*R/Fs,frame_max); hold on;
    plot((1:frame_number)*R/Fs,frame_min)
    ylabel({'framevmax & frame mean'})

    subplot(414)
    % plot((1:frame_number)*R/Fs,frame_change)
    plot(tm_frame(1:frame_number),frame_change)
    xlabel('time(s)')
    ylabel({'frame change'})
    
end

end
