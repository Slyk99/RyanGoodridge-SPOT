function [x, P, y, H, V] = runSTDQMEKF(z_meas, dt, x, P, Q, R, V, r, rho, dmax, dq_red)
% Inputs:
% dq_red = dual quaternion of the chaser 
% z_meas = relitive dual quaterion of the target as seen from the chaser
% x = [target dual quaternion (global); target dual velocity quaternion]
% P = covar for error state 12 by 12
% dt = time step

%% Call the MEKF
[x, P, y, H, V] = STDQMEKF(z_meas, dt, x, P, Q, R, V, r, rho, dmax, dq_red,@dqmekfProp,[]);
end