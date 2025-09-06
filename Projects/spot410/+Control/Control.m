function u = Control(x_ref, x_current)
% x_ref     = desired [x_rel, y_rel, theta_frame, dx_rel, dy_rel, dtheta_frame]
% x_currnet = actual  [x_rel, y_rel, theta_targ,  dx_rel, dy_rel, dtheta_targ, theta_frame, dtheta_frame]

m = 12;
J = 0.2;
K = [diag([0.1, 0.1, 0.001]), diag([1, 1, 0.01])];

% Reshape x_current
x_act = [x_current(1:2); x_current(7); x_current(4:5); x_current(8)];

% Find optimal control effort
u = LQR_FF(x_ref, x_act, Params);

end
