%% Initialize
params.m_s = mRED;
params.J_s = IRED;
navOpts.params  = params;

x_s = [dataClass_rt.RED_Px_m.Data, dataClass_rt.RED_Py_m.Data, dataClass_rt.RED_Rz_rad.Data, ...
       dataClass_rt.RED_Vx_mpers.Data, dataClass_rt.RED_Vy_mpers.Data, dataClass_rt.RED_RzD_radpers.Data]';
x_c = [dataClass_rt.BLACK_Px_m.Data, dataClass_rt.BLACK_Py_m.Data, dataClass_rt.BLACK_Rz_rad.Data, ...
       dataClass_rt.BLACK_Vx_mpers.Data, dataClass_rt.BLACK_Vy_mpers.Data, dataClass_rt.BLACK_RzD_radpers.Data]';
x_rel = [globalToRelative(x_s(:,3), x_c(:,3)); 0; x_s(6,3)] + [1e-2*rand([3,1]); 1e-3*rand([3,1]); 1e-4*rand([2,1])];

P = 2*eye(8);

% Initialize, Track 1 (INS), Track 2 (GNS), and fusion 
x_ic = zeros(8,1,3);
P_ic = zeros(8,8,3);
for i = 1:1:3
    x_ic(:,1,i) = x_rel;
    P_ic(:,:,i) = P;
end

%% Not Tuned
navOpts.Q_INS    = 0.00001*eye(4);
navOpts.Q_GNS    = 0.001*eye(4);
navOpts.Q_12     = 0.2*eye(4);
navOpts.R_PS     = 0.000001*eye(4);
navOpts.R_LRF    = 0.0001;
navOpts.R_Stereo = 0.0001*eye(4);
navOpts.R_LiDAR  = 0.001*eye(4);
navOpts.R_IMU    = diag([1; 1]);
navOpts.dmax     = 1.345;

%% Sage Husa Parameters
% initial measurement Bias
navOpts.r_PS     = [0; 0; 0; 0];
navOpts.r_LRF    =  0;
navOpts.r_Lidar  = [0; 0; 0; 0];
navOpts.r_Stereo = [0; 0; 0; 0];
navOpts.r_IMU    = [0; 0];

% Fading Factor for Sage Husa bias (0 = no change in bias)
alphaSH.rLRF     = 0.02;  % This sensor is just bad ngl
alphaSH.rIMU     = 0.0001; % Slow moving to acount for imu constant bias
alphaSH.rLidar   = 0.02;  % Hopefully with a fast moving r we can account for +-pi flips in angle
alphaSH.rStereo  = 0;     % Trust this sensor 
alphaSH.rPS      = 0;     % This sensor will never have bias

% Fading Factor for Sage Husa Q Adaptation (0 = no change in bias)
alphaSH.QINS     = 0.1;
alphaSH.QGNS     = 0.1;

% Fading Factor for Sage Husa Q Adaptation (0 = no change in bias)
alphaSH.Stereo   = 0.01;
alphaSH.LiDAR    = 0.01;
alphaSH.IMU      = 0.01;
alphaSH.RPS      = 0.01;
alphaSH.LRF      = 0.01;

navOpts.alphaSH = alphaSH;

%% Strong Tracking 
rho.INS = 0.99;
rho.GNS = 0.99;
navOpts.rho = rho;

%% Max Mahalanobis distance
navOpts.d_max = 3;

%% Toggles
navOpts.GNStoggle       = false;  % Use Vision
navOpts.INStoggle       = true;  % Use PhaseSpace
navOpts.OLR             = false; % Outlier Rejection
navOpts.ST              = false; % Strong Tracking
navOpts.SageHusa_Q      = false;
navOpts.SageHusa_R      = false;
navOpts.SageHusa_r      = true;

clear functions % make sure simulink is cleared 

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
r_s      = x_s(1:2);
r_c      = x_c(1:2);
theta_s  = x_s(3);
theta_c  = x_c(3);

% Extract velocities
dr_s     = x_s(4:5);
dr_c     = x_c(4:5);
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