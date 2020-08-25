function [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% [trainedClassifier, validationAccuracy] = trainClassifier(trainingData)
% ���ؾ���ѵ���ķ���������׼ȷ�ȡ����´������´����� Classification Learner App ��ѵ
% ���ķ���ģ�͡�������ʹ�ø����ɵĴ�������������Զ�ѵ��ͬһģ�ͣ���ͨ�����˽�����Գ��򻯷�
% ʽѵ��ģ�͡�
%
%  ����:
%      trainingData: һ������Ԥ���������Ӧ���뵼�� App �е���ͬ�ı�
%
%  ���:
%      trainedClassifier: һ������ѵ���ķ������Ľṹ�塣�ýṹ���о��и��ֹ�����ѵ����
%       ��������Ϣ���ֶΡ�
%
%      trainedClassifier.predictFcn: һ���������ݽ���Ԥ��ĺ�����
%
%      validationAccuracy: һ������׼ȷ�Ȱٷֱȵ�˫����ֵ���� App �У�"��ʷ��¼" ��
%       ����ʾÿ��ģ�͵Ĵ�����׼ȷ�ȷ�����
%
% ʹ�øô��������������ѵ��ģ�͡�Ҫ����ѵ������������ʹ��ԭʼ���ݻ���������Ϊ�������
% trainingData �������е��øú�����
%
% ���磬Ҫ����ѵ������ԭʼ���ݼ� T ѵ���ķ�������������:
%   [trainedClassifier, validationAccuracy] = trainClassifier(T)
%
% Ҫʹ�÷��ص� "trainedClassifier" �������� T2 ����Ԥ�⣬��ʹ��
%   yfit = trainedClassifier.predictFcn(T2)
%
% T2 ������һ�����������ٰ�����ѵ���ڼ�ʹ�õ�Ԥ���������ͬ��Ԥ������С��й���ϸ��Ϣ����
% ����:
%   trainedClassifier.HowToPredict

% �� MATLAB �� 2020-08-25 11:55:02 �Զ�����


% ��ȡԤ���������Ӧ
% ���´��뽫���ݴ���Ϊ���ʵ���״��ѵ��ģ�͡�
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% ����ת��: ѡ�������Ӽ�
% ���´���ѡ��������Ӽ��� App ��ʹ�õ���ͬ��
includedPredictorNames = predictors.Properties.VariableNames([true true true true true true true true true true true true false false false false true true true true]);
predictors = predictors(:,includedPredictorNames);
isCategoricalPredictor = isCategoricalPredictor([true true true true true true true true true true true true false false false false true true true true]);

% �� PCA Ӧ����Ԥ���������
% ������ֵԤ��������� PCA��PCA ����Է���Ԥ����������κδ���
isCategoricalPredictorBeforePCA = isCategoricalPredictor;
numericPredictors = predictors(:, ~isCategoricalPredictor);
numericPredictors = table2array(varfun(@double, numericPredictors));
% �� PCA �б��뽫 'inf' ֵ��Ϊȱʧ���ݡ�
numericPredictors(isinf(numericPredictors)) = NaN;
[pcaCoefficients, pcaScores, ~, ~, explained, pcaCenters] = pca(...
    numericPredictors);
% �����㹻�ĳɷ�����������ķ�������
explainedVarianceToKeepAsFraction = 95/100;
numComponentsToKeep = find(cumsum(explained)/sum(explained) >= explainedVarianceToKeepAsFraction, 1);
pcaCoefficients = pcaCoefficients(:,1:numComponentsToKeep);
predictors = [array2table(pcaScores(:,1:numComponentsToKeep)), predictors(:, isCategoricalPredictor)];
isCategoricalPredictor = [false(1,numComponentsToKeep), true(1,sum(isCategoricalPredictor))];

% ѵ��������
% ���´���ָ�����з�����ѡ�ѵ����������
classificationKNN = fitcknn(...
    predictors, ...
    response, ...
    'Distance', 'Euclidean', ...
    'Exponent', [], ...
    'NumNeighbors', 3, ...
    'DistanceWeight', 'Equal', ...
    'Standardize', true, ...
    'ClassNames', [0; 1; 2; 3]);

% ʹ��Ԥ�⺯����������ṹ��
predictorExtractionFcn = @(t) t(:, predictorNames);
featureSelectionFcn = @(x) x(:,includedPredictorNames);
pcaTransformationFcn = @(x) [ array2table((table2array(varfun(@double, x(:, ~isCategoricalPredictorBeforePCA))) - pcaCenters) * pcaCoefficients), x(:,isCategoricalPredictorBeforePCA) ];
knnPredictFcn = @(x) predict(classificationKNN, x);
trainedClassifier.predictFcn = @(x) knnPredictFcn(pcaTransformationFcn(featureSelectionFcn(predictorExtractionFcn(x))));

% �����ṹ��������ֶ�
trainedClassifier.RequiredVariables = {'frame_change_EDA', 'frame_change_acx', 'frame_change_acy', 'frame_change_acz', 'frame_change_temp', 'frame_max_EDA', 'frame_max_acx', 'frame_max_acy', 'frame_max_acz', 'frame_max_temp', 'frame_mean_EDA', 'frame_mean_acx', 'frame_mean_acy', 'frame_mean_acz', 'frame_mean_temp', 'frame_min_EDA', 'frame_min_acx', 'frame_min_acy', 'frame_min_acz', 'frame_min_temp'};
trainedClassifier.PCACenters = pcaCenters;
trainedClassifier.PCACoefficients = pcaCoefficients;
trainedClassifier.ClassificationKNN = classificationKNN;
trainedClassifier.About = '�˽ṹ���Ǵ� Classification Learner R2019b ������ѵ��ģ�͡�';
trainedClassifier.HowToPredict = sprintf('Ҫ���±� T ����Ԥ�⣬��ʹ��: \n yfit = c.predictFcn(T) \n�� ''c'' �滻Ϊ��Ϊ�˽ṹ��ı��������ƣ����� ''trainedModel''��\n \n�� T ����������������ݷ��صı���: \n c.RequiredVariables \n������ʽ(�������/��������������)������ԭʼѵ������ƥ�䡣\n��������������\n \n�й���ϸ��Ϣ������� <a href="matlab:helpview(fullfile(docroot, ''stats'', ''stats.map''), ''appclassification_exportmodeltoworkspace'')">How to predict using an exported model</a>��');

% ��ȡԤ���������Ӧ
% ���´��뽫���ݴ���Ϊ���ʵ���״��ѵ��ģ�͡�
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% ִ�н�����֤
KFolds = 5;
cvp = cvpartition(response, 'KFold', KFolds);
% ��Ԥ���ʼ��Ϊ�ʵ��Ĵ�С
validationPredictions = response;
numObservations = size(predictors, 1);
numClasses = 4;
validationScores = NaN(numObservations, numClasses);
for fold = 1:KFolds
    trainingPredictors = predictors(cvp.training(fold), :);
    trainingResponse = response(cvp.training(fold), :);
    foldIsCategoricalPredictor = isCategoricalPredictor;
    
    % ����ת��: ѡ�������Ӽ�
    % ���´���ѡ��������Ӽ��� App ��ʹ�õ���ͬ��
    includedPredictorNames = trainingPredictors.Properties.VariableNames([true true true true true true true true true true true true false false false false true true true true]);
    trainingPredictors = trainingPredictors(:,includedPredictorNames);
    foldIsCategoricalPredictor = foldIsCategoricalPredictor([true true true true true true true true true true true true false false false false true true true true]);
    
    % �� PCA Ӧ����Ԥ���������
    % ������ֵԤ��������� PCA��PCA ����Է���Ԥ����������κδ���
    isCategoricalPredictorBeforePCA = foldIsCategoricalPredictor;
    numericPredictors = trainingPredictors(:, ~foldIsCategoricalPredictor);
    numericPredictors = table2array(varfun(@double, numericPredictors));
    % �� PCA �б��뽫 'inf' ֵ��Ϊȱʧ���ݡ�
    numericPredictors(isinf(numericPredictors)) = NaN;
    [pcaCoefficients, pcaScores, ~, ~, explained, pcaCenters] = pca(...
        numericPredictors);
    % �����㹻�ĳɷ�����������ķ�������
    explainedVarianceToKeepAsFraction = 95/100;
    numComponentsToKeep = find(cumsum(explained)/sum(explained) >= explainedVarianceToKeepAsFraction, 1);
    pcaCoefficients = pcaCoefficients(:,1:numComponentsToKeep);
    trainingPredictors = [array2table(pcaScores(:,1:numComponentsToKeep)), trainingPredictors(:, foldIsCategoricalPredictor)];
    foldIsCategoricalPredictor = [false(1,numComponentsToKeep), true(1,sum(foldIsCategoricalPredictor))];
    
    % ѵ��������
    % ���´���ָ�����з�����ѡ�ѵ����������
    classificationKNN = fitcknn(...
        trainingPredictors, ...
        trainingResponse, ...
        'Distance', 'Euclidean', ...
        'Exponent', [], ...
        'NumNeighbors', 3, ...
        'DistanceWeight', 'Equal', ...
        'Standardize', true, ...
        'ClassNames', [0; 1; 2; 3]);
    
    % ʹ��Ԥ�⺯����������ṹ��
    featureSelectionFcn = @(x) x(:,includedPredictorNames);
    pcaTransformationFcn = @(x) [ array2table((table2array(varfun(@double, x(:, ~isCategoricalPredictorBeforePCA))) - pcaCenters) * pcaCoefficients), x(:,isCategoricalPredictorBeforePCA) ];
    knnPredictFcn = @(x) predict(classificationKNN, x);
    validationPredictFcn = @(x) knnPredictFcn(pcaTransformationFcn(featureSelectionFcn(x)));
    
    % �����ṹ��������ֶ�
    
    % ������֤Ԥ��
    validationPredictors = predictors(cvp.test(fold), :);
    [foldPredictions, foldScores] = validationPredictFcn(validationPredictors);
    
    % ��ԭʼ˳��洢Ԥ��
    validationPredictions(cvp.test(fold), :) = foldPredictions;
    validationScores(cvp.test(fold), :) = foldScores;
end

% ������֤׼ȷ��
correctPredictions = (validationPredictions == response);
isMissing = isnan(response);
correctPredictions = correctPredictions(~isMissing);
validationAccuracy = sum(correctPredictions)/length(correctPredictions);
