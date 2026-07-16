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

idx = DATA_STARTTIME:DATA_STEP:DATA_ENDTIME;

time = dataClass_rt.Time_s.Data(idx,:);

RED_Px = dataClass_rt.RED.Px_m.Data(idx,:);
RED_Py = dataClass_rt.RED.Py_m.Data(idx,:);
RED_Rz = dataClass_rt.RED.Rz_rad.Data(idx,:);

BLACK_Px = dataClass_rt.BLACK.Px_m.Data(idx,:);
BLACK_Py = dataClass_rt.BLACK.Py_m.Data(idx,:);
BLACK_Rz = dataClass_rt.BLACK.Rz_rad.Data(idx,:);

RED_Fx = dataClass_rt.RED.Fx_N.Data(idx,:);
RED_Fy = dataClass_rt.RED.Fy_N.Data(idx,:);
RED_Tz = dataClass_rt.RED.Tz_Nm.Data(idx,:);

RED_MPC_Fx  = dataClass_rt.MPC.Controls.Data(idx,1);
RED_MPC_Fy  = dataClass_rt.MPC.Controls.Data(idx,2);

z = dataClass_rt.MPC.Optimization_Variable.Data(idx,:);
z_t = dataClass_rt.MPC.Target_Trajectory.Data(idx,:);

r_hold_tar = dataClass_rt.MPC.Target_Holding_Radius.Data(idx,:);

%% Plotting

fig = figure('Color', 'w');

for frame = 1:length(time)
    patch([0, xLength, xLength, 0], [0, 0, yLength, yLength], 'black', 'FaceAlpha', 0.08); 
    hold on
    patch([edge_buffer, xLength-edge_buffer, xLength-edge_buffer, edge_buffer], [edge_buffer, edge_buffer, yLength-edge_buffer, yLength-edge_buffer], 'k', 'facealpha', 0, 'LineStyle', '--', 'EdgeColor', [.7 .7 .7]);

    holding_radius = DrawEllipse(BLACK_Px(frame), BLACK_Py(frame), r_hold_tar(frame,1), r_hold_tar(frame,2), BLACK_Rz(frame));
    patch(holding_radius(:,1), holding_radius(:,2), 'k', 'facealpha', 0, 'LineStyle', '--', 'EdgeColor', [.7 .7 .7])

    % Plotting trajectory
    plot(RED_Px(1:frame),RED_Py(1:frame), 'r-','Linewidth',1.2);
    plot(BLACK_Px(1:frame),BLACK_Py(1:frame), 'k-','Linewidth',1.2);
    
    % Plotting spacecraft shapes
    spacecraft = DrawSpacecraft([RED_Px(frame),RED_Py(frame),RED_Rz(frame),9]);
    patch(spacecraft(:,1), spacecraft(:,2), 'r', 'facealpha', 0.1, 'linewidth', 0.8, 'edgecolor', 'red')

    spacecraft = DrawSpacecraft([BLACK_Px(frame),BLACK_Py(frame),BLACK_Rz(frame),10]);
    patch(spacecraft(:,1), spacecraft(:,2), 'k', 'facealpha', 0.1, 'linewidth', 0.8)

    % Plotting MPC trajectories
    plot(z(frame,4:9:9*N_h), z(frame,5:9:9*N_h), 'b--', 'LineWidth', 0.5);
    plot(z_t(frame,4), z_t(frame,5), 'k*')

    % Plotting force vector
    quiver(RED_Px(frame), RED_Py(frame), RED_Fx(frame), RED_Fy(frame), 'b', 'AutoScale','off', 'MaxHeadSize', 5, 'LineWidth', 1)

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

myWriter = VideoWriter(strcat(MAT_DIR, '\', 'animation'), 'MPEG-4');
myWriter.FrameRate = 10;
open(myWriter);
for i=1:length(movieVector)
    writeVideo(myWriter, movieVector(i));
end
close(myWriter);

imwrite(movieVector(end).cdata, strcat(MAT_DIR, '\', 'snapshot.png'));
