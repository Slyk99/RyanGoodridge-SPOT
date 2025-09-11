% UDU Extended Kalman Filter with Optional Mahalanobis‐Distance Rejection and strong tracking adaptation
%
%   [x, P, EKFout] = UDU_STEKF(dt, z, x, u, P, Q, R, ...
%                        Hhndl, Fhndl, ...
%                        OLR, d_max)
%
% Description:
%   Implements a discrete‐time Extended Kalman Filter for nonlinear systems,
%   with optional outlier rejection based on the Mahalanobis distance.
%
%   Inputs:
%     dt      - Scalar time step Δt.
%     z       - Measurement column vector at current time.
%     x       - Prior state estimate column vector.
%     u       - Control/input column vector.
%     UD      - Prior state covariance matrix.
%     Q       - Process noise covariance matrix.
%     R       - Measurement noise covariance matrix.
%     V       - "True" Pzz
%     rho     - Fading Factor
%     Hhndl   - Measurement model handle:
%               [z_calc, H] = Hhndl(xk).
%     Fhndl   - Process model handle:
%               [xk, F, G] = Fhndl(x, dt, u).
%     ST      - (optional) Boolean flag to enable Strong Tracking Adaptation.
%     OLR     - (optional) Boolean flag to enable Mahalanobis outlier rejection.
%               Default: false.
%     d_max   - (optional) Distance threshold (in σ units) for rejection.
%               Default: 3.
%
%   Outputs:
%     x       - Posterior state estimate after update.
%     UD      - Posterior state covariance after update.
%     EKFout  - Struct with fields:
%                  y   - Innovation (z – z_calc).
%                  K   - Kalman gain matrix.
%                  H   - Measurement Jacobian.
%                  xk  - Predicted state before update.
%                  UDk - Predicted covariance before update.
%                  d   - Mahalanobis distance of the measurement.
%
%   Notes:
%     • The update step is sequential
%     • When OLR is true, any measurement with Mahalanobis distance > d_max
%       or containing NaNs is rejected: y→0, H→0, and update uses x = xk.
%
%   Example:
%     [x, P, out] = UDU_STEKF(0.1, z, x_prev, u, UD_prev, Q, R, ...
%                       @h_meas, @f_prop, true, 3);
%
%   (c) 2025 Ryan Goodridge
%

function [x, UD, EKFout] = UDU_STEKF(dt, z, x, u, UD, Q, R, V, rho, Hhndl, Fhndl, ST, OLR, d_max)
    % Handle different numbers of inputs and set defaults for optional parameters
    if nargin == 11
        ST  = false;
        OLR = false;
    elseif nargin == 12
        OLR = false;  % Default: Outlier rejection is off
    elseif nargin == 13
        d_max = 3;    % Default: Mahalanobis distance threshold
    elseif nargin < 11
        error('Too Many Inputs');  % Error if more than 9 inputs
    elseif nargin > 14
        error('Not Enough Inputs');  % Error if fewer than 10 inputs
    end

    % UD is n-by-n combined matrix
    n = size(UD,1);
    idx = 1:(n+1):n*n;        % linear indices of diagonal entries
    
    dvec = UD(idx);          % extract diagonal as vector
    D = diag(dvec);          % full diagonal matrix (optional)
    U = UD;                  
    U(idx) = 1;              % set diagonal to ones -> unit upper triangular U

    % Propagate the state to the next time step using the provided function handle
    [xk, F, G] = Fhndl(x, dt, u);

    W = [F*U, G];
    D_tilde = blkdiag(D,Q);
    [U, D] = TempFilterModule.OrbitEstimation.Filter.WMGS(W, D_tilde);

    % Store UD in single matrix
    n = size(U,1);
    idx = 1:(n+1):n*n;         % diagonal indices
    UDk = U;                    
    UDk(idx) = diag(D);         % put diagonal values into UD's diagonal

    % Measurement Prediction
    [z_bar, H] = Hhndl(xk);
    
    % Calculate innovation
    y = z - z_bar;
    y(5) = TempFilterModule.Misc.angErr(z(5), z_bar(5)); % Handle angle err
    
    % Sequential update (Scalar update)
    x = xk;

    % Preallocate
    K_store = (zeros(length(x), length(y)));
    d = zeros(size(z));
    for i = 1:1:length(y)  
        % Measurement Prediction
        [z_bar, H] = Hhndl(x);
        
        % Calculate innovation
        y = z - z_bar;
        y(4) = TempFilterModule.Misc.angErr(z(4), z_bar(4)); % Handle angle err

        % If not an outlier, proceed with the Kalman filter update
        Hi = H(i,:);
        Ri = R(i,i);
        yi = y(i);

        % Check if the measurement contains NaN values or mahalanobis rejection
        P = U*D*U';
        d(i) = (yi^2)/(Hi*P*Hi' + R(i,i));
        if isnan(yi) || OLR && d(i) > d_max(i)
            continue;
        else

        % Strong Tracking adaptation
        if ST
            [V(i,i), lambda] = TempFilterModule.AdaptiveLaws.srtongTracking(V(i,i), yi, P, Hi, Ri, rho);
            D = lambda*D; % Only true for scalar update
        end

        [U, D, K] = TempFilterModule.OrbitEstimation.Filter.modifiedAgeeTurner(U, D, Ri, Hi');  
        x = x + K * yi;  
        
        K_store(:,i) = K;
        end
    end

    % Store UD in single matrix    
    UD = U;                    
    UD(idx) = diag(D);         % put diagonal values into UD's diagonal

    % EKF output
    EKFout.y  = y;  % Measurement Residual
    EKFout.K  = K_store;  % Kalman Gain
    EKFout.H  = H;  % Measurement Jacobian
    EKFout.xk = xk; % Predicted States
    EKFout.Pk = UDk; % Predicted Covariance
    EKFout.F  = F;  % State Transition Jacobian
    EKFout.G  = G;  % State Input Matrix (discrete time)
    EKFout.V  = V;  % Estimate of True Pzz
    EKFout.d  = d;  % Mahalanobis Distance
end