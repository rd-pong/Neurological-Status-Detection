clear; clc; close all
x = [1 2 3 4];

knn = [
    79.70	59.40	61.50	91.40
    45.30	49.90	50.40	62.80
    81.60	69.10	60.10	89.60
    82.90	68.80	60.80	89.20];
subplot(211)
scatter(knn(1, :),x, 'd', 'filled'); hold on
scatter(knn(2, :),x, 'p', 'filled'); 
scatter(knn(3, :),x, 'o', 'filled');
scatter(knn(4, :),x, '^', 'filled');
set(gca, 'ytick', x)
set(gca,'YTickLabel',{'HR+SPO2+EDA','HR+SPO2','EDA','Accelerometry'});
legend('mean', 'change', 'max', 'min')
xlabel('Accuracy')
title('kNN');

subplot(212)
rf = [
    89.10	65.70	49.40	92.30
    52.20	51.00	53.50	65.70
    91.30	74.00	69.30	95.20
    89.90	73.90	68.90	91.70];
scatter(rf(1, :),x, 'd', 'filled'); hold on
scatter(rf(2, :),x, 'p', 'filled'); 
scatter(rf(3, :),x, 'o', 'filled');
scatter(rf(4, :),x, '^', 'filled');
set(gca, 'ytick', x)
set(gca,'YTickLabel',{'HR+SPO2+EDA','HR+SPO2','EDA','Accelerometry'})
legend('mean', 'change', 'max', 'min')
xlabel('Accuracy')
title('Random Forest');