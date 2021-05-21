function [label, score] = kNN(input_data)
    kNN = loadLearnerForCoder("kNN_model.mat");
    [label,score] = predict(kNN, input_data);
end
