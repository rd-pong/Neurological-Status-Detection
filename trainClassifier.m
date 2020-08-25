function [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% 返回经过训练的分类器及其准确度。以下代码重新创建在 Classification Learner App 中训
% 练的分类模型。您可以使用该生成的代码基于新数据自动训练同一模型，或通过它了解如何以程序化方
% 式训练模型。
%
%  输入:
%      trainingData: 一个所含预测变量和响应列与导入 App 中的相同的表。
%
%  输出:
%      trainedClassifier: 一个包含训练的分类器的结构体。该结构体中具有各种关于所训练分
%       类器的信息的字段。
%
%      trainedClassifier.predictFcn: 一个对新数据进行预测的函数。
%
%      validationAccuracy: 一个包含准确度百分比的双精度值。在 App 中，"历史记录" 列
%       表显示每个模型的此总体准确度分数。
%
% 使用该代码基于新数据来训练模型。要重新训练分类器，请使用原始数据或新数据作为输入参数
% trainingData 从命令行调用该函数。
%
% 例如，要重新训练基于原始数据集 T 训练的分类器，请输入:
%   [trainedClassifier, validationAccuracy] = trainClassifier(T)
%
% 要使用返回的 "trainedClassifier" 对新数据 T2 进行预测，请使用
%   yfit = trainedClassifier.predictFcn(T2)
%
% T2 必须是一个表，其中至少包含与训练期间使用的预测变量列相同的预测变量列。有关详细信息，请
% 输入:
%   trainedClassifier.HowToPredict

% 由 MATLAB 于 2020-08-25 11:55:02 自动生成


% 提取预测变量和响应
% 以下代码将数据处理为合适的形状以训练模型。
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% 数据转换: 选择特征子集
% 以下代码选择的特征子集与 App 中使用的相同。
includedPredictorNames = predictors.Properties.VariableNames([true true true true true true true true true true true true false false false false true true true true]);
predictors = predictors(:,includedPredictorNames);
isCategoricalPredictor = isCategoricalPredictor([true true true true true true true true true true true true false false false false true true true true]);

% 将 PCA 应用于预测变量矩阵。
% 仅对数值预测变量运行 PCA。PCA 不会对分类预测变量进行任何处理。
isCategoricalPredictorBeforePCA = isCategoricalPredictor;
numericPredictors = predictors(:, ~isCategoricalPredictor);
numericPredictors = table2array(varfun(@double, numericPredictors));
% 在 PCA 中必须将 'inf' 值视为缺失数据。
numericPredictors(isinf(numericPredictors)) = NaN;
[pcaCoefficients, pcaScores, ~, ~, explained, pcaCenters] = pca(...
    numericPredictors);
% 保留足够的成分来解释所需的方差量。
explainedVarianceToKeepAsFraction = 95/100;
numComponentsToKeep = find(cumsum(explained)/sum(explained) >= explainedVarianceToKeepAsFraction, 1);
pcaCoefficients = pcaCoefficients(:,1:numComponentsToKeep);
predictors = [array2table(pcaScores(:,1:numComponentsToKeep)), predictors(:, isCategoricalPredictor)];
isCategoricalPredictor = [false(1,numComponentsToKeep), true(1,sum(isCategoricalPredictor))];

% 训练分类器
% 以下代码指定所有分类器选项并训练分类器。
classificationKNN = fitcknn(...
    predictors, ...
    response, ...
    'Distance', 'Euclidean', ...
    'Exponent', [], ...
    'NumNeighbors', 3, ...
    'DistanceWeight', 'Equal', ...
    'Standardize', true, ...
    'ClassNames', [0; 1; 2; 3]);

% 使用预测函数创建结果结构体
predictorExtractionFcn = @(t) t(:, predictorNames);
featureSelectionFcn = @(x) x(:,includedPredictorNames);
pcaTransformationFcn = @(x) [ array2table((table2array(varfun(@double, x(:, ~isCategoricalPredictorBeforePCA))) - pcaCenters) * pcaCoefficients), x(:,isCategoricalPredictorBeforePCA) ];
knnPredictFcn = @(x) predict(classificationKNN, x);
trainedClassifier.predictFcn = @(x) knnPredictFcn(pcaTransformationFcn(featureSelectionFcn(predictorExtractionFcn(x))));

% 向结果结构体中添加字段
trainedClassifier.RequiredVariables = {'frame_change_EDA', 'frame_change_acx', 'frame_change_acy', 'frame_change_acz', 'frame_change_temp', 'frame_max_EDA', 'frame_max_acx', 'frame_max_acy', 'frame_max_acz', 'frame_max_temp', 'frame_mean_EDA', 'frame_mean_acx', 'frame_mean_acy', 'frame_mean_acz', 'frame_mean_temp', 'frame_min_EDA', 'frame_min_acx', 'frame_min_acy', 'frame_min_acz', 'frame_min_temp'};
trainedClassifier.PCACenters = pcaCenters;
trainedClassifier.PCACoefficients = pcaCoefficients;
trainedClassifier.ClassificationKNN = classificationKNN;
trainedClassifier.About = '此结构体是从 Classification Learner R2019b 导出的训练模型。';
trainedClassifier.HowToPredict = sprintf('要对新表 T 进行预测，请使用: \n yfit = c.predictFcn(T) \n将 ''c'' 替换为作为此结构体的变量的名称，例如 ''trainedModel''。\n \n表 T 必须包含由以下内容返回的变量: \n c.RequiredVariables \n变量格式(例如矩阵/向量、数据类型)必须与原始训练数据匹配。\n忽略其他变量。\n \n有关详细信息，请参阅 <a href="matlab:helpview(fullfile(docroot, ''stats'', ''stats.map''), ''appclassification_exportmodeltoworkspace'')">How to predict using an exported model</a>。');

% 提取预测变量和响应
% 以下代码将数据处理为合适的形状以训练模型。
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% 执行交叉验证
KFolds = 5;
cvp = cvpartition(response, 'KFold', KFolds);
% 将预测初始化为适当的大小
validationPredictions = response;
numObservations = size(predictors, 1);
numClasses = 4;
validationScores = NaN(numObservations, numClasses);
for fold = 1:KFolds
    trainingPredictors = predictors(cvp.training(fold), :);
    trainingResponse = response(cvp.training(fold), :);
    foldIsCategoricalPredictor = isCategoricalPredictor;
    
    % 数据转换: 选择特征子集
    % 以下代码选择的特征子集与 App 中使用的相同。
    includedPredictorNames = trainingPredictors.Properties.VariableNames([true true true true true true true true true true true true false false false false true true true true]);
    trainingPredictors = trainingPredictors(:,includedPredictorNames);
    foldIsCategoricalPredictor = foldIsCategoricalPredictor([true true true true true true true true true true true true false false false false true true true true]);
    
    % 将 PCA 应用于预测变量矩阵。
    % 仅对数值预测变量运行 PCA。PCA 不会对分类预测变量进行任何处理。
    isCategoricalPredictorBeforePCA = foldIsCategoricalPredictor;
    numericPredictors = trainingPredictors(:, ~foldIsCategoricalPredictor);
    numericPredictors = table2array(varfun(@double, numericPredictors));
    % 在 PCA 中必须将 'inf' 值视为缺失数据。
    numericPredictors(isinf(numericPredictors)) = NaN;
    [pcaCoefficients, pcaScores, ~, ~, explained, pcaCenters] = pca(...
        numericPredictors);
    % 保留足够的成分来解释所需的方差量。
    explainedVarianceToKeepAsFraction = 95/100;
    numComponentsToKeep = find(cumsum(explained)/sum(explained) >= explainedVarianceToKeepAsFraction, 1);
    pcaCoefficients = pcaCoefficients(:,1:numComponentsToKeep);
    trainingPredictors = [array2table(pcaScores(:,1:numComponentsToKeep)), trainingPredictors(:, foldIsCategoricalPredictor)];
    foldIsCategoricalPredictor = [false(1,numComponentsToKeep), true(1,sum(foldIsCategoricalPredictor))];
    
    % 训练分类器
    % 以下代码指定所有分类器选项并训练分类器。
    classificationKNN = fitcknn(...
        trainingPredictors, ...
        trainingResponse, ...
        'Distance', 'Euclidean', ...
        'Exponent', [], ...
        'NumNeighbors', 3, ...
        'DistanceWeight', 'Equal', ...
        'Standardize', true, ...
        'ClassNames', [0; 1; 2; 3]);
    
    % 使用预测函数创建结果结构体
    featureSelectionFcn = @(x) x(:,includedPredictorNames);
    pcaTransformationFcn = @(x) [ array2table((table2array(varfun(@double, x(:, ~isCategoricalPredictorBeforePCA))) - pcaCenters) * pcaCoefficients), x(:,isCategoricalPredictorBeforePCA) ];
    knnPredictFcn = @(x) predict(classificationKNN, x);
    validationPredictFcn = @(x) knnPredictFcn(pcaTransformationFcn(featureSelectionFcn(x)));
    
    % 向结果结构体中添加字段
    
    % 计算验证预测
    validationPredictors = predictors(cvp.test(fold), :);
    [foldPredictions, foldScores] = validationPredictFcn(validationPredictors);
    
    % 按原始顺序存储预测
    validationPredictions(cvp.test(fold), :) = foldPredictions;
    validationScores(cvp.test(fold), :) = foldScores;
end

% 计算验证准确度
correctPredictions = (validationPredictions == response);
isMissing = isnan(response);
correctPredictions = correctPredictions(~isMissing);
validationAccuracy = sum(correctPredictions)/length(correctPredictions);
