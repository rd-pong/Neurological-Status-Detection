function [label, score] = RF(input_data)
    RF = loadLearnerForCoder("RF_model.mat");
    [label,score] = predict(RF, input_data);
end
