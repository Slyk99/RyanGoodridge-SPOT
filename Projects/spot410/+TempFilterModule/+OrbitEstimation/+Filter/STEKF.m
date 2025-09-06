% ST-EKF   Strong Tracking Extended Kalman Filter with Optional Mahalanobis‐Distance Rejection
%
%   [x, P, EKFout] = EKF(dt, z, x, u, P, Q, R, ...
%                        Fhndl, Fargs, Hhndl, Hargs, ...
%                        OLR, d_max)
%
% Description:
%   Implements a discrete‐time Extended Kalman Filter for nonlinear systems,
%   with optional Strong Tracking, and/or outlier rejection based on the Mahalanobis distance.
%
%   Inputs:
%     dt      — Scalar time step Δt.
%     z       — Measurement column vector at current time.
%     x       — Prior state estimate column vector.
%     u       — Control/input column vector.
%     P       — Prior state covariance matrix.
%     Q       — Process noise covariance matrix.
%     R       — Measurement noise covariance matrix.
%     rho     — Fading factor for ST adaptation.
%     V       — True Pzz for ST adaptation.
%     Fhndl   — Process model handle:
%               [xk, F, G] = Fhndl(x, dt, u, Fargs).
%     Fargs   — Extra arguments (cell array or struct) for Fhndl.
%     Hhndl   — Measurement model handle:
%               [z_calc, H] = Hhndl(xk, Hargs).
%     Hargs   — Extra arguments (cell array or struct) for Hhndl.
%     ST      — Boolean flag to enable Strong Tracking Adaptation.
%     OLR     — (optional) Boolean flag to enable Mahalanobis outlier rejection.
%               Default: false.
%     d_max   — (optional) Distance threshold (in σ units) for rejection.
%               Default: 3.
%
%   Outputs:
%     x       — Posterior state estimate after update.
%     P       — Posterior state covariance after update.
%     V       — Updated True Pzz.
%     EKFout  — Struct with fields:
%                  y   — Innovation (z – z_calc).
%                  K   — Kalman gain matrix.
%                  H   — Measurement Jacobian.
%                  xk  — Predicted state before update.
%                  Pk  — Predicted covariance before update.
%                  d   — Mahalanobis distance of the measurement.
%
%   Notes:
%     • When OLR is true, any measurement with Mahalanobis distance > d_max
%       or containing NaNs is rejected: y→0, H→0, and update uses x = xk, P = Pk.
%     • Covariance update uses Joseph form:
%         P = (I – K·H)·Pk·(I – K·H)' + K·R·K'.
%
%   Example:
%     [x, P, V, out] = EKF(0.1, z, x_prev, u, P_prev, Q, R, V, ...
%                       @f_prop, f_args, @h_meas, h_args, true, 3);
%
%   (c) 2024 Ryan Goodridge

function [x, P, V, EKFout] = STEKF(dt, z, x, u, P, Q, R, rho, V, Fhndl, Fargs, Hhndl, Hargs, ST, OLR, d_max)
    % Handle different numbers of inputs and set defaults for optional parameters
    if nargin == 14
        OLR = false;  % Default: Outlier rejection is off
    elseif nargin == 15
        d_max = 3;    % Default: Mahalanobis distance threshold is 3 standard deviations
    elseif nargin > 16
        error('Too Many Inputs');  % Error if more than 15 inputs
    elseif nargin < 14
        error('Not Enough Inputs');  % Error if fewer than 13 inputs
    end

    % Propagate the state to the next time step using the provided function handle
    [xk, F, G] = Fhndl(x, dt, u, Fargs);
    Pk = F * P * F' + G*Q*G';

    % Measurement residual (innovation)
    [y, H] = Hhndl(xk,z);

    % Standard Kalman filter update step
    I = eye(size(Pk)); 
    Pzz = H * Pk * H' + R;

    % Compute the Mahalanobis distance and check for outliers
    if OLR
        [reject, d] = TempFilterModule.Misc.Mahalanobis2(y, Pzz, d_max);
    else
        reject = false;
        d = 0;
    end

    % Check if the measurement contains NaN values
    if reject || any(isnan(z))
        y = zeros(size(z)); 
        H = zeros(size(H));
        d = 0; 
    end

    % Strong Tracking adaptation
    if ST
        [V, lambda] = TempFilterModule.AdaptiveLaws.srtongTracking(V, y, Pzz, R, rho);
        Pk = lambda*Pk*lambda';
    end

    % If not an outlier, proceed with the Kalman filter update
    K = Pk * H' / Pzz;  
    x = xk + K * y;  
    P = (I - K * H) * Pk * (I - K * H)' + K * R * K'; 
    
    % EKF output
    EKFout.y  = y;
    EKFout.K  = K;
    EKFout.H  = H;
    EKFout.xk = xk;
    EKFout.Pk = Pk;
    EKFout.d  = d;
    EKFout.F  = F;
    EKFout.G  = G;
end