function [x, P, y, H] = runDQMEKF(z_meas, dt, x, P, Q, R, r, dmax, dq_red)
% Inputs:
% dq_red = dual quaternion of the chaser 
% z_meas = relitive dual quaterion of the target as seen from the chaser
% x = [target dual quaternion (global); target dual velocity quaternion]
% P = covar for error state 12 by 12
% dt = time step

%% Call the MEKF
[x, P, y, H] = DQMEKF(z_meas, dt, x, P, Q, R, r, dmax, dq_red,@dqmekfProp,[]);

end