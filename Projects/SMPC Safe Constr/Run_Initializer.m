% The following script is the initializer for SPOT 4.1; in this script,
% users define all initials parameters and/or constants required for
% simulation and experiment.

clear;
clc;
close all force;

warning('off','all')

%% Start and pre-configure GUI

% No matter what, the GUI needs to be loaded
appHandle = GUI_v4_1_Main;

% Set the active diagram
appHandle.AvailableDiagramsDropDown.Value = "SMPC_safeconstr.slx";
appHandle.LoadSimulinkDiagram();

% Edit active platforms
appHandle.REDCheckBox.Value    = 1;
appHandle.BLACKCheckBox.Value  = 1;
appHandle.BLUECheckBox.Value   = 0;
appHandle.ARMCheckBox.Value    = 0;

appHandle.ConfirmSettings();

% Edit phase durations
appHandle.DurPhase0EditField.Value = 10;
appHandle.DurPhase1EditField.Value = 5;
appHandle.DurPhase2EditField.Value = 30;

appHandle.SubPhase1EditField.Value = 120;
appHandle.SubPhase2EditField.Value = 0;
appHandle.SubPhase3EditField.Value = 0;
appHandle.SubPhase4EditField.Value = 0;

appHandle.DurPhase4EditField.Value = 0;
appHandle.DurPhase5EditField.Value = 0;

appHandle.UpdateTimes();

%% Conversions

d2r = pi/180;                                   % Degrees to radians conversion
r2d = 1/d2r;                                    % Radians to degrees conversion

%% Dynamics 

% Set RED mass in the GUI
A = [zeros(3), eye(3); zeros(3,6)];             % State matrix
B = [zeros(3); diag([1/mRED, 1/mRED, 1/IRED])]; % Input matrix

%% Model Predictive Control

N_h = 15;                                       % Horizon length
T_d = 2;                                        % Discretization time [s]

% Q = diag([100 100 100 300 300 300]);            % State error weighting matrix
% R = diag([200 200 200]);                        % Control weighting matrix

Q = diag([10 10 10 300 300 500]);            % State error weighting matrix
R = diag([10 10 10]);                        % Control weighting matrix

%% Constraints

use_LOS_constr = false;
use_table_constr = false;

% Target Collision Constraint
r_hold_min = [0.8; (0.3+0.05)];                 % Minimum holding radius [m, m]
r_hold_obs = 1.1*sqrt(2)*0.3.*[1;1];

gamma = 0.95;                                   % Holding radius scaling factor
eta = 0.7;                                      % Holding radius linear tolerance [m]
zeta = 10*d2r;                                  % Holding radius angular tolerance [deg.]

% Table Constraint
edge_buffer = 0.27;                             % Table edge buffer [m]

% Thruster Constraint
T_max = 0.15;                                   % Maximum thrust [N]
u_max = T_max.*[1 1 (0.3/2)];                   % Maximum control input [N, N, Nm]

% Docking
docking_face = [0 1]';                          % Docking face normal vector
docking_offset = [0 0 0]';                      % Docking chaser offset [m, m, rad]

%% Unscented Kalman Filter Parameters

Q_k = [1e-6*eye(3)  zeros(3,3);                 % Process noise covariance matrix
       zeros(3,3)  1e-8*eye(3)];
% dt = 0.05;
% G = [(dt^2/2)*eye(3); dt*eye(3)];
% q = 1e-6*eye(3);

% Q_k = G*q*G';
R_k = diag([0.02^2 0.02^2 0.01^2]);             % Measurement noise covariance matrix

alpha = 0.9;                                    % UKF tuning parameter
beta = 2;                                       % UKF tuning parameter
kappa = 20;                                     % UKF tuning parameter

% alpha = 1;                                    % UKF tuning parameter
% beta = 0;                                       % UKF tuning parameter
% kappa = 0;                                     % UKF tuning parameter

lambda = (alpha^2)*(6 + kappa) - 6;

w_m0 = lambda/(6 + lambda);
w_c0 = w_m0 + (1 - alpha^2 + beta);

w_i = 1/(2*(6 + lambda));

w_m = [w_m0, w_i.*ones(1, 2*6)];                % Mean sigma point weighting
w_c = [w_c0, w_i.*ones(1, 2*6)];                % Covariance sigma point weighting

%% Pre-compute constant MPC matrices

[A_d, B_d] = discretize(A, B, T_d);             % Discretized state & control matrices
Q_f = idare(A_d, B_d, Q, R, [], []);            % Terminal state error weighting matrix

% Cost Function Weights
H = kron(eye(N_h), [R, zeros(3,6); zeros(6,3), Q]);
H(end-6+1:end,end-6+1:end) = Q_f; % Replace last Q with Q_f

% Dynamics Constraint
C = [  [-B_d eye(6)],        zeros(6, 9*(N_h-1));
     zeros(6*(N_h-1), 9), zeros(6*(N_h-1), 9*(N_h-1))];

for j = 2:N_h
    row = 6*(j-1)+1;
    col = 15*(j-1)-(6*j)+1;

    C(row:row+6-1, col:col+15-1) = [-A_d -B_d eye(6)];
end

% Table Constraint
F_t = [kron(eye(N_h),  [zeros(2,3), eye(2), zeros(2,4)]); 
       kron(eye(N_h), -[zeros(2,3), eye(2), zeros(2,4)])];

f_t = [kron(ones(N_h, 1), [xLength yLength]' - edge_buffer); 
       kron(ones(N_h, 1), [0 0]' - edge_buffer)];

% Thrust Constraint
F_u = [kron(eye(N_h),  [eye(3), zeros(3,6)]);
            kron(eye(N_h), -[eye(3), zeros(3,6)])];

f_u = kron(ones(2*N_h, 1), u_max');

%% Initial Conditions

test_case = 1;

if test_case == 0
    u_0 = [-0.14 0 0]';
    r_hold_0 = 1.15.*[1 1];
    x_RED_0 = [3 2 0 0 0 0]';
    x_BLACK_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
    x_BLUE_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
elseif test_case == 1
    u_0 = [-0.14 0 0]';
    r_hold_0 = 1.15.*[1 1];
    x_RED_0 = [3.3 1.8 0 0 0 0]';
    x_BLACK_0 = [2.0 2.2 270*d2r -0.01 -0.005 -1.25*d2r]';
    x_BLUE_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
elseif test_case == 2
    u_0 = [-0.14 0 0]';
    r_hold_0 = 1.15.*[1 1];
    x_RED_0 = [1.5 2 pi 0 0 0]';
    x_BLACK_0 = [2.2 0.2 3*pi/2 -0.005 0.005 2.5*d2r]';
    x_BLUE_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
elseif test_case == 3
    u_0 = [0 -0.1 0]';
    r_hold_0 = 0.9.*[1 1];
    x_RED_0 = [3.2 2.1 pi/2 0 0 0]';
    x_BLACK_0 = [1.7 1.2 180*d2r 0 0 -1*d2r]';
    x_BLUE_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
elseif test_case == 4
    u_0 = [-0.14 0 0]';
    r_hold_0 = 1.03.*[1 1];
    x_RED_0 = [3.2 2.1 0 0 0 0]';
    x_BLACK_0 = [0.32 0.32 315*d2r 0.01 0.005 1*d2r]';
    x_BLUE_0 = [0.5 0.5 315*d2r 0.01 0.01 1*d2r]';
end

P_tar_0 = [R_k zeros(3,3);
           zeros(3,3), diag([1 1 1])];
P_obs_0 = [2.*R_k zeros(3,3);
           zeros(3,3), diag([1 1 1])];

x_tar_0 = [x_BLACK_0(1:3) + diag(sqrt(R_k)); 0.01; 0.01; 0.005];
x_obs_0 = [x_BLUE_0(1:3) + diag(sqrt(R_k)); 0.01; 0.01; 0.005];

% Initial optimization variable guess
z_0 = zeros(9*N_h,1);
z_0(1:9) = [u_0; A_d*x_RED_0 + B_d*u_0];
 
for j = 2:N_h
    pos = 9*(j-1)+1;
    
    z_0(pos:pos+9-1) = [zeros(3,1); A_d*z_0(pos-6:pos-1)];
end

% Set initial conditions in the GUI
appHandle.SubAppInitialConditions.REDInitialX.Value  = x_RED_0(1);
appHandle.SubAppInitialConditions.REDInitialY.Value  = x_RED_0(2);
appHandle.SubAppInitialConditions.REDInitialTh.Value = x_RED_0(3)*r2d;
appHandle.SubAppInitialConditions.REDStartX.Value  = x_RED_0(1);
appHandle.SubAppInitialConditions.REDStartY.Value  = x_RED_0(2);
appHandle.SubAppInitialConditions.REDStartTh.Value = x_RED_0(3)*r2d;

appHandle.SubAppInitialConditions.BLACKInitialX.Value  = x_BLACK_0(1);
appHandle.SubAppInitialConditions.BLACKInitialY.Value  = x_BLACK_0(2);
appHandle.SubAppInitialConditions.BLACKInitialTh.Value = x_BLACK_0(3)*r2d;
appHandle.SubAppInitialConditions.BLACKStartX.Value  = x_BLACK_0(1);
appHandle.SubAppInitialConditions.BLACKStartY.Value  = x_BLACK_0(2);
appHandle.SubAppInitialConditions.BLACKStartTh.Value = x_BLACK_0(3)*r2d;

appHandle.SubAppInitialConditions.BLUEInitialX.Value  = x_BLUE_0(1);
appHandle.SubAppInitialConditions.BLUEInitialY.Value  = x_BLUE_0(2);
appHandle.SubAppInitialConditions.BLUEInitialTh.Value = x_BLUE_0(3)*r2d;
appHandle.SubAppInitialConditions.BLUEStartX.Value  = x_BLUE_0(1);
appHandle.SubAppInitialConditions.BLUEStartY.Value  = x_BLUE_0(2);
appHandle.SubAppInitialConditions.BLUEStartTh.Value = x_BLUE_0(3)*r2d;

appHandle.SubAppInitialConditions.UpdateInitialConditions();

%% Place any custom variables or overwriting variables in this section

% As an example, here are the control parameters the manipulator.
% Set torque limits on joints

Tz_lim_sharm                   = .1; % Shoulder Joint [Nm]

Tz_lim_elarm                   = .1; % Elbow Joint [Nm]

Tz_lim_wrarm                   = .1; % Wrist Joint [Nm]

% Transpose Jacobian controller gains:

Kp = [0.08 0 0
      0    0.08 0
      0    0    0.002];
Kv = [0.05 0 0
      0    0.05 0
      0    0    0.005];

% Initialize the PID gains for the ARM:

Kp_sharm                       = 1.5;
Kd_sharm                       = 1.0;

Kp_elarm                       = 1.2;
Kd_elarm                       = 0.8;

Kp_wrarm                       = 1.0;
Kd_wrarm                       = 0.6;

% Define the model properties for the joint friction:
% Based on https://ieeexplore.ieee.org/document/1511048

%Shoulder
Gamma1_sh = 0.005; 
Gamma2_sh = 5;
Gamma3_sh = 40;
Gamma4_sh = 0.015; 
Gamma5_sh = 800; 
Gamma6_sh = 0.005;

%Elbow
Gamma1_el = 0.12; 
Gamma2_el = 5;
Gamma3_el = 10;
Gamma4_el = 0.039; 
Gamma5_el = 800;
Gamma6_el = 0.000001;

%Wrist
Gamma1_wr = 0.025;
Gamma2_wr = 5;
Gamma3_wr = 40;
Gamma4_wr = 0.029;
Gamma5_wr = 800; 
Gamma6_wr = 0.02;

%% This section of the code contains parameters should not be modified

% Set the PWM frequency
PWMFreq = 5; %[Hz]

%% Functions

function C = rotz(theta)
    C = [cos(theta), -sin(theta); 
         sin(theta),  cos(theta)];
end

function theta_des = rotateToFace(theta, r)
    theta_des = theta + wrapToPi(atan2(r(2),r(1)) - theta);
end

function theta_wrap = wrapAngle(theta)
    theta_wrap = atan2(sin(theta),cos(theta));
end

function [Ad, Bd] = discretize(A, B, dt)
    if size(A,1) ~= size(B,1)
        error('The first dimension of A and B must be equal')
    end

    phi = expm([A B; zeros(size(B,2),size(A,2)+size(B,2))]*dt);
    
    Ad = phi(1:size(A,1), 1:size(A,2));
    Bd = phi(1:size(B,1), size(A,2)+1:size(A,2)+size(B,2));
end




