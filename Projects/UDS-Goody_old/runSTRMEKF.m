function [x, Rot, P, y, H, V] = runSTRMEKF(Chaser, z, Rot_obs, dt, x, Rot, P, Q, R, V, r, rho, dmax)
% Filter – Wrapper for the Multiplicative Extended Kalman Filter (MEKF)
%
% Inputs:
%   Chaser   - [x; y; yaw] (chaser state; note: z and roll/pitch assumed zero)
%   z        - measurement vector (translation measurement, 3x1)
%   Rot_obs  - observed rotation matrix (3x3) from sensors
%   dt       - time step
%   x        - non‐attitude state vector (9x1): [position; velocity; angular velocity]
%   Rot      - attitude estimate (3x3 rotation matrix)
%   P        - filter covariance (12x12) for [attitude error; x error]
%   Q        - process noise covariance (12x12) (if empty, a default is used)
%   R        - measurement noise covariance (6x6) (if empty, a default is used)
%
% Outputs:
%   States   - Full state vector for output [target position; attitude angles; remaining x]
%   x        - updated non‑attitude state (9x1)
%   Rot      - updated attitude estimate (3x3)
%   P        - updated covariance (12x12)
%   y        - measurement innovation (6x1)
%   H_full   - full measurement Jacobian (6x12)
%   d        - Mahalanobis distance

    % Set up measurement parameters (chaser parameters)
    Hargs.x = Chaser(1);   % chaser x-position
    Hargs.y = Chaser(2);   % chaser y-position
    Hargs.z = 0;           % chaser z is assumed zero
    Hargs.yaw = Chaser(3:6); % chaser quat

    % Run the MEKF
    [x, Rot, P, y, H, V] = STRMEKF(z, Rot_obs, dt, x, Rot, P, Q, R, V, r, rho, dmax, @rmekfProp, [], @rmekfMeas, Hargs);
end