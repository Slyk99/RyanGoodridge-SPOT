%%
% Inputs:
% z_prev    - Previous MPC solution
% kfChaser  - Structure with the following params
%             x     - Estimate of current state vector
%             P     - Estimate of current Covar
%             Q     - Process Noise Matrix
% kfTarget  - Structure with the following params
%             x     - Estimate of current state vector
%             P     - Estimate of current Covar
%             Q     - Process Noise Matrix
% kfObs     - Structure with the following params
%             x     - Estimate of current state vector
%             P     - Estimate of current Covar
%             Q     - Process Noise Matrix
% dt        - Current time difference
% N         - Prediction Horizon
% M         - Control Horizon
% mpcConfig - Structure with the following params
%             dt        - Delta Time
%             x_max     - Maximum value for constrained states
%             x_min     - Minimum value for constrained states
%             H_max     - Transformation matrix from states to constrained states for
%                         states that have a maximum
%             H_min     - Transformation matrix from states to constrained states for
%                         states that have a minimum
%             A         - Cont. Time Dynamics Matrix
%             B         - Cont. Time Input Matrix
%             Q         - State Weighting Matrix
%             R         - Input Weighting Matrix
%             epsilon   - Stochastic Constraint Parameter [0 < eps < 0.5]
%
function [z, u, results] = runMPC(z_prev, kfChaser, kfTarget, kfObs, umax, N, M, mpcConfig)
    % Declare as Persistent
    tic
    persistent isInit k n m Ad Bd K H0 Aineq_input bineq_input r_hold proximity

    % Preallocate Space
    z = z_prev;
    u = zeros(size(mpcConfig.B,2),1);
    results = -1*ones(1,4); % -1 Flag for didn't run quodprog

    %% One‑Time Initialization
    if isempty(isInit)

        % problem dimensions
        n = size(mpcConfig.A,1);
        m = size(mpcConfig.B,2);

        % discretize
        Ad = eye(n) + mpcConfig.dt*mpcConfig.A;
        Bd =         mpcConfig.dt*mpcConfig.B;

        % Termination weight matrix
        [Qf, K] = spotSMPC.Gradient.dare_iterative(Ad, Bd, mpcConfig.Q, mpcConfig.R, 10000, 0.00001);

        % cost Hessian
        H0 = spotSMPC.Gradient.MakeWeight(mpcConfig.Q, Qf, mpcConfig.R, N);

        % input constraints
        [Aineq_input, bineq_input] = spotSMPC.InequalityConstrains.inputConstraints(umax, n, m, N);

        % Holding radius and close range flag
        r_hold = mpcConfig.holding_radius;
        proximity = false;

        % First call should run the MPC
        k = M;

        % Never call the initialize again
        isInit = true;
    end

    %% Advance k and Return Last u opt
    if k < M
        % extract the k-th block from last solution z
        idx_start = (k-1)*m + 1;
        idx_end   = idx_start + m - 1; 
        u(1:end) = z_prev(idx_start:idx_end);
        k = k + 1;
        return
    end

    %% If k == M Run MPC
    % Propagate Black States
    [xTstack, PTstack] = spotSMPC.InitialConditions.propTarget(kfTarget.x, kfTarget.P, Ad, Bd, kfTarget.Q, n, N);
    [xOstack, POstack] = spotSMPC.InitialConditions.propTarget(kfObs.x, kfObs.P, Ad, Bd, kfObs.Q, n, N);

    [z0, PChaser] = spotSMPC.InitialConditions.initialGuess(z_prev, kfChaser.x, kfChaser.P, [], Ad, Bd, 0*K, kfChaser.Q, n, m, N, M);

    % Calculate the docking port location
    [DockingPort, DockingRadius] = spotSMPC.InitialConditions.dockingLocation(xTstack, mpcConfig.docking_Offset, N);

    % Calculate the reference trajectory
    [x_ref, u_ref] = spotSMPC.InitialConditions.genReference(z0, xTstack, DockingPort, DockingRadius, m, n, N, mpcConfig.dt, mpcConfig.Camera_Offset);

    % Equality Constraints
    [Aeq, beq] = spotSMPC.EqualityConstraints.dynamicConstraint(kfChaser.x, Ad, Bd, n, m, N);

    % Update reference angle if close enough to dock
    if proximity
        x_ref = spotSMPC.InitialConditions.updateAngle(x_ref, mpcConfig.docking_Offset(3), n, N);
    end

    % idx = 3:6:length(x_ref);
    % plot(x_ref(idx,1))
    % Calculate Holding Radius
    [r_hold,proximity] = spotSMPC.InequalityConstrains.calcHoldingDist(r_hold, proximity, x_ref, kfChaser.x, mpcConfig.eta, mpcConfig.zeta, mpcConfig.gamma, mpcConfig.r_hold_min);

    % Inequality Constraints
    [Aineq_max, bineq_max]   = spotSMPC.InequalityConstrains.buildMaxConstraint(mpcConfig.x_max, PChaser, mpcConfig.H_max, m, N, mpcConfig.epsilon);
    [Aineq_min, bineq_min]   = spotSMPC.InequalityConstrains.buildMaxConstraint(-1*mpcConfig.x_min, PChaser, -1*mpcConfig.H_min, m, N, mpcConfig.epsilon);
    [Aineq_hold, bineq_hold] = spotSMPC.InequalityConstrains.StochasticHoldingRadius(r_hold, z0, xTstack, PTstack, mpcConfig.BlackOffset, n, m, N, mpcConfig.epsilon);
    [Aineq_Obs, bineq_Obs]   = spotSMPC.InequalityConstrains.StochasticHoldingRadius(mpcConfig.ObsHold, z0, xOstack, POstack, mpcConfig.BlueOffset, n, m, N, mpcConfig.epsilon);
    % [Aineq_FOV, bineq_FOV]   = spotSMPC.InequalityConstrains.fovConstraints(z0, PChaser, xTstack, PTstack, x_ref, mpcConfig.Camera_FOV, mpcConfig.Camera_Offset, m, n, N, mpcConfig.epsilon);
    % FOV not needed because looking angle was used for the reference
    % Append all constraints
    Aineq = [Aineq_input;
             Aineq_max;
             Aineq_min;
             Aineq_hold;
             Aineq_Obs;]; 
    bineq = [bineq_input;
             bineq_max;
             bineq_min;
             bineq_hold;
             bineq_Obs;];

    % Gradient of Cost
    [H, f] = spotSMPC.Gradient.GradientMatrices(x_ref, u_ref, H0, n, m, N);

    % Solve QP
    [z_opt, u_opt, results_opt] = spotSMPC.MPCsolve(H, f, Aineq, bineq, Aeq, beq, z0, m);
    z(1:end) = z_opt;
    u(1:end) = u_opt;
    cputime_tot = toc;
    results(1,1:end) = [results_opt, cputime_tot];

    % reset counter so next M‑1 calls use previous solution
    k = 1;
end
