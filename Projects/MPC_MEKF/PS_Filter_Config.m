%% RED Workspace
% Tunable Parameters
kfChaser.Q    = blkdiag(0.0001*eye(2), 0.0000001);
kfChaser.R    = 0.0000001*eye(3);
kfChaser.rho  = 0.995;
kfChaser.dmax = 3;
kfChaser.a    = 10;

% toggles
kfChaser.ST   = false;
kfChaser.OLR  = false;

% State Sizes
kfChaser.x = zeros(6,1);
kfChaser.P = zeros(6,6);

%% BLACK Workspace
kfTarget = kfChaser;

%% BLUE Workspace
kfObs = kfChaser;

%% Navigation Options
navOpts.kfChaser = kfChaser;
navOpts.kfTarget = kfTarget;
navOpts.kfObs    = kfObs;

% Propagation arguments
navOpts.params.m = mRED;
navOpts.params.I = IRED;

% Toggles
navOpts.toggleREDkf     = true;
navOpts.toggleBLACKkf   = true;
navOpts.toggleBLUEkf    = true;

% Initial conditions
spotKFx0 = zeros(6,3);
spotKFP0 = zeros(6,6,3);

spotKFx0(1:3,1) = init_states_RED';
spotKFx0(1:3,2) = init_states_BLACK';
spotKFx0(1:3,3) = init_states_BLUE';

for i = 1:1:3
    spotKFP0(:,:,i) = eye(6);
end
