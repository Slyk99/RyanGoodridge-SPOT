%% Initialize
params.m_s = mRED;
params.J_s = IRED;
navOpts.params  = params;

x_s = [drop_states_RED'; ...
       zeros(3,1)];
x_c = [drop_states_BLACK'; ...
       zeros(3,1)];
x_rel = [globalToRelative(x_s, x_c); x_s(3,1); 0];

P = 2*eye(8);

% Initialize, Track 1 (INS), Track 2 (GNS), and fusion 
x_ic = zeros(8,1,3);
P_ic = zeros(8,8,3);
for i = 1:1:3
    x_ic(:,1,i) = x_rel;
    P_ic(:,:,i) = P;
end

%% Not Tuned
navOpts.Q_INS    = blkdiag(0.01*eye(2), ...
                   0.01, ...
                   0.01);
navOpts.Q_GNS    = blkdiag(0.01*eye(2), ...
                   0.01, ...
                   0.001);
navOpts.Q_12     = 0.000001*eye(4);
navOpts.R_GNS    = blkdiag(0.0001*eye(2), ...
                           0.001, ...
                           0.001, 0.01);
navOpts.RINSfull = [[0.1*ones(2,1); 0.1; 0.1]; % Stereo 
                    [2*ones(2,1); 2; 0.01]; % LiDAR
                    0.0001;  % LRF
                    0.0001;   % PS angle
                    0.1;]; % Angular Velocity

%% Sage Husa Parameters
% initial measurement Bias
navOpts.r_PS     = [0; 0; 0; 0; 0];
navOpts.r_LRF    =  0;
navOpts.r_Lidar  = [0; 0; 0; 0];
navOpts.r_Stereo = [0; 0; 0; 0];
navOpts.r_IMU    = [0; 0];

% Fading Factor for Sage Husa bias (0 = no change in bias)
alphaSH.rLRF     = 0.02;  % This sensor is just bad ngl
alphaSH.rIMU     = 0.00005; % Slow moving to acount for imu constant bias
alphaSH.rLidar   = 0;  % Hopefully with a fast moving r we can account for +-pi flips in angle
alphaSH.rStereo  = 0;     % Trust this sensor 
alphaSH.rPS      = 0.002;     % This sensor will never have bias

% Fading Factor for Sage Husa Q Adaptation
alphaSH.QINS     = 0.1;
alphaSH.QGNS     = 0;

% Fading Factor for Sage Husa R Adaptation
alphaSH.Stereo   = 0;
alphaSH.LiDAR    = 0.01;
alphaSH.IMU      = 0.01;
alphaSH.RPS      = 0;
alphaSH.LRF      = 0.01;

navOpts.alphaSH = alphaSH;

%% Strong Tracking 
rho.INS = 0.999;
rho.GNS = 0.999;
navOpts.rho = rho;

%% Max Mahalanobis distance
navOpts.GNSdmax     = [0.5; 0.5; 0.5; 0.5; 0.5];
navOpts.INSdmax     = [20; 20; 20; 10; 200; 20];

%% Toggles
navOpts.GNStoggle       = false;  % Use Vision
navOpts.INStoggle       = true; % Use PhaseSpace
navOpts.OLR             = true;  % Outlier Rejection
navOpts.ST              = false;  % Strong Tracking
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