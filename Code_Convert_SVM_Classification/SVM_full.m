function [label, score] = SVM_full(input_data)
    RF = loadLearnerForCoder("RF_model.mat");
    [label,score] = predict(RF, input_data);
end
