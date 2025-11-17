% Ryan Goodridge
% Copyright (C) 2024
%
% Description: 
% This function performs the Rauch-Tung-Striebel (RTS) smoothing step for 
% an Extended Kalman Filter (EKF). It uses backward recursion to smooth 
% the state estimates and covariances over the provided time steps, given 
% the predicted states, covariances, and a state propagation function.
%
% Inputs:
%   dt_data   - Time step data (1 by t)
%   x_data    - State estimate data (n by t)
%   P_data    - State estimate covariance (n by n by t)
%   xk_data   - Predicted state for the next time step (n by t)
%   Pk_data   - Predicted covariance matrix for the next time step (n by n by t)
%   Fhndl     - Function handle to propagate the state
%   Fargs     - Arguments for the state propagation function
%
% Outputs:
%   x_est_s   - Smoothed state estimate data (n by t)
%   p_est_s   - Smoothed state estimate covariance (n by n by t)

function [x_est_s, p_est_s] = RTS_Loop(x_data, P_data, xk_data, Pk_data, dt_data, u_data, Fhndl, Fargs)
    % Number of time steps
    t = length(dt_data) + 1;

    % State dimension
    n = size(x_data,1);

    x_est_s = zeros(n, t);
    p_est_s = zeros(n, n, t);

    % initialize at final time
    x_est_s(:,t)   = x_data(:,t);
    p_est_s(:,:,t) = P_data(:,:,t);

    % backward recursion
    for i = t-1:-1:1
        x   = x_data(:,i);
        P   = P_data(:,:,i);
        % prediction *into* time i+1:
        xk  = xk_data(:,i+1);
        Pk  = Pk_data(:,:,i+1);
        dt  = dt_data(i);
        u   = u_data(:,i);

        % carry in the already‐smoothed at i+1
        xs  = x_est_s(:,i+1);
        Ps  = p_est_s(:,:,i+1);

        % one step of the RTS smoother
        [xs, Ps] = spotKF.PostProcessing.RTS(x, P, xk, Pk, xs, Ps, dt, u, Fhndl, Fargs);

        x_est_s(:,i)   = xs;
        p_est_s(:,:,i) = Ps;
    end
end
