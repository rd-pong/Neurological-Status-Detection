function [label, score] = SVM(input_data)
    SVM = loadLearnerForCoder("SVM_model.mat");
    [label,score] = predict(SVM, input_data);
end
