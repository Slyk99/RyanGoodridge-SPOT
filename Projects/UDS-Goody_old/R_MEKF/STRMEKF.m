function [x, Rot, P, y, H, V] = STRMEKF(z, Rot_obs, dt, x, Rot, P, Q, R, V, r, rho, dmax, Fhndl, Fargs, Hhndl, Hargs)

% EMEKF – Extended Multiplicative Extended Kalman Filter.
%
% The full (error) state is defined as:
%    delta = [delta_theta (3); delta_x (9)]
% and the covariance P is 12x12.
%
% Inputs:
%   z       - translation measurement (3x1)
%   Rot_obs - observed rotation matrix (3x3)
%   dt      - time step
%   x       - current non-attitude state (9x1)
%   Rot     - current attitude estimate (3x3)
%   P       - current covariance (12x12)
%   Q       - process noise covariance (12x12)
%   R       - measurement noise covariance (6x6)
%   Fhndl   - handle for propagation function
%   Fargs   - additional arguments for propagation
%   Hhndl   - handle for measurement function
%   Hargs   - additional arguments for measurement
%
% Outputs:
%   x       - updated non-attitude state (9x1)
%   Rot     - updated attitude estimate (3x3)
%   P       - updated covariance (12x12)
%   y       - measurement innovation (6x1)
%   H_full  - full measurement Jacobian (6x12)
%   d       - (dummy) Mahalanobis distance

    %% Predict Step
    [x_k, Rot_pred, F] = Fhndl(x, Rot, dt, Fargs);  % F is 12x12
    P_k = F * P * F' + Q;  % Propagate covariance (12x12)

    %% Update Step
    % Evaluate measurement function at the predicted state:
    [z_bar, Rot_bar, H] = Hhndl(x_k, z, Rot_pred, Hargs);  % z_bar (3x1), H_meas (3x9)
    
    % Calculate Innovation
    dtheta = (rand(1,1)-0.5)*r;
    Rot_obs = C3(dtheta)*Rot_obs;
    y = residual(z,z_bar,Rot_bar,Rot_obs);

    %% Mahalanobis distance (reject position and rotation separate)
    HQuat = H(1:3,:);
    HPose = H(4:6,:);
    [rejectQuat, ~] = Mahalanobis2(y(1:3), HQuat * P_k * HQuat', dmax(1));
    [rejectPose, ~] = Mahalanobis2(y(4:6), HPose * P_k * HPose', dmax(2));

    % mask out only the bad part
    if rejectQuat
        y(1:3)    = 0;
        H(1:3, :) = 0;
    end
    if rejectPose
        y(4:6)    = 0;
        H(4:6, :) = 0;
    end

    %% ST Algorythm
    % Find better estimate of S
    V = optPzz1(V,rho,y);
    % V = optPzz3(Pzz,rho,y);

    % Find Lambda
    % L = corrP1(V,Pzz,R);
    % L = corrP2(V,R,H,Q,P_k);
    % L = corrP3(V,R,H,Q,Pzz);
    L = corrP4R(P_k, H, R, V);

    % Corrct Covar
    P_k = L*P_k*L;
    Pzz = H * P_k * H' + R; % Innovation covariance
    V = rho*V;

    %% EKF Update
    K = P_k * H' / Pzz;                                % Kalman gain
    I = eye(size(P));                                  % Identity matrix
    P = (I - K * H) * P_k * (I - K * H)' + K * R * K'; % Joseph form to maintain symmetry

    % State update:
    delta = K * y;

    % Rebuild rotation matrix
    delta_R = buildRot(delta(1:3));

    % Updated attitude estimate
    Rot = delta_R * Rot_pred;

    % Update the non-attitude state:
    x = x_k + delta(4:end);  % 9x1
end
