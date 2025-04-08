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

%% Select Data File

[MAT_FILES, MAT_DIR] = uigetfile('*', 'Select the MAT file', '../Saved Data/', 'MultiSelect', 'on');

MAT_FILEPATHS = fullfile(MAT_DIR, MAT_FILES);

%% Load Data

dataClass_rt = {};
exp_idx = {};

startTime = 1e6;
endTime = -1;

for j = 1:numel(MAT_FILEPATHS)
   dataClass_rt{j} = load(MAT_FILEPATHS{j}).dataClass_rt;
   exp_idx{j} = getIdx(dataClass_rt{j});

   startTime_j = dataClass_rt{j}.Time_s.Data(exp_idx{j}(1));
   endTime_j = dataClass_rt{j}.Time_s.Data(exp_idx{j}(end));

   if startTime_j < startTime
       startTime = startTime_j;
   end

   if endTime_j > endTime
       endTime = endTime_j;
   end
end

time_idx = {};
for j = 1:numel(dataClass_rt)
    start_idx = find(dataClass_rt{j}.Time_s.Data == startTime);
    end_idx = find(dataClass_rt{j}.Time_s.Data == endTime);

    time_idx{j} = start_idx:end_idx;
end

maxSize = length(time_idx{1});

%% Process Data

for j = 1:numel(dataClass_rt)
    zeroIdx = (dataClass_rt{j}.VIS.BLACK_Measurements.Data(exp_idx{j},1) == 0);

    for i = 1:3
        data = dataClass_rt{j}.VIS.BLACK_States.Data(exp_idx{j},i);
        dataClass_rt{j}.VIS.BLACK_States.Data(exp_idx{j}(zeroIdx),i) = interp1(find(~zeroIdx),data(~zeroIdx,:),find(zeroIdx), 'linear', 'extrap');
    end
end

BLACK_Px_PS_mean = zeros(maxSize,1);
BLACK_Py_PS_mean = zeros(maxSize,1);
BLACK_Rz_PS_mean = zeros(maxSize,1);

for i = 1:maxSize
    BLACK_Px_PS_sum = 0;
    BLACK_Py_PS_sum = 0;
    BLACK_Rz_PS_sum = 0;

    counter = 0;
    for j = 1:numel(dataClass_rt)
        BLACK_PS = [dataClass_rt{j}.BLACK.Px_m.Data(time_idx{j}(i),:), dataClass_rt{j}.BLACK.Py_m.Data(time_idx{j}(i),:), dataClass_rt{j}.BLACK.Rz_rad.Data(time_idx{j}(i),:)];

        BLACK_Px_PS_sum = BLACK_Px_PS_sum + BLACK_PS(1);
        BLACK_Py_PS_sum = BLACK_Py_PS_sum + BLACK_PS(2);
        BLACK_Rz_PS_sum = BLACK_Rz_PS_sum + BLACK_PS(3);

        counter = counter + 1;
    end

    BLACK_Px_PS_mean(i) = BLACK_Px_PS_sum/counter;
    BLACK_Py_PS_mean(i) = BLACK_Py_PS_sum/counter;
    BLACK_Rz_PS_mean(i) = BLACK_Rz_PS_sum/counter;
end

BLACK_Px_Vis_mean = zeros(maxSize,1);
BLACK_Py_Vis_mean = zeros(maxSize,1);
BLACK_Rz_Vis_mean = zeros(maxSize,1);

BLACK_Px_UKF_mean = zeros(maxSize,1);
BLACK_Py_UKF_mean = zeros(maxSize,1);
BLACK_Rz_UKF_mean = zeros(maxSize,1);

BLACK_Px_Vis_var = zeros(maxSize,1);
BLACK_Py_Vis_var = zeros(maxSize,1);
BLACK_Rz_Vis_var = zeros(maxSize,1);

BLACK_Px_UKF_var = zeros(maxSize,1);
BLACK_Py_UKF_var = zeros(maxSize,1);
BLACK_Rz_UKF_var = zeros(maxSize,1);

for i = 1:maxSize
    BLACK_Px_Vis_sum = 0;
    BLACK_Py_Vis_sum = 0;
    BLACK_Rz_Vis_sum = 0;

    BLACK_Px_UKF_sum = 0;
    BLACK_Py_UKF_sum = 0;
    BLACK_Rz_UKF_sum = 0;

    BLACK_Px_Vis_ssd = 0;
    BLACK_Py_Vis_ssd = 0;
    BLACK_Rz_Vis_ssd = 0;

    BLACK_Px_UKF_ssd = 0;
    BLACK_Py_UKF_ssd = 0;
    BLACK_Rz_UKF_ssd = 0;

    counter = 0;
    for j = 1:numel(dataClass_rt)
        ii = time_idx{j}(i);

        if any(exp_idx{j} == ii)
            BLACK_Vis = dataClass_rt{j}.VIS.BLACK_States.Data(ii,:);
            BLACK_UKF = dataClass_rt{j}.UKF.BLACK_Estimated_States.Data(ii,:);

            BLACK_Px_Vis_sum = BLACK_Px_Vis_sum + BLACK_Vis(1);
            BLACK_Py_Vis_sum = BLACK_Py_Vis_sum + BLACK_Vis(2);
            BLACK_Rz_Vis_sum = BLACK_Rz_Vis_sum + BLACK_Vis(3);

            BLACK_Px_UKF_sum = BLACK_Px_UKF_sum + BLACK_UKF(1);
            BLACK_Py_UKF_sum = BLACK_Py_UKF_sum + BLACK_UKF(2);
            BLACK_Rz_UKF_sum = BLACK_Rz_UKF_sum + BLACK_UKF(3);

            counter = counter + 1;
        end
    end

    BLACK_Px_Vis_mean(i) = BLACK_Px_Vis_sum/counter;
    BLACK_Py_Vis_mean(i) = BLACK_Py_Vis_sum/counter;
    BLACK_Rz_Vis_mean(i) = BLACK_Rz_Vis_sum/counter;


    BLACK_Px_UKF_mean(i) = BLACK_Px_UKF_sum/counter;
    BLACK_Py_UKF_mean(i) = BLACK_Py_UKF_sum/counter;
    BLACK_Rz_UKF_mean(i) = BLACK_Rz_UKF_sum/counter;

    counter = 0;
    for j = 1:numel(dataClass_rt)
        ii = time_idx{j}(i);

        if any(exp_idx{j} == ii)
            BLACK_Vis = dataClass_rt{j}.VIS.BLACK_States.Data(ii,:);
            BLACK_UKF = dataClass_rt{j}.UKF.BLACK_Estimated_States.Data(ii,:);

            BLACK_Px_Vis_ssd = BLACK_Px_Vis_ssd + (BLACK_Vis(1) - BLACK_Px_Vis_mean(i))^2;
            BLACK_Py_Vis_ssd = BLACK_Py_Vis_ssd + (BLACK_Vis(2) - BLACK_Py_Vis_mean(i))^2;
            BLACK_Rz_Vis_ssd = BLACK_Rz_Vis_ssd + (BLACK_Vis(3) - BLACK_Rz_Vis_mean(i))^2;

            BLACK_Px_UKF_ssd = BLACK_Px_UKF_ssd + (BLACK_UKF(1) - BLACK_Px_UKF_mean(i))^2;
            BLACK_Py_UKF_ssd = BLACK_Py_UKF_ssd + (BLACK_UKF(2) - BLACK_Py_UKF_mean(i))^2;
            BLACK_Rz_UKF_ssd = BLACK_Rz_UKF_ssd + (BLACK_UKF(3) - BLACK_Rz_UKF_mean(i))^2;

            counter = counter + 1;
        end
    end

    if counter == 1
        counter = 2;
    end

    BLACK_Px_Vis_var(i) = BLACK_Px_Vis_ssd/counter;
    BLACK_Py_Vis_var(i) = BLACK_Py_Vis_ssd/counter;
    BLACK_Rz_Vis_var(i) = BLACK_Rz_Vis_ssd/counter;

    BLACK_Px_UKF_var(i) = BLACK_Px_UKF_ssd/counter;
    BLACK_Py_UKF_var(i) = BLACK_Py_UKF_ssd/counter;
    BLACK_Rz_UKF_var(i) = BLACK_Rz_UKF_ssd/counter;
end

RMSE_UKF_Px = 0;
RMSE_UKF_Py = 0;
RMSE_UKF_Rz = 0;

for j = 1:numel(dataClass_rt)
    sum_err_Px_sqr = 0;
    sum_err_Py_sqr = 0;
    sum_err_Rz_sqr = 0;

    for i = 1:length(exp_idx{j})
        id = exp_idx{j}(i);

        sum_err_Px_sqr = sum_err_Px_sqr + (dataClass_rt{j}.UKF.BLACK_Estimated_States.Data(id,1) - dataClass_rt{j}.BLACK.Px_m.Data(id))^2;
        sum_err_Py_sqr = sum_err_Py_sqr + (dataClass_rt{j}.UKF.BLACK_Estimated_States.Data(id,2) - dataClass_rt{j}.BLACK.Py_m.Data(id))^2;
        sum_err_Rz_sqr = sum_err_Rz_sqr + (dataClass_rt{j}.UKF.BLACK_Estimated_States.Data(id,3) - dataClass_rt{j}.BLACK.Rz_rad.Data(id))^2;

    end

    RMSE_UKF_Px = RMSE_UKF_Px + (sqrt(sum_err_Px_sqr/length(exp_idx{j})) - RMSE_UKF_Px)/j;
    RMSE_UKF_Py = RMSE_UKF_Py + (sqrt(sum_err_Py_sqr/length(exp_idx{j})) - RMSE_UKF_Py)/j;
    RMSE_UKF_Rz = RMSE_UKF_Rz + (sqrt(sum_err_Rz_sqr/length(exp_idx{j})) - RMSE_UKF_Rz)/j;
end

%% Trial data (Vision)

figure
tiledlayout(3, 1, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_Vis_mean, 'k', 'DisplayName', 'Mean');
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Px_Vis_mean+3*sqrt(BLACK_Px_Vis_var); fliplr((BLACK_Px_Vis_mean-3*sqrt(BLACK_Px_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_Vis_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('X-Position [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([1 2.5])
legend('Location', 'northeast', 'NumColumns', 3)

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_Vis_mean, 'k', 'DisplayName', 'Mean')
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Py_Vis_mean+3*sqrt(BLACK_Py_Vis_var); fliplr((BLACK_Py_Vis_mean-3*sqrt(BLACK_Py_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_Vis_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('Y-Position [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([0.5 1.5])

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_Vis_mean, 'k', 'DisplayName', 'Mean')
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Rz_Vis_mean+3*sqrt(BLACK_Rz_Vis_var); fliplr((BLACK_Rz_Vis_mean-3*sqrt(BLACK_Rz_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_Vis_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('Attitude [rad]')
xlabel('Time [s]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([-2 2.5])

%% Trial data (UKF)

figure
tiledlayout(3, 1, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_UKF_mean, 'k', 'DisplayName', 'Mean');
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Px_UKF_mean+3*sqrt(BLACK_Px_UKF_var); fliplr((BLACK_Px_UKF_mean-3*sqrt(BLACK_Px_UKF_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_UKF_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('X-Position [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([1 2.5])
legend('Location', 'northeast', 'NumColumns', 3)

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_UKF_mean, 'k', 'DisplayName', 'Mean')
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Py_UKF_mean+3*sqrt(BLACK_Py_UKF_var); fliplr((BLACK_Py_UKF_mean-3*sqrt(BLACK_Py_UKF_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_UKF_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('Y-Position [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([0.5 1.5])

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_UKF_mean, 'k', 'DisplayName', 'Mean')
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_PS_mean, 'k--', 'DisplayName', 'Ground Truth')
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Rz_UKF_mean+3*sqrt(BLACK_Rz_UKF_var); fliplr((BLACK_Rz_UKF_mean-3*sqrt(BLACK_Rz_UKF_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits');
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_UKF_mean, 'k', 'HandleVisibility', 'off');
grid on
ylabel('Attitude [rad]')
xlabel('Time [s]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([-2 2.5])

%% Trial data (Vision & UKF)

figure
tiledlayout(3, 1, 'TileSpacing', 'compact', 'Padding', 'compact');

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_Vis_mean, 'r', 'DisplayName', 'Mean (Vision)');
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_UKF_mean, 'b', 'DisplayName', 'Mean (UKF)');
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Px_Vis_mean+3*sqrt(BLACK_Px_Vis_var); fliplr((BLACK_Px_Vis_mean-3*sqrt(BLACK_Px_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (Vision)');
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Px_UKF_mean+3*sqrt(BLACK_Px_UKF_var); fliplr((BLACK_Px_UKF_mean-3*sqrt(BLACK_Px_UKF_var))')'], ...
     'b', 'FaceAlpha', 0.1, 'EdgeColor', 'b', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (UKF)');

plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Px_PS_mean, 'k', 'DisplayName', 'Ground Truth')
grid on
ylabel('{\it x}_c [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([1 2.5])
legend('Location', 'northoutside', 'NumColumns', 3)

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_Vis_mean, 'r', 'DisplayName', 'Mean (Vision)');
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_UKF_mean, 'b', 'DisplayName', 'Mean (UKF)');

fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Py_Vis_mean+3*sqrt(BLACK_Py_Vis_var); fliplr((BLACK_Py_Vis_mean-3*sqrt(BLACK_Py_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (Vision)');
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Py_UKF_mean+3*sqrt(BLACK_Py_UKF_var); fliplr((BLACK_Py_UKF_mean-3*sqrt(BLACK_Py_UKF_var))')'], ...
     'b', 'FaceAlpha', 0.1, 'EdgeColor', 'b', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (UKF)');

plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Py_PS_mean, 'k', 'DisplayName', 'Ground Truth')

grid on
ylabel('{\it y}_c [m]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([0.5 1.5])

nexttile
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_Vis_mean, 'r', 'DisplayName', 'Mean (Vision)');
hold on
plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_UKF_mean, 'b', 'DisplayName', 'Mean (UKF)');

fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Rz_Vis_mean+3*sqrt(BLACK_Rz_Vis_var); fliplr((BLACK_Rz_Vis_mean-3*sqrt(BLACK_Rz_Vis_var))')'], ...
     'r', 'FaceAlpha', 0.1, 'EdgeColor', 'r', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (Vision)');
fill([(0:baseRate:(maxSize-1)*baseRate)'; fliplr((0:baseRate:(maxSize-1)*baseRate))'], ...
     [BLACK_Rz_UKF_mean+3*sqrt(BLACK_Rz_UKF_var); fliplr((BLACK_Rz_UKF_mean-3*sqrt(BLACK_Rz_UKF_var))')'], ...
     'b', 'FaceAlpha', 0.1, 'EdgeColor', 'b', 'LineStyle', '--', 'DisplayName', '3\sigma Limits (UKF)');

plot((0:baseRate:(maxSize-1)*baseRate)', BLACK_Rz_PS_mean, 'k', 'DisplayName', 'Ground Truth')

grid on
ylabel('\theta_c [rad]')
xlabel('Time [s]')
set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
xlim([0 (maxSize-1)*baseRate])
ylim([-2 2.5])

%% Functions

function idx = getIdx(dataClass_rt)
    MPC_trigger = dataClass_rt.RED.Control_Law_Enabler.Data;

    MPC_start = find(MPC_trigger == 3, 1);
    MPC_end = find(MPC_trigger == 3, 1, 'last');

    idx = MPC_start:MPC_end;
end