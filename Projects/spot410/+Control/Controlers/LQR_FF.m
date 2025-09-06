function u = LQR_FF(x_ref, x_act, Params)
% Params
K = Params.K;
m = Params.m;
J = Params.J;

% Skew-symmetric for z-axis
S = [0, -1; 1, 0];

% Unpack
r_rel = x_act(1:2);
v_rel = x_act(4:5);
w_s   = x_act(6);

%% Standard LQR
err = x_ref - x_act;
u_LQR = K*err; % 3 by 1

%% Feed Forward to cancel out rotating frame (No Torque)
% Compute servicer accelerations in its body frame
alpha_s  = u_LQR(3)/J;            % angular accel (scalar)

a_cor  = - 2*w_s*(S * v_rel);     % Coriolis
a_cent = - alpha_s*(S * r_rel);   % angular accel effect
a_acc  = w_s^2 * r_rel;           % centripetal

u_ff = - m*(a_cor + a_cent + a_acc); % 2 by 2

% Sum forces
u = u_LQR + [u_ff; 0];

end