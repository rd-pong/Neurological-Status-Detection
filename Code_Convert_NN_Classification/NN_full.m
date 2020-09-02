function [Y] = NN_full(input_data)
    NN = load('NN_model.mat').net;
    % [label,score] = predict(NN, input_data);
    Y = sim(NN, input_data')
end
