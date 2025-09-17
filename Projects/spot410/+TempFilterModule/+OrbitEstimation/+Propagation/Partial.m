function F = Partial(x, alpha_s)
% Partial
% Computes the partial derivatives of 3-DoF planar relative dynamics
% with respect to the relative states, in servicer body frame.
%
% New State Definition:
%   x = [x_r; y_r; theta_r; theta_s; vx_r; vy_r; omega_s; bias]
%
% Inputs:
%   x         : state vector
%   alpha_s   : servicer angular acceleration (rad/s^2)
%
% Output:
%   Fout      : 8x8 Jacobian (continuous-time)

% === Extract states ===
xr      = x(1);   % relative x position
yr      = x(2);   % relative y position
theta_r = x(3);   % relative attitude
theta_s = x(4);   % servicer attitude
vx      = x(5);   % relative x velocity
vy      = x(6);   % relative y velocity
omega_r = x(7);   % relative angular rate
omega_s = x(8);   % servicer angular rate
bias    = x(9);   % bias

% --- preallocate
F = zeros(9,9);

% Kinematics: derivatives of positions / angles
F(1,5) = 1;   % dx/dvx
F(2,6) = 1;   % dy/dvy
F(3,7) = 1;   % dtheta_r/domega_r
F(4,8) = 1;   % dtheta_s/domega_s

% Dynamics: vx_dot = omega_s^2 * x + 2*omega_s*vy + alpha_s * y
F(5,1) = omega_s^2;             % d(vx_dot)/d x
F(5,2) = alpha_s;               % d(vx_dot)/d y
F(5,5) = 0;                     % d(vx_dot)/d vx
F(5,6) = 2*omega_s;             % d(vx_dot)/d vy
F(5,7) = 0;                     % d(vx_dot)/d omega_r
F(5,8) = 2*(omega_s * xr + vy); % d(vx_dot)/d omega_s
% bias does not appear in dynamics -> no column for it

% Dynamics: vy_dot = omega_s^2 * y - 2*omega_s*vx - alpha_s * x
F(6,1) = -alpha_s;              % d(vy_dot)/d x
F(6,2) = omega_s^2;             % d(vy_dot)/d y
F(6,5) = -2*omega_s;            % d(vy_dot)/d vx
F(6,6) = 0;                     % d(vy_dot)/d vy
F(6,7) = 0;                     % d(vy_dot)/d omega_r
F(6,8) = 2*(omega_s * yr - vx); % d(vy_dot)/d omega_s

end
