function F = Partial(x_rel, alpha_s)
% Partial
% Computes the partial derivatives of 3-DoF planar relative dynamics
% with respect to the relative states, in servicer body frame.
%
% Inputs:
%   x_rel       : [x_r; y_r; theta_r; vx_r; vy_r; omega_r]
%   omega_s     : servicer angular velocity (rad/s)
%   omega_s_dot : servicer angular acceleration (rad/s^2)
%
% Output:
%   A           : 8x8 Jacobian (continuous-time)

% Extract states
rx        = x_rel(1);      % relative x position
ry        = x_rel(2);      % relative y position
vx        = x_rel(4);      % relative x velocity 
vy        = x_rel(5);      % relative y velocity
omega_rel = x_rel(6);      % relative angular rate
theta_s   = x_rel(7);      % inertial angle
w_s       = x_rel(8);      % inertial angular rate

% Preallocate
F = zeros(8,8);

% rows 1:3
F_13 = [zeros(3), eye(3), zeros(3,2)];

% row 4
F_4 = [w_s^2,    alpha_s, 0, 0,      2*w_s, 0, 0, 2*(vy + vx*w_s)];

% row 5
F_5 = [-alpha_s, w_s^2,   0, -2*w_s, 0,     0, 0, -2*(vx - vy*w_s)];

% rows 6:8
F_68 = zeros(3,8);
F_68(2,7) = 1;

% Full Jacobian
F = [F_13;
     F_4;
     F_5;
     F_68];

end