function [trainedClassifier, validationAccuracy] = trainClassifier_3knn(trainingData)
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

% �� MATLAB �� 2020-08-25 21:13:06 �Զ�����


% ��ȡԤ���������Ӧ
% ���´��뽫���ݴ���Ϊ���ʵ���״��ѵ��ģ�͡�
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA', 'frame_mean', 'frame_max', 'frame_min', 'frame_change'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% ����ת��: ѡ�������Ӽ�
% ���´���ѡ��������Ӽ��� App ��ʹ�õ���ͬ��
includedPredictorNames = predictors.Properties.VariableNames([true false false false true false false false true true true false true false false false false false true false false false false false]);
predictors = predictors(:,includedPredictorNames);
isCategoricalPredictor = isCategoricalPredictor([true false false false true false false false true true true false true false false false false false true false false false false false]);

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
knnPredictFcn = @(x) predict(classificationKNN, x);
trainedClassifier.predictFcn = @(x) knnPredictFcn(featureSelectionFcn(predictorExtractionFcn(x)));

% �����ṹ��������ֶ�
trainedClassifier.RequiredVariables = {'frame_change', 'frame_change_EDA', 'frame_change_acx', 'frame_change_acy', 'frame_change_acz', 'frame_change_temp', 'frame_max', 'frame_max_EDA', 'frame_max_acx', 'frame_max_acy', 'frame_max_acz', 'frame_max_temp', 'frame_mean', 'frame_mean_EDA', 'frame_mean_acx', 'frame_mean_acy', 'frame_mean_acz', 'frame_mean_temp', 'frame_min', 'frame_min_EDA', 'frame_min_acx', 'frame_min_acy', 'frame_min_acz', 'frame_min_temp'};
trainedClassifier.ClassificationKNN = classificationKNN;
trainedClassifier.About = '�˽ṹ���Ǵ� Classification Learner R2019b ������ѵ��ģ�͡�';
trainedClassifier.HowToPredict = sprintf('Ҫ���±� T ����Ԥ�⣬��ʹ��: \n yfit = c.predictFcn(T) \n�� ''c'' �滻Ϊ��Ϊ�˽ṹ��ı��������ƣ����� ''trainedModel''��\n \n�� T ����������������ݷ��صı���: \n c.RequiredVariables \n������ʽ(�������/��������������)������ԭʼѵ������ƥ�䡣\n��������������\n \n�й���ϸ��Ϣ������� <a href="matlab:helpview(fullfile(docroot, ''stats'', ''stats.map''), ''appclassification_exportmodeltoworkspace'')">How to predict using an exported model</a>��');

% ��ȡԤ���������Ӧ
% ���´��뽫���ݴ���Ϊ���ʵ���״��ѵ��ģ�͡�
%
inputTable = trainingData;
predictorNames = {'frame_mean_acx', 'frame_max_acx', 'frame_min_acx', 'frame_change_acx', 'frame_mean_acy', 'frame_max_acy', 'frame_min_acy', 'frame_change_acy', 'frame_mean_acz', 'frame_max_acz', 'frame_min_acz', 'frame_change_acz', 'frame_mean_temp', 'frame_max_temp', 'frame_min_temp', 'frame_change_temp', 'frame_mean_EDA', 'frame_max_EDA', 'frame_min_EDA', 'frame_change_EDA', 'frame_mean', 'frame_max', 'frame_min', 'frame_change'};
predictors = inputTable(:, predictorNames);
response = inputTable.Y_stack;
isCategoricalPredictor = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false];

% ִ�н�����֤
partitionedModel = crossval(trainedClassifier.ClassificationKNN, 'KFold', 5);

% ������֤Ԥ��
[validationPredictions, validationScores] = kfoldPredict(partitionedModel);

% ������֤׼ȷ��
validationAccuracy = 1 - kfoldLoss(partitionedModel, 'LossFun', 'ClassifError');
