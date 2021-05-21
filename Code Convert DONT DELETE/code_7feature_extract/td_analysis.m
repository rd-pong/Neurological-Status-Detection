function [frame_max] = td_analysis(s, L, R)
%
% return mean min max change along with frame indexing given tm/sampling intervals
%
% L     window size
% n     window range
% R     window shift
% window1 = 1; --> Rectangular window
% window2 = 0; --> Hamming window
% debug_fig set below to 1, if want to show debug figures 

% Window setup
n=0:(L-1); % window range temp
w=0*(n<0)+1*(n>=0&n<=(L-1))+0*(n>(L-1)); %Rectangular window

% calculate the total number of frames (dividing sig_length by frame_length)
signal_length=length(s); 
frame_number=floor((signal_length-L)/R)+1; 

% Initialization
% frame_mean = [zeros(frame_number, 1)];
frame_max = [zeros(frame_number, 1)];
% frame_change = [zeros(frame_number, 1)];
% frame_min = [zeros(frame_number, 1)];

for i=1:frame_number
    frame_index=(i-1)*R+(1:L);
    framesignal1=s(frame_index).*w';

%     frame_mean(i) = mean(framesignal1); % mean
    frame_max(i) = max(framesignal1); % max
%     frame_min(i) = min(framesignal1); % min
%     frame_change(i) = framesignal1(1) - framesignal1(end); % change
end

end
