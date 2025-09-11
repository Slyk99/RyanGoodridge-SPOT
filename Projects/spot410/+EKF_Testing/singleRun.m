% close all
% clear
clc

% Loads GUI and all params - GUI NOT USED
% Run_Initializer;

% Load experimental data
% load('+navigation_module/ExperimentData_RED_2025_7_24_14_6_22_4009_1.mat')
% load('+navigation_module/ExperimentData_RED_2025_7_24_15_31_59_0273_1.mat')
load('+navigation_module/ExperimentData_RED_2025_7_24_16_9_56_3461_3.mat')
initSpotEKF

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

data = sim("+EKF_Testing\EKF_OPT.slx");

%%
lidar = [data.LiDAR(:,1:2).*data.LiDAR(:,3), data.LiDAR(:,4)];
CNN   = [data.Stereo(:,1:2).*data.Stereo(:,3), data.Stereo(:,4)];

figure
for i = 1:1:3
    subplot(3,1,i)
    plot(data.PS(:,i), 'k')
    hold on
    plot(lidar(:,i), 'b*')
    plot(CNN(:,i), 'g*')    
    plot(data.x_INS(:,i),'r')
    grid on
end

figure
for i = 4:1:6
    subplot(3,1,i-3)
    plot(data.PS(:,i), 'k')
    hold on
    plot(data.x_INS(:,i),'r')
    grid on
end

figure
for i = 7:1:8
    subplot(2,1,i-6)
    plot(data.PS(:,i), 'k')
    hold on
    plot(data.IMU(:,i-6), 'b*')
    plot(data.x_INS(:,i),'r')
    plot(data.bias(:,i+8),'g')
    grid on
end

%%
P = recoverP(data.P_INS);
V = data.V;

figure
for i = 1:1:5
    P_angle = squeeze(P(i,i,:) + navOpts.R_GNS(i,i));
    V_angle = squeeze(V(i,i,:));

    subplot(5,1,i)
    plot(P_angle, 'k')
    hold on
    plot(V_angle,'r')
    grid on
    ylim([0,1e-2])
end

figure
for i = 1:1:5
    subplot(5,1,i)
    plot(data.d(:,i),'k')
    grid on
end

function P = recoverP(ud)
P = zeros(size(ud));

    % UD is n-by-n combined matrix
    n = size(ud,1);
    idx = 1:(n+1):n*n;        % linear indices of diagonal entries

for i = 1:1:length(P)
    UD = ud(:,:,i);
    dvec = UD(idx);          % extract diagonal as vector
    D = diag(dvec);          % full diagonal matrix (optional)
    U = UD;                  
    U(idx) = 1;              % set diagonal to ones -> unit upper triangular U
    P(:,:,i) = U*D*U';
end

end