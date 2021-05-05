%% Neural Network Train & Test
% reorganize training data/label
X_array = table2array(X_stack);
Y_array = Y_stack;
Y_array_flag = [];
for i = 1: length(Y_array)
    if Y_array(i) == 0
        Y_array_flag = [Y_array_flag; [1 0 0 0]];
    elseif Y_array(i) == 1
        Y_array_flag = [Y_array_flag; [0 1 0 0]];
    elseif Y_array(i) == 2
        Y_array_flag = [Y_array_flag; [0 0 1 0]];
    elseif Y_array(i) == 3
        Y_array_flag = [Y_array_flag; [0 0 0 1]];
    end
end

% design/train network
net = fitnet(10,'traingdx');
net.adaptParam.lr=0.3; % learning rate
net.trainParam.mc = 0.2; % momentum
[net,tr] = train(net, X_array', Y_array_flag');

% test network
y = net(X_array'); % net is not a function, its just the 'net' we trained above
perf = perform(net,y,Y_array_flag');

% Saving the network weights and biases
net.IW;
net.LW;
net.b;

% save network for coder
% genFunction(net, 'NN_model', 'MatrixOnly','yes');

%% Get final prediction of NN as 0, 1, 2, 3, rather than [1, 0, 0, 0], [0, 1, 0, 0], ...
% get result (4*14497-->1*14497)
Y_predict = [];
for i = 1: length(y)
    column_buff = y(:, i);
    max_idx = find(column_buff == max(column_buff(:)))-1;
    Y_predict = [max_idx; Y_predict];
end

%% Confusion Matrix
figure; plotconfusion(Y_array_flag', y);

correct_mark = zeros(length(Y_stack), 1);
for i = 1:length(Y_stack)

    if Y_predict(i) == Y_stack(i)
        correct_mark(i) = 1;
    else
        correct_mark(i) = 0;
    end

end
success_rate = sum(correct_mark) / length(Y_stack)