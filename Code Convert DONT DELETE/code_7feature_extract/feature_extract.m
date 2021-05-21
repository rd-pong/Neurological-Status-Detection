function output = feature_extract(frame_AccTempEDA, frame_SpO2HR)
% input: AccTempEDA, SpO2HR
% output: feature matrix of size (5+2)*4, 
% 5column-->AccTempEDA, 2column-->SpO2HR,4-->features(min/max/mean/change)
%

%% AccTempEDA
L1 = 48; R1 = 24;
[acx_max] = td_analysis(frame_AccTempEDA(:, 1), L1, R1);
[acy_max] = td_analysis(frame_AccTempEDA(:, 2), L1, R1);
[acz_max] = td_analysis(frame_AccTempEDA(:, 3), L1, R1);
[temp_max] = td_analysis(frame_AccTempEDA(:, 4), L1, R1);
[EDA_max] = td_analysis(frame_AccTempEDA(:, 5), L1, R1);

%% SpO2HR
L2 = 6; R2 = 3;
[SPO2_max] = td_analysis(frame_SpO2HR(:, 1), L2, R2);
[HR_max] = td_analysis(frame_SpO2HR(:, 2), L2, R2);

%% Create table according to Code Generation (Restriction) for Tables
table_name = {...
            'acx_max','acy_max','acz_max','temp_max','EDA_max','SPO2_max','HR_max'};

output = table(...
            acx_max,acy_max,acz_max,temp_max,EDA_max,SPO2_max,HR_max,...
            'VariableNames', table_name);
end