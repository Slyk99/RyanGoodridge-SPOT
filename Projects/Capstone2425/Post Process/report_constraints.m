clc
clear all
close all

%% Constants

yLength = 2.4;
xLength = 3.5;

lidar_FOV = 40*pi/180;

N_h = 15;
T_d = 2;

edge_buffer = 0.27;

%% Select Data Folder

[MAT_FILE, MAT_DIR] = uigetfile('*', 'Select the MAT file', '../Saved Data/');
MAT_FILEPATH = strcat(MAT_DIR, MAT_FILE);

load(MAT_FILEPATH)

%% Load Data

if (exist('dataClass','var') == 1)
    dataClass_rt = dataClass;
end

MPC_trigger = dataClass_rt.RED.Control_Law_Enabler.Data;

MPC_start = find(MPC_trigger == 3, 1);
MPC_end = find(MPC_trigger == 3, 1, 'last');
MPC_step = (round(T_d)/0.05);

DATA_STARTTIME = MPC_start;          
DATA_ENDTIME = MPC_end;

idx = DATA_STARTTIME:DATA_ENDTIME;

time = dataClass_rt.Time_s.Data(idx,:);
time = time-time(1);

RED_Px = dataClass_rt.RED.Px_m.Data(idx,:);
RED_Py = dataClass_rt.RED.Py_m.Data(idx,:);
RED_Rz = dataClass_rt.RED.Rz_rad.Data(idx,:);

BLACK_Px = dataClass_rt.BLACK.Px_m.Data(idx,:);
BLACK_Py = dataClass_rt.BLACK.Py_m.Data(idx,:);
BLACK_Rz = dataClass_rt.BLACK.Rz_rad.Data(idx,:);

BLACK_Vx = dataClass_rt.BLACK.Vx_mpers.Data(idx,:);
BLACK_Vy = dataClass_rt.BLACK.Vy_mpers.Data(idx,:);
BLACK_RzD = dataClass_rt.BLACK.RzD_radpers.Data(idx,:);

RED_Fx = dataClass_rt.RED.Fx_N.Data(idx,:);
RED_Fy = dataClass_rt.RED.Fy_N.Data(idx,:);
RED_Tz = dataClass_rt.RED.Tz_Nm.Data(idx,:);

RED_Fx_Sat = dataClass_rt.RED.Fx_Sat_N.Data(idx,:);
RED_Fy_Sat = dataClass_rt.RED.Fy_Sat_N.Data(idx,:);
RED_Tz_Sat = dataClass_rt.RED.Tz_Sat_Nm.Data(idx,:);

RED_MPC_Fx  = dataClass_rt.MPC.Controls.Data(idx,1);
RED_MPC_Fy  = dataClass_rt.MPC.Controls.Data(idx,2);
RED_MPC_Tz  = dataClass_rt.MPC.Controls.Data(idx,3);

z = dataClass_rt.MPC.Optimization_Variable.Data(idx,:);
z_t = dataClass_rt.MPC.Target_Trajectory.Data(idx,:);

r_hold = dataClass_rt.MPC.Holding_Radius.Data(idx,:);

MPC_Exitflag = dataClass_rt.MPC.Solver_Result.Data(idx,1);
MPC_Iterations = dataClass_rt.MPC.Solver_Result.Data(idx,2);
MPC_CPUTime = dataClass_rt.MPC.Solver_Result.Data(idx,3);

%% Thrust Constraint

figure
tiledlayout(3, 1, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile
plot(time, RED_MPC_Fx, 'r-', 'DisplayName', 'Commanded')
hold on
plot([min(time) max(time)], [0.15, 0.15], 'k--', 'DisplayName', 'Thrust Limits')
plot([min(time) max(time)], [-0.15, -0.15], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.3 0.3])
xlim([time(1) time(end)])
ylabel("F_x [N]")
legend('NumColumns', 2)
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

nexttile
plot(time, RED_MPC_Fy, 'r-', 'DisplayName', 'Commanded')
hold on
plot([min(time) max(time)], [0.15, 0.15], 'k--', 'DisplayName', 'Thrust/Torque Limits')
plot([min(time) max(time)], [-0.15, -0.15], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.3 0.3])
xlim([time(1) time(end)])
ylabel("F_y [N]")
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

nexttile
plot(time, RED_MPC_Tz, 'r-', 'DisplayName', 'Commanded')
hold on
plot([min(time) max(time)], [0.0225, 0.0225], 'k--', 'DisplayName', 'Torque Limits')
plot([min(time) max(time)], [-0.0225, -0.0225], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.03 0.03])
xlim([time(1) time(end)])
ylabel("\tau_z [Nm]")
xlabel("Time [s]")
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

%% Vision Constraint

theta_star = unwrap(atan2(RED_Py-BLACK_Py,RED_Px-BLACK_Px));

figure
plot(time, theta_star, 'k', 'DisplayName', 'Ideal')
hold on
plot(time, unwrap(RED_Rz)+pi, 'r', 'DisplayName', 'Actual')
plot(time, theta_star+lidar_FOV/2, 'k--', 'DisplayName', 'FOV Limits')
plot(time, theta_star-lidar_FOV/2, 'k--', 'HandleVisibility','off')
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("\theta_s [rad]")
legend('Location', 'northwest')
xlim([time(1) time(end)])
ylim([0 4])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

%% Dynamic Collision Constraint

[a_e, b_e] = deal(r_hold(:,1), r_hold(:,2));

r_e = zeros(length(r_hold),1);
r = zeros(length(r_hold),1);
for j = 1:length(r_e)
    r_tar = [BLACK_Px(j); BLACK_Py(j)];
    r_chs = [RED_Px(j); RED_Py(j)];
    theta_tar = BLACK_Rz(j);

    u_tc = (r_chs-r_tar)/norm(r_chs-r_tar);

    R = [cos(theta_tar) -sin(theta_tar); 
         sin(theta_tar) cos(theta_tar)];

    theta_e = acos(u_tc'*(R*[1; 0]));

    r_e(j) = a_e(j)*b_e(j)/sqrt((a_e(j)*sin(theta_e))^2 + (b_e(j)*cos(theta_e))^2);
    r(j) = sqrt((BLACK_Px(j)-RED_Px(j))^2+(BLACK_Py(j)-RED_Py(j))^2);
end

figure
plot(time, r_e, 'k--', 'DisplayName', 'Holding Region Radius')
hold on
plot(time, r, 'r', 'DisplayName', 'Client-Servicer Distance')
xlabel("Time [s]")
ylabel("Distance [m]")
xlim([time(1) time(end)])
grid on
legend
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

%% Workspace Constraint


figure
tiledlayout(2, 1, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile
plot(time, RED_Px, 'r', 'DisplayName', 'Actual')
hold on
plot([min(time) max(time)], [xLength-edge_buffer xLength-edge_buffer], 'k--', 'DisplayName', 'Workspace Limits');
plot([min(time) max(time)], [edge_buffer edge_buffer], 'k--', 'HandleVisibility', 'off');
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("{\it x}_s [m]")
legend('Location', 'northeast', 'NumColumns', 2)
ylim([0 xLength])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

nexttile
plot(time, RED_Py, 'r', 'DisplayName', '')
hold on
plot([min(time) max(time)], [yLength-edge_buffer yLength-edge_buffer], 'k--', 'DisplayName', 'Workspace Limits');
plot([min(time) max(time)], [edge_buffer edge_buffer], 'k--', 'HandleVisibility', 'off');
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("{\it y}_s [m]")
xlim([time(1) time(end)])
ylim([0 yLength])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)