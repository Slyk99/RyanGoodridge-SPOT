clc
clear all
close all

%% Constants

yLength = 2.4;
xLength = 3.5;

lidar_FOV = 50*pi/180;

N_h = 15;
T_d = 2;

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
DATA_STEP = MPC_step/8;

idx = DATA_STARTTIME:DATA_STEP:length(MPC_trigger);

time = dataClass_rt.Time_s.Data(idx,:);

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

BLACK_Px_Vis = dataClass_rt.VIS.BLACK_States.Data(idx,1);
BLACK_Py_Vis = dataClass_rt.VIS.BLACK_States.Data(idx,2);
BLACK_Rz_Vis = dataClass_rt.VIS.BLACK_States.Data(idx,3);

BLACK_Px_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,1);
BLACK_Py_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,2);
BLACK_Rz_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,3);
BLACK_Vx_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,4);
BLACK_Vy_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,5);
BLACK_RzD_Est = dataClass_rt.UKF.BLACK_Estimated_States.Data(idx,6);

BLACK_Vx_Est_Avg = dataClass_rt.UKF.BLACK_Estimated_Velocity.Data(idx,1);
BLACK_Vy_Est_Avg = dataClass_rt.UKF.BLACK_Estimated_Velocity.Data(idx,2);
BLACK_RzD_Est_Avg = dataClass_rt.UKF.BLACK_Estimated_Velocity.Data(idx,3);

BLACK_P = dataClass_rt.UKF.Estimation_Covariance.Data(idx,:);

BLACK_Px_Meas = dataClass_rt.VIS.BLACK_Measurements.Data(idx,1);
BLACK_Py_Meas = dataClass_rt.VIS.BLACK_Measurements.Data(idx,2);
BLACK_Rz_Meas = dataClass_rt.VIS.BLACK_Measurements.Data(idx,3);

%% MPC Statistics

figure
plot(time, MPC_Exitflag)
grid on
xlabel("Time [s]")
ylabel("Exit Flag")
xlim([time(1) time(end)])

figure
plot(time, MPC_Iterations)
grid on
xlabel("Time [s]")
ylabel("# of Iterations")
xlim([time(1) time(end)])

figure
plot(time, MPC_CPUTime)
grid on
xlabel("Time [s]")
ylabel("Computation Time [s]")
xlim([time(1) time(end)])

%% Thrust Constraint

figure
plot(time, RED_Fx, 'k-', 'DisplayName', 'Commanded Thrust')
hold on
plot(time,RED_Fx_Sat, 'r-', 'DisplayName', 'Saturated Torque')
plot([min(time) max(time)], [0.15, 0.15], 'k--', 'DisplayName', '\pmThrust Limits')
plot([min(time) max(time)], [-0.15, -0.15], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.2 0.2])
xlim([time(1) time(end)])
ylabel("X-Thrust [N]")
xlabel("Time [s]")

figure
plot(time, RED_Fy, 'k-', 'DisplayName', 'Commanded Thrust')
hold on
plot(time,RED_Fy_Sat, 'r-', 'DisplayName', 'Saturated Torque')
plot([min(time) max(time)], [0.15, 0.15], 'k--', 'DisplayName', '\pmThrust Limits')
plot([min(time) max(time)], [-0.15, -0.15], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.2 0.2])
xlim([time(1) time(end)])
ylabel("Y-Thrust [N]")
xlabel("Time [s]")

figure
plot(time, RED_MPC_Tz, 'k-', 'DisplayName', 'Commanded Torque')
hold on
plot(time,RED_Tz_Sat, 'r-', 'DisplayName', 'Saturated Torque')
plot([min(time) max(time)], [0.0225, 0.0225], 'k--', 'DisplayName', '\pmTorque Limits')
plot([min(time) max(time)], [-0.0225, -0.0225], 'k--', 'HandleVisibility', 'off')
grid on
ylim([-0.03 0.03])
xlim([time(1) time(end)])
ylabel("Z-Torque [Nm]")
xlabel("Time [s]")
legend

%% Vision Constraint

theta_star = unwrap(atan2(RED_Py-BLACK_Py,RED_Px-BLACK_Px));

figure
plot(time, unwrap(RED_Rz)+pi, 'r', 'DisplayName', 'Servicer Attitude')
hold on
plot(time, theta_star, 'k', 'DisplayName', 'Desired Pointing Attitude')
plot(time, theta_star+lidar_FOV/2, 'k--', 'DisplayName', '\pmFOV Limits')
plot(time, theta_star-lidar_FOV/2, 'k--', 'HandleVisibility','off')
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Attitude [rad]")
legend

%% Vision/UKF Data - (Positions)

idx_meas = find(dataClass_rt.VIS.BLACK_Measurements.Data(idx,1) ~= 0);

figure
plot(time(idx_meas), BLACK_Px_Vis(idx_meas), 'r', 'DisplayName', "Measurement")
hold on
plot(time,BLACK_Px, 'k', 'DisplayName', "Ground Truth")
plot(time, BLACK_Px_Est, 'b', 'DisplayName', "Estimation")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("X-Position [m]")
legend

figure
plot(time(idx_meas), BLACK_Py_Vis(idx_meas), 'r', 'DisplayName', "Measurement")
hold on
plot(time,BLACK_Py, 'k', 'DisplayName', "Ground Truth")
plot(time, BLACK_Py_Est, 'b', 'DisplayName', "Estimation")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Y-Position [m]")
legend

figure
plot(time(idx_meas), BLACK_Rz_Vis(idx_meas), 'r', 'DisplayName', "Measurement")
hold on
plot(time,BLACK_Rz, 'k', 'DisplayName', "Ground Truth")
plot(time, BLACK_Rz_Est, 'b', 'DisplayName', "Estimation")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Attitude [rad]")
legend

figure
plot(time,BLACK_Vx, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_Vx_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_Vx_Est_Avg, 'r', 'DisplayName', "Estimation (MA)")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("X-Velocity [m/s]")
legend

figure
plot(time,BLACK_Vy, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_Vy_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_Vy_Est_Avg, 'r', 'DisplayName', "Estimation (MA)")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Y-Velocity [m/s]")
legend

figure
plot(time,BLACK_RzD, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_RzD_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_RzD_Est_Avg, 'r', 'DisplayName', "Estimation (MA)")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Angular Velocity [rad/s]")
legend

%% Vision Errors

figure
plot(time(idx_meas), BLACK_Px_Vis(idx_meas)-BLACK_Px(idx_meas), 'r', 'DisplayName', "Error")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("X-Position Error [m]")
legend

figure
plot(time(idx_meas), BLACK_Py_Vis(idx_meas)-BLACK_Py(idx_meas), 'r', 'DisplayName', "Error")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Y-Position Error [m]")
legend

figure
plot(time(idx_meas), BLACK_Rz_Vis(idx_meas)-BLACK_Rz(idx_meas), 'r', 'DisplayName', "Error")
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Attitude Error [rad]")
legend

%% UKF Data

sigma_3 = zeros(length(time),6);

for j = 1:length(time)
    sigma_3(j,:) = 3*sqrt(diag(reshape(BLACK_P(j,:),6,6)));
end

figure
plot(time,BLACK_Px, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_Px_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_Px_Est+sigma_3(:,1), 'b--', 'DisplayName', '\pm 3\sigma Bounds')
plot(time, BLACK_Px_Est-sigma_3(:,1), 'b--', 'HandleVisibility', 'off')
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("X-Position [m]")
legend

figure
plot(time,BLACK_Py, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_Py_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_Py_Est+sigma_3(:,2), 'b--', 'DisplayName', '\pm 3\sigma Bounds')
plot(time, BLACK_Py_Est-sigma_3(:,2), 'b--', 'HandleVisibility', 'off')
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Y-Position [m]")
legend

figure
plot(time,BLACK_Rz, 'k', 'DisplayName', "Ground Truth")
hold on
plot(time, BLACK_Rz_Est, 'b', 'DisplayName', "Estimation")
plot(time, BLACK_Rz_Est+sigma_3(:,3), 'b--', 'DisplayName', '\pm 3\sigma Bounds')
plot(time, BLACK_Rz_Est-sigma_3(:,3), 'b--', 'HandleVisibility', 'off')
xlim([time(1) time(end)])
grid on
xlabel("Time [s]")
ylabel("Attitude [rad]")
legend
