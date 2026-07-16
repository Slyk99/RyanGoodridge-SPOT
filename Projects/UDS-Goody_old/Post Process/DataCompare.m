clc
clear all
close all

% Adding parent directory to the path, which contains the plotting functions
parentDirectory = fileparts(cd);
addpath(parentDirectory)          
addpath("functions")

%%

yLength = 2.4;
xLength = 3.5;

edge_buffer = 0.27;

N_h = 15;
T_d = 2;

%% Select Simulation and Experiment MAT files

[EXP_FILE, EXP_DIR] = uigetfile('*', 'Select the MAT file', '../Saved Data/');
EXP_FILEPATH = strcat(EXP_DIR, EXP_FILE);

dataClass_EXP = load(EXP_FILEPATH).dataClass;

[SIM_FILE, SIM_DIR] = uigetfile('*', 'Select the MAT file', '../Saved Data/');
SIM_FILEPATH = strcat(SIM_DIR, SIM_FILE);

dataClass_SIM = load(SIM_FILEPATH).dataClass;

%% Load Timing Data

MPC_trigger_EXP = dataClass_EXP.RED.Control_Law_Enabler.Data;
MPC_trigger_SIM = dataClass_SIM.RED.Control_Law_Enabler.Data;

MPC_start_EXP = find(MPC_trigger_EXP == 3, 1);
MPC_end_EXP = find(MPC_trigger_EXP == 3, 1, 'last');

MPC_start_SIM = find(MPC_trigger_SIM == 3, 1);
MPC_end_SIM = find(MPC_trigger_SIM == 3, 1, 'last');

MPC_step = (round(T_d)/0.05)/8;

idx_EXP = MPC_start_EXP:MPC_step:MPC_end_EXP;
idx_SIM = MPC_start_SIM:MPC_step:MPC_end_SIM;

if length(idx_EXP) >= length(idx_SIM)
    idx_EXP = idx_EXP(1:length(idx_SIM));
else
    idx_SIM = idx_SIM(1:length(idx_EXP));
end

%% Load Experiment Data

RED_Px_EXP = dataClass_EXP.RED.Px_m.Data(idx_EXP,:);
RED_Py_EXP = dataClass_EXP.RED.Py_m.Data(idx_EXP,:);
RED_Rz_EXP = dataClass_EXP.RED.Rz_rad.Data(idx_EXP,:);

BLACK_Px_EXP = dataClass_EXP.BLACK.Px_m.Data(idx_EXP,:);
BLACK_Py_EXP = dataClass_EXP.BLACK.Py_m.Data(idx_EXP,:);
BLACK_Rz_EXP = dataClass_EXP.BLACK.Rz_rad.Data(idx_EXP,:);

RED_Fx_EXP = dataClass_EXP.RED.Fx_N.Data(idx_EXP,:);
RED_Fy_EXP = dataClass_EXP.RED.Fy_N.Data(idx_EXP,:);
RED_Tz_EXP = dataClass_EXP.RED.Tz_Nm.Data(idx_EXP,:);

RED_MPC_Fx_EXP  = dataClass_EXP.MPC.Controls.Data(idx_EXP,1);
RED_MPC_Fy_EXP  = dataClass_EXP.MPC.Controls.Data(idx_EXP,2);

z_EXP = dataClass_EXP.MPC.Optimization_Variable.Data(idx_EXP,:);
zt_EXP = dataClass_EXP.MPC.Target_Trajectory.Data(idx_EXP,:);

r_hold_tar_EXP = dataClass_EXP.MPC.Target_Holding_Radius.Data(idx_EXP,:);

%% Load Simulation Data

RED_Px_SIM = dataClass_SIM.RED.Px_m.Data(idx_SIM,:);
RED_Py_SIM = dataClass_SIM.RED.Py_m.Data(idx_SIM,:);
RED_Rz_SIM = dataClass_SIM.RED.Rz_rad.Data(idx_SIM,:);

BLACK_Px_SIM = dataClass_SIM.BLACK.Px_m.Data(idx_SIM,:);
BLACK_Py_SIM = dataClass_SIM.BLACK.Py_m.Data(idx_SIM,:);
BLACK_Rz_SIM = dataClass_SIM.BLACK.Rz_rad.Data(idx_SIM,:);

RED_Fx_SIM = dataClass_SIM.RED.Fx_N.Data(idx_SIM,:);
RED_Fy_SIM = dataClass_SIM.RED.Fy_N.Data(idx_SIM,:);
RED_Tz_SIM = dataClass_SIM.RED.Tz_Nm.Data(idx_SIM,:);

RED_MPC_Fx_SIM  = dataClass_SIM.MPC.Controls.Data(idx_SIM,1);
RED_MPC_Fy_SIM  = dataClass_SIM.MPC.Controls.Data(idx_SIM,2);

z_SIM = dataClass_SIM.MPC.Optimization_Variable.Data(idx_SIM,:);
zt_SIM = dataClass_SIM.MPC.Target_Trajectory.Data(idx_SIM,:);

r_hold_tar_SIM = dataClass_SIM.MPC.Target_Holding_Radius.Data(idx_SIM,:);

%% Plotting

fig = figure('Color', 'w');

for frame = 1:length(idx_EXP)
    patch([0, xLength, xLength, 0], [0, 0, yLength, yLength], 'black', 'FaceAlpha', 0.08); 
    hold on
    patch([edge_buffer, xLength-edge_buffer, xLength-edge_buffer, edge_buffer], [edge_buffer, edge_buffer, yLength-edge_buffer, yLength-edge_buffer], 'k', 'facealpha', 0, 'LineStyle', '--', 'EdgeColor', [.7 .7 .7]);

    % Plot holding radius
    holding_radius = DrawEllipse(BLACK_Px_SIM(frame), BLACK_Py_SIM(frame), r_hold_tar_SIM(frame,1), r_hold_tar_SIM(frame,2), BLACK_Rz_SIM(frame));
    patch(holding_radius(:,1), holding_radius(:,2), 'k', 'facealpha', 0, 'LineStyle', '--', 'EdgeColor', [.7 .7 .7], 'edgealpha', 0.3)

    holding_radius = DrawEllipse(BLACK_Px_EXP(frame), BLACK_Py_EXP(frame), r_hold_tar_EXP(frame,1), r_hold_tar_EXP(frame,2), BLACK_Rz_EXP(frame));
    patch(holding_radius(:,1), holding_radius(:,2), 'k', 'facealpha', 0, 'LineStyle', '--', 'EdgeColor', [.7 .7 .7])

    % Plotting trajectory
    patchline(RED_Px_SIM(1:frame), RED_Py_SIM(1:frame), 'facecolor', 'r', 'linewidth', 1.2, 'edgealpha', 0.3, 'edgecolor', 'red')
    patchline(BLACK_Px_SIM(1:frame), BLACK_Py_SIM(1:frame), 'facecolor', 'r', 'linewidth', 1.2, 'edgealpha', 0.3)

    plot(RED_Px_EXP(1:frame),RED_Py_EXP(1:frame), 'r-','Linewidth', 1.2);
    plot(BLACK_Px_EXP(1:frame),BLACK_Py_EXP(1:frame), 'k-','Linewidth', 1.2);
    
    % Plotting spacecraft shapes
    spacecraft = DrawSpacecraft([RED_Px_SIM(frame), RED_Py_SIM(frame), RED_Rz_SIM(frame),3]);
    patch(spacecraft(:,1), spacecraft(:,2), 'r', 'facealpha', 0.1, 'linewidth', 0.8, 'edgecolor', 'red', 'edgealpha', 0.3)
    spacecraft = DrawSpacecraft([BLACK_Px_SIM(frame), BLACK_Py_SIM(frame), BLACK_Rz_SIM(frame),7]);
    patch(spacecraft(:,1), spacecraft(:,2), 'k', 'facealpha', 0.1, 'linewidth', 0.8, 'edgealpha', 0.3)

    spacecraft = DrawSpacecraft([RED_Px_EXP(frame),RED_Py_EXP(frame),RED_Rz_EXP(frame),3]);
    patch(spacecraft(:,1), spacecraft(:,2), 'r', 'facealpha', 0.1, 'linewidth', 0.8, 'edgecolor', 'red')
    spacecraft = DrawSpacecraft([BLACK_Px_EXP(frame),BLACK_Py_EXP(frame),BLACK_Rz_EXP(frame),7]);
    patch(spacecraft(:,1), spacecraft(:,2), 'k', 'facealpha', 0.1, 'linewidth', 0.8)

    % Plotting MPC trajectories
    patchline(z_SIM(frame,4:9:9*N_h), z_SIM(frame,5:9:9*N_h), 'edgecolor', 'b', 'LineStyle', '--', 'LineWidth', 0.5, 'edgealpha', 0.3);
    plot(z_EXP(frame,4:9:9*N_h), z_EXP(frame,5:9:9*N_h), 'b--', 'LineWidth', 0.5);

    grid on
    box on
    axis equal;

    set(gca, 'FontName', 'Times New Roman', 'FontSize', 10)

    xlim([-0.2 xLength+0.2]);
    ylim([-0.2 yLength+0.2]);

    xlabel('X-Position [m]');
    ylabel('Y-Position [m]');

    movieVector(frame) = getframe(gcf);

    clf
end

close(gcf)

myWriter = VideoWriter(strcat(EXP_DIR, '\', 'animation'), 'MPEG-4');
myWriter.FrameRate = 10;
open(myWriter);

for i=1:length(movieVector)
    writeVideo(myWriter, movieVector(i));
end
close(myWriter);

imwrite(movieVector(end).cdata, strcat(EXP_DIR, '\', 'snapshot.png'));

%% Functions

function [x_plus, y_plus, x_minus, y_minus] = calculateLineEndpoints(x1, y1, x2, y2, angle, lineLength)
    % Compute the angle of the line connecting (x1, y1) and (x2, y2)
    theta = atan2(y2 - y1, x2 - x1);

    % Angles for the new lines
    theta_plus = theta + angle;  % +angle degrees
    theta_minus = theta - angle; % -angle degrees

    % Compute end points of the new lines
    x_plus = x2 + lineLength * cos(theta_plus);
    y_plus = y2 + lineLength * sin(theta_plus);

    x_minus = x2 + lineLength * cos(theta_minus);
    y_minus = y2 + lineLength * sin(theta_minus);
end