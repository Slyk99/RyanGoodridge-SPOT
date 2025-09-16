function x_rel = globalToRelative(x_s, x_c)
% globalToRelative  Compute relative state in servicer frame
%
% Inputs:
%   x_s : 6x1 servicer global state [x_s; y_s; theta_s; dx_s; dy_s; dtheta_s]
%   x_c : 6x1 client  global state [x_c; y_c; theta_c; dx_c; dy_c; dtheta_c]
%
% Output:
%   x_rel : 6x1 relative state [x_rel; y_rel; theta_rel; vx_rel; vy_rel; omega_rel]

% Extract positions and orientations
r_s      = x_s(1:2)';
r_c      = x_c(1:2)';
theta_s  = x_s(3);
theta_c  = x_c(3);

% Extract velocities
dr_s     = x_s(4:5)';
dr_c     = x_c(4:5)';
w_s      = x_s(6);
w_c      = x_c(6);

% Rotation matrix from inertial to servicer frame
R_s = [cos(theta_s),  sin(theta_s);
       -sin(theta_s), cos(theta_s)];

% Skew-symmetric matrix in 2D
S = [0, -1; 1, 0];

% Relative position in servicer frame
r_rel = R_s*(r_c - r_s);

% Relative orientation
theta_rel = theta_c - theta_s;

% Relative velocity in servicer frame (transport theorem)
v_rel = R_s*(dr_c - dr_s) - w_s*(S*r_rel);

% Relative angular rate
omega_rel = w_c - w_s;

% Assemble relative state
x_rel = [
    r_rel;           % [x_rel; y_rel]
    theta_rel;       % theta_rel
    v_rel;           % [vx_rel; vy_rel]
    omega_rel       % omega_rel
];
end
