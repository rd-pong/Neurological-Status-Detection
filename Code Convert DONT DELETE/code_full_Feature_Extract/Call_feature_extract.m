clear; clc; close all;

%%
frame0_AccTempEDA = load('frame_AccTempEDA.mat').frame0_AccTempEDA;
frame0_SpO2HR = load('frame_SpO2HR.mat').frame0_SpO2HR;

frame1_AccTempEDA = load('frame_AccTempEDA.mat').frame1_AccTempEDA;
frame1_SpO2HR = load('frame_SpO2HR.mat').frame1_SpO2HR;

%%
output0 = feature_extract(frame0_AccTempEDA, frame0_SpO2HR);
output1 = feature_extract(frame1_AccTempEDA, frame1_SpO2HR);