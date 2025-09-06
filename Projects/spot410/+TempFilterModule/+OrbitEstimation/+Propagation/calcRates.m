function dx = calcRates(x_rel, u, m_s, J_s)
% calcRates Compute 3-DOF relative rates in servicer body fixed frame
%
% Inputs:
%   x_rel   : 8x1 relative state [x; y; theta; vx; vy; omega; theta_s; omega_s]
%           - theta_s : servicer attitude (rad)
%           - w_s     : servicer angular rate (rad/s)
%   u       : 3x1 control input [u1; u2; u3]
%           - u1,u2 = inertial-frame forces (Fx, Fy)
%           - u3 = inertial-frame torque (about z)
%   m_s     : servicer mass
%   J_s     : servicer moment of inertia
%
% Output:
%   dx    : 8x1 derivative of [x; y; theta; vx; vy; omega; theta_s, omega_s]
%

% Extract states
r_rel     = x_rel(1:2);    % relative position [x; y]
v_rel     = x_rel(4:5);    % relative velocity [vx; vy]
omega_rel = x_rel(6);      % relative angular rate
theta_s   = x_rel(7);      % inertial angle
w_s       = x_rel(8);      % inertial angular rate

% Skew-symmetric for z-axis
S = [0, -1; 1, 0];

% Compute servicer accelerations in its body frame
a_s_body = u(1:2)/m_s;  % linear accel in body frame
alpha_s  = u(3)/J_s;    % angular accel (scalar)

% Relative linear acceleration (transport theorem)
a_rel = - a_s_body ...             % servicer thrust
      - 2*w_s*(S * v_rel) ...      % Coriolis
      - alpha_s*(S * r_rel) ...    % angular accel effect
      + w_s^2 * r_rel;             % centripetal

% Relative angular acceleration
alpha_rel = - alpha_s;

% Pack derivatives
dx = [ v_rel;                  % x_dot, y_dot
       omega_rel;              % theta_dot
       a_rel;                  % vx_dot, vy_dot
       alpha_rel;              % omega_dot
       w_s;                    % theta_s_dot
       alpha_s];               % omega_s_dot            
end