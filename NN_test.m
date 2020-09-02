%% Neural Network Train & Test
load('Matrix Storage XY.mat')
load('feature_data.mat')
% reorganize training data/label
X_array = table2array(X_stack);
Y_array = Y_stack;
Y_array_flag = [];
for i = 1: length(Y_array)
    if Y_array(i) == 0
        Y_array_flag = [[1 0 0 0]; Y_array_flag];
    elseif Y_array(i) == 1
        Y_array_flag = [[0 1 0 0]; Y_array_flag];
    elseif Y_array(i) == 2
        Y_array_flag = [[0 0 1 0]; Y_array_flag];
    elseif Y_array(i) == 3
        Y_array_flag = [[0 0 0 1]; Y_array_flag];
    end
end

% design/train network
net = feedforwardnet(4);
[net,tr] = train(net, X_array', Y_array_flag');

% test network
sim(net,output0') % work
classify(net,output0') % not work
predict(net,output0') % not work

% how to validate/test?