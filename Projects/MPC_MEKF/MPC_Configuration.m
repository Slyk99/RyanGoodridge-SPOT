%% Parameters
mred = 12;
Ired = 0.2;
umax = 0.25;
Tmax = 0.05;

%% State Space Model
A = [zeros(3), eye(3);
     zeros(3), zeros(3)];

B = [0,      0,      0;
     0,      0,      0;
     0,      0,      0;
     1/mred, 0,      0;
     0,      1/mred, 0;
     0,      0,      1/Ired;];

C = [eye(3), zeros(3)];

D = zeros(3);

%% MPC Inputs
N = 15; % Prediction Horizon
M = 3;  % Control Horizon
n = 6;  % State dimension
m = 3;  % Input dimension

% Initial Condition
mpcIC = zeros((3*N + 6*N),1); 

% Maximum force and torque
umax = [umax; umax; Tmax];

% Rate of MPC - MPC is ZOH
mpcConfig.dt = 0.2; % MPC dt

% Tunable Parameters
mpcConfig.Q = blkdiag(5*eye(3), 1*eye(3)); % State cost
mpcConfig.R = 100 * eye(m);                % Input cost
mpcConfig.epsilon = 0.01;                  % Confidence Level (For stochastic constraints)

% Offset
mpcConfig.docking_Offset = [0.1655093; 0.43629; 0]; % Where red needs to be to dock
mpcConfig.BlackOffset = [0.1655093; 0];             % Offset for geometry
mpcConfig.BlueOffset = [0;0];                       % No offset, constraint is at center of mass

% Docking Angle offset - Red looks at black until docking, then activates
% this angular offset 
theta = atan2(mpcConfig.docking_Offset(2), mpcConfig.docking_Offset(1));
mpcConfig.Camera_Offset = [0; 0; theta];

% Avoidance Constraint
mpcConfig.holding_radius = 0.7*[1; 1.1];    % Target Max constraint
mpcConfig.r_hold_min = [0.35; 0.35];        % Target Min constraint - [0.8; 0.45] for solar panels
mpcConfig.ObsHold = 0.7*[1;1];              % Obstacle Constraint

% Holding Radius Decay Factors
mpcConfig.eta = 0.2;        % Min Error to start decay
mpcConfig.zeta = 10*pi/180; % Angular decay rate
mpcConfig.gamma = 0.98;     % Position decay rate

% System 
mpcConfig.A = A;
mpcConfig.B = B;

% Table Bounds
d = 0.15; % Center to pucks distance
mpcConfig.x_max = [3.5-d; 2.4-d; 10*pi];
mpcConfig.x_min = [0+d; 0+d; -10*pi];
mpcConfig.H_max = [eye(3), zeros(3)]; % What states have a maxima
mpcConfig.H_min = [eye(3), zeros(3)]; % What states have a minima

% Camera FOV constraint (NOT USED)
mpcConfig.Camera_FOV = 120*pi/180; % FOV of camera
