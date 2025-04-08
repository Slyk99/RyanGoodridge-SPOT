clc
clear all
close all

% Adding parent directory to the path, which contains the plotting functions
parentDirectory = fileparts(cd);
addpath(parentDirectory)          
addpath("functions")

%% Constants

yLength = 2.4;
xLength = 3.5;

baseRate = 0.05;

fullSendOffset = 150;

%% Select Data File

[MAT_FILES, MAT_DIR] = uigetfile('*', 'Select the MAT file', '../Saved Data/', 'MultiSelect', 'on');

MAT_FILEPATHS = fullfile(MAT_DIR, MAT_FILES);

%% Load Data

dataClass_rt = {};
idx = {};

for j = 1:numel(MAT_FILEPATHS)
   dataClass_rt{j} = load(MAT_FILEPATHS{j}).dataClass_rt;
   idx{j} = getIdx(dataClass_rt{j});
end

maxSize = max(cellfun(@numel, idx));

%% Impulse & Computation Time

impulse = {};
computation_time = {};
for j = 1:numel(dataClass_rt)
    RED_Fx = dataClass_rt{j}.MPC.Controls.Data(idx{j},1);
    RED_Fy = dataClass_rt{j}.MPC.Controls.Data(idx{j},2);
    RED_Tz = dataClass_rt{j}.MPC.Controls.Data(idx{j},3);

    computation_time{j} = dataClass_rt{j}.MPC.Solver_Result.Data(idx{j}, 3);
    impulse{j} = (abs(RED_Fx) + abs(RED_Fy) + abs(RED_Tz)*0.15)*baseRate;
end

RED_Imp_mean = zeros(maxSize,1);
RED_Imp_var = zeros(maxSize,1);

RED_CT_mean = zeros(maxSize,1);
RED_CT_var = zeros(maxSize,1);

RED_Px_mean = zeros(maxSize,1);
RED_Py_mean = zeros(maxSize,1);
RED_Rz_mean = zeros(maxSize,1);

RED_Px_var = zeros(maxSize,1);
RED_Py_var = zeros(maxSize,1);
RED_Rz_var = zeros(maxSize,1);

for i = 1:maxSize
    RED_Imp_sum = 0;
    RED_Imp_ssd = 0;

    RED_CT_sum = 0;
    RED_CT_ssd = 0;

    RED_Px_sum = 0;
    RED_Py_sum = 0;
    RED_Rz_sum = 0;

    RED_Px_ssd = 0;
    RED_Py_ssd = 0;
    RED_Rz_ssd = 0;

    counter = 0;
    for j = 1:numel(idx)
        if i <= length(idx{j})
            RED_Imp_sum = RED_Imp_sum + impulse{j}(i);
            RED_CT_sum = RED_CT_sum + computation_time{j}(i);

            RED_Px_sum = RED_Px_sum + dataClass_rt{j}.RED.Px_m.Data(idx{j}(i));
            RED_Py_sum = RED_Py_sum + dataClass_rt{j}.RED.Py_m.Data(idx{j}(i));
            RED_Rz_sum = RED_Rz_sum + dataClass_rt{j}.RED.Rz_rad.Data(idx{j}(i));

            counter = counter + 1;
        end
    end

    RED_Imp_mean(i) = RED_Imp_sum/counter;
    RED_CT_mean(i) = RED_CT_sum/counter;

    RED_Px_mean(i) = RED_Px_sum/counter;
    RED_Py_mean(i) = RED_Py_sum/counter;
    RED_Rz_mean(i) = RED_Rz_sum/counter;

    counter = 0;
    for j = 1:numel(idx)
        if i <= length(idx{j})
            RED_Imp_ssd = RED_Imp_ssd + (impulse{j}(i) - RED_Imp_mean(i))^2;
            RED_CT_ssd = RED_CT_ssd + (computation_time{j}(i) - RED_CT_mean(i))^2;

            RED_Px_ssd = RED_Px_ssd + (dataClass_rt{j}.RED.Px_m.Data(idx{j}(i)) - RED_Px_mean(i))^2;
            RED_Py_ssd = RED_Py_ssd + (dataClass_rt{j}.RED.Py_m.Data(idx{j}(i)) - RED_Py_mean(i))^2;
            RED_Rz_ssd = RED_Rz_ssd + (dataClass_rt{j}.RED.Rz_rad.Data(idx{j}(i)) - RED_Rz_mean(i))^2;

            counter = counter + 1;
        end
    end

    RED_Imp_var(i) = RED_Imp_ssd/counter;
    RED_CT_var(i) = RED_CT_ssd/counter;

    RED_Px_var(i) = RED_Px_ssd/counter;
    RED_Py_var(i) = RED_Py_ssd/counter;
    RED_Rz_var(i) = RED_Rz_ssd/counter;
end

avgTotalImpulse = 0;
avgComputationTime = 0;
for j = 1:numel(dataClass_rt)
    avgComputationTime = avgComputationTime + (mean(computation_time{j})-avgComputationTime)/j;
    avgTotalImpulse = avgTotalImpulse + (sum(impulse{j})-avgTotalImpulse)/j;
end

%% Create Path Plot & Trial data

figure
tiledlayout(3, 2, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile([3, 1])
hold on
for j = 1:numel(idx)
    idx_j = [idx{j} idx{j}(end)+1:idx{j}(end)+fullSendOffset];

    RED_Px = dataClass_rt{j}.RED.Px_m.Data;
    RED_Py = dataClass_rt{j}.RED.Py_m.Data;
    RED_Rz = dataClass_rt{j}.RED.Rz_rad.Data;
    BLACK_Px = dataClass_rt{j}.BLACK.Px_m.Data;
    BLACK_Py = dataClass_rt{j}.BLACK.Py_m.Data;
    BLACK_Rz = dataClass_rt{j}.BLACK.Rz_rad.Data;

    patchline(RED_Px(idx_j), RED_Py(idx_j), 'facecolor', 'r', 'linewidth', 1, 'edgecolor', 'red');
    patchline(BLACK_Px(idx_j), BLACK_Py(idx_j), 'facecolor', 'k', 'linewidth', 1)
    
    spacecraft = DrawSpacecraft([RED_Px(idx_j(end)),RED_Py(idx_j(end)),RED_Rz(idx_j(end)), 9]);
    patch(spacecraft(:,1), spacecraft(:,2), 'r', 'facealpha', 0, 'linewidth', 0.5, 'edgecolor', 'red')
    
    spacecraft = DrawSpacecraft([BLACK_Px(idx_j(end)), BLACK_Py(idx_j(end)), BLACK_Rz(idx_j(end)), 10]);
    patch(spacecraft(:,1), spacecraft(:,2), 'k', 'facealpha', 0, 'linewidth', 0.5)
end

grid on
box on
axis equal;

xlim([0 xLength]);
ylim([0 yLength]);

xlabel('X-Position [m]')
ylabel('Y-Position [m]')

set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
hold off

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', RED_Px_mean, 'k', 'DisplayName', 'Mean');
hold on
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [RED_Px_mean+3*sqrt(RED_Px_var); fliplr((RED_Px_mean-3*sqrt(RED_Px_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
grid on
ylabel('{\it x}_s [m]')
xlim([0 (maxSize-1)*baseRate])
ylim([0 3.5])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
legend

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', RED_Py_mean, 'k')
hold on
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [RED_Py_mean+3*sqrt(RED_Py_var); fliplr((RED_Py_mean-3*sqrt(RED_Py_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
grid on
ylabel('{\it y}_s [m]')
xlim([0 (maxSize-1)*baseRate])
ylim([0 2.5])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', RED_Rz_mean, 'k')
hold on
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [RED_Rz_mean+3*sqrt(RED_Rz_var); fliplr((RED_Rz_mean-3*sqrt(RED_Rz_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
grid on
ylabel('\theta_s [rad]')
xlabel('Time [s]')
xlim([0 (maxSize-1)*baseRate])
ylim([-3 1])
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)

set(gcf, 'Position', [gcf().Position(1:2), 1260, 420]);
set(gcf,'PaperOrientation','landscape');
set(gcf, 'PaperSize',[18 8.5]);

%% Functions

function idx = getIdx(dataClass_rt)
    MPC_trigger = dataClass_rt.RED.Control_Law_Enabler.Data;

    MPC_start = find(MPC_trigger == 3, 1);
    MPC_end = find(MPC_trigger == 3, 1, 'last');

    idx = MPC_start:MPC_end;
end