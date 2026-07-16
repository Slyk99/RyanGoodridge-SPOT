try
    spotFilterData = spotKF.PostProcessing.FilterData(dataClass, navOpts);
catch
    spotFilterData = spotKF.PostProcessing.genFilterData(dataClass_rt, navOpts);
end

% set(0,'DefaultFigureWindowStyle','docked')
set(0,'DefaultFigureWindowStyle','normal')

t = spotFilterData.Time.t;

%% Figure 1 (x, y, theta vs time)

state_est  = spotFilterData.estimated_States.BLACK;
state_smth = spotFilterData.smoothed_States.BLACK;
state_meas = spotFilterData.measurements.BLACK;
state_pred = spotFilterData.predicted_States.BLACK;
P          = spotFilterData.estimated_Cov.BLACK;

state_est(3,:) = wrapTo2Pi(state_est(3,:));
state_smth(3,:) = wrapTo2Pi(state_smth(3,:));
state_meas(3,:) = wrapTo2Pi(state_meas(3,:));
state_pred(3,:) = wrapTo2Pi(state_pred(3,:));
LW = 2;

figure('Name', 'Position')

for i = 1:3
    subplot(3,1,i)
    hold on

    % Plot covariance region for the estimate
    spotKF.PostProcessing.Plots.plotCovariance(t, state_est(i,:), P, i, 0.2, [1 0 0]); % light red shade

    plot(t, state_pred(i,:),  'go', 'LineWidth', LW, 'MarkerFaceColor', 'g', 'MarkerSize', 2)
    % plot(t, state_smth(i,:),  'm', 'LineWidth', LW)

    % Plot measurement (ground truth)
    plot(t, state_meas(i,:), 'k', 'LineWidth', LW)

    % Plot State
    plot(t, state_est(i,:), 'r', 'LineWidth', LW)

    if i == 2
        legend({'3σ bound', 'Estimate', 'Measurement'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end


figure('Name','State Errors')

for i = 1:3
    subplot(3,1,i)
    hold on

    % Compute error: estimate minus measurement
    err = state_est(i,:) - state_meas(i,:);

    % Plot 3σ bounds around zero (mu = 0)
    zero_line = zeros(size(t));
    spotKF.PostProcessing.Plots.plotCovariance(t, zero_line, P, i, 0.2, [1 0 0]); % red shade

    % Plot error line
    plot(t, err, 'r', 'LineWidth', 2)

    % Axis / labels
    grid on
    set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
    ylabel(sprintf('$e_{%d}$', i), 'Interpreter','latex', 'FontSize', 12)

    if i == 3
        xlabel('$t$ [s]', 'Interpreter','latex', 'FontSize', 12)
    end

    if i == 2
        legend({'3σ Bounds','Error'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end

figure('Name', 'Velocitys')

for i = 1:3
    j = i+3;
    subplot(3,1,i)
    hold on

    % Plot covariance region for the estimate
    spotKF.PostProcessing.Plots.plotCovariance(t, state_est(j,:), P, j, 0.2, [1 0 0]); % light red shade

    plot(t, state_pred(j,:),  'go', 'LineWidth', LW, 'MarkerFaceColor', 'g', 'MarkerSize', 2)
    plot(t, state_smth(i+3,:),  'm', 'LineWidth', LW)

    % Plot measurement (ground truth)
    plot(t, state_meas(j,:), 'k', 'LineWidth', LW)

    % Plot State
    plot(t, state_est(j,:), 'r', 'LineWidth', LW)

    if i == 2
        legend({'3σ bound', 'Estimate', 'Measurement'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end


figure('Name','State Errors')

for i = 1:3
    j = i+3;
    subplot(3,1,i)
    hold on

    % Compute error: estimate minus measurement
    err = state_est(j,:) - state_meas(j,:);

    % Plot 3σ bounds around zero (mu = 0)
    zero_line = zeros(size(t));
    spotKF.PostProcessing.Plots.plotCovariance(t, zero_line, P, j, 0.2, [1 0 0]); % red shade

    % Plot error line
    plot(t, err, 'r', 'LineWidth', 2)

    % Axis / labels
    grid on
    set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
    ylabel(sprintf('$e_{%d}$', i), 'Interpreter','latex', 'FontSize', 12)

    if i == 3
        xlabel('$t$ [s]', 'Interpreter','latex', 'FontSize', 12)
    end

    if i == 2
        legend({'3σ Bounds','Error'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end

figure('Name', 'Accelerations')
for i = 1:3
    j = i+6;
    subplot(3,1,i)
    hold on

    % plot(t, state_pred(j,:),  'go', 'LineWidth', LW, 'MarkerFaceColor', 'g', 'MarkerSize', 2)
    % plot(t, state_smth(i+3,:),  'm', 'LineWidth', LW)

    a = diff(state_est(i+3,:))./diff(t);
    plot(t(2:end), a,  'go', 'LineWidth', LW, 'MarkerFaceColor', 'g', 'MarkerSize', 2)

    % Plot measurement (ground truth)
    plot(t, state_meas(j,:), 'k', 'LineWidth', LW)

    % Plot State
    plot(t, state_est(j,:), 'r', 'LineWidth', LW)

    if i == 2
        legend({'3σ bound', 'Estimate', 'Measurement'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end


figure('Name','State Errors')

for i = 1:3
    j = i+6;
    subplot(3,1,i)
    hold on

    % Compute error: estimate minus measurement
    err = state_est(j,:) - state_meas(j,:);

    % Plot error line
    plot(t, err, 'r', 'LineWidth', 2)

    % Axis / labels
    grid on
    set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
    ylabel(sprintf('$e_{%d}$', i), 'Interpreter','latex', 'FontSize', 12)

    if i == 3
        xlabel('$t$ [s]', 'Interpreter','latex', 'FontSize', 12)
    end

    if i == 2
        legend({'3σ Bounds','Error'}, 'Interpreter','latex')
    end
    ylim tight;
    hold off
end