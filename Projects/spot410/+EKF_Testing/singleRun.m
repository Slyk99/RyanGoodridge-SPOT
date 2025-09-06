close all
% clear
clc

% Loads GUI and all params - GUI NOT USED
% Run_Initializer;

% Load experimental data
load('+navigation_module/ExperimentData_RED_2025_7_24_14_6_22_4009_1.mat')


%% Filter IC
% x_s = [1; 2; 0; 0; 0; 0];
% x_c = [ones(3,1); 0; 0; 0];
% x_rel = globalToRelative(x_s, x_c);
% x_rel = [x_rel; x_s(3); x_s(6);]; % added theta_s and w_s

% x_s = [dataClass_rt.RED_Px_m.Data, dataClass_rt.RED_Py_m.Data, dataClass_rt.RED_Rz_rad.Data, ...
%        dataClass_rt.RED_Vx_mpers.Data, dataClass_rt.RED_Vy_mpers.Data, dataClass_rt.RED_RzD_radpers.Data]';
% x_c = [dataClass_rt.BLACK_Px_m.Data, dataClass_rt.BLACK_Py_m.Data, dataClass_rt.BLACK_Rz_rad.Data, ...
%        dataClass_rt.BLACK_Vx_mpers.Data, dataClass_rt.BLACK_Vy_mpers.Data, dataClass_rt.BLACK_RzD_radpers.Data]';
% x_rel = globalToRelative(x_s(:,3), x_c(:,3)) + [1e-2*rand([3,1]); 1e-3*rand([3,1])];

