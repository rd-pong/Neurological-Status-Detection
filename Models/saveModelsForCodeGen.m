%%
load('saved_model_7features.mat')
saveLearnerForCoder(trainedModel_compact_knn.ClassificationKNN, 'kNN_model');
saveLearnerForCoder(trainedModel_compact_rf.ClassificationEnsemble, 'RF_model');
saveLearnerForCoder(trainedModel_compact_svm.ClassificationSVM, 'SVM_model');