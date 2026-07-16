function plotCovariance(t, mu, P, idx, alpha, color)
% PLOTSTATEWITHCOVARIANCE
%   Plots the mean state with ±3σ covariance shading.
%
% Inputs:
%   t     - time vector (1×T)
%   mu    - mean vector for this state (1×T)
%   P     - covariance matrix (n×n×T)
%   idx   - index of the state to plot (1…n)
%   alpha - transparency for shaded area
%   color - 3×1 RGB or MATLAB color char (for mean + shading)

    % --- Extract variance of desired state ---
    var_x = squeeze(P(idx, idx, :))';   % (1×T)
    sig_x = sqrt(var_x);                % standard deviation

    upper = mu + 3*sig_x;
    lower = mu - 3*sig_x;

    % --- Plot shaded 3σ region ---
    hold on
    fill([t fliplr(t)], [upper fliplr(lower)], color, ...
         'FaceAlpha', alpha, 'EdgeColor', 'none');

    % --- Plot mean ---
    % plot(t, mu, 'Color', color, 'LineWidth', 2);

    % --- Formatting ---
    grid on
    set(gca, 'FontName', 'Times New Roman', 'FontSize', 12)
    xlabel('$t$ [s]', 'Interpreter', 'latex', 'FontSize', 12)
    ylabel(sprintf('$x_{%d}$', idx), 'Interpreter', 'latex', 'FontSize', 12)
end
