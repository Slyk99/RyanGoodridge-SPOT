function plot3SigmaBounds(x, P, idx, color, faceAlpha)
% plot3SigmaBounds - Plots ±3σ bounds from covariance
% Inputs:
%   x         - vector (e.g., time or frame index)
%   P         - covariance: scalar, vector, or 3D array (N×N×T)
%   idx       - index to extract the variance from if P is a matrix
%   color     - RGB triplet or color char
%   faceAlpha - optional, default 0.1

    if nargin < 5
        faceAlpha = 0.1;
    end
    
    % Extract variance
    if isvector(P)
        sigma = sqrt(P(:));
    elseif ismatrix(P) && size(P,1) == size(P,2)
        sigma = sqrt(P(idx,idx));  % single covariance matrix
    elseif ndims(P) == 3
        T = size(P,3);
        sigma = zeros(1,T);
        for t = 1:T
            sigma(t) = sqrt(P(idx,idx,t));
        end
    else
        error('P must be a vector, square matrix, or 3D array');
    end

    x = x(:);
    sigma = sigma(:);
    upper = 3 * sigma;
    lower = -3 * sigma;

    % Plot shaded area
    hold on;
    fill([x; flipud(x)], [upper; flipud(lower)], ...
        color, 'FaceAlpha', faceAlpha, 'EdgeColor', 'none');
    
    % Optional: plot boundaries
    plot(x, upper, '-', 'Color', color, 'LineWidth', 0.5);
    plot(x, lower, '-', 'Color', color, 'LineWidth', 0.5);
end