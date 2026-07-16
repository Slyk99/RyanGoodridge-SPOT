%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File name: fmincon_solver_v#.m
% Author: Aaron vandenEnden
% Version: 5.1
% Last updated: May 12th 2026
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Version 5.1 updates:
% - Tuning for SPOT




function [X, U] = fmincon_solver_v50(qin, dqin, xgoal, N, Ndt, obs1, useCollision1)
% fmincon_solver_taskspace
% Task-space (Cartesian) NMPC for a free-floating planar base + 3R arm
% State:  x = [q(6); dq(6)]  = 12x1
% Control: u = tau_arm(3) applied to joints 4:6 (base unactuated)
%
% Inputs:
%   qin   (6x1)  = [x_base; y_base; theta_base; q1; q2; q3]
%   dqin  (6x1)
%   xgoal (3x1)  = [x_ee_des; y_ee_des; phi_ee_des]
%   N            = horizon steps
%   Ndt          = sample time (seconds) per step
%   obs1        Series of verticies to describe obstacle 1 [x,y; ...]
%
% Outputs:
%   X (12x(N+1)) rollout of optimal predicted state trajectory
%   U (3xN)      optimal torque sequence for joints 4:6


dt = Ndt;

% Unpack obstacle
obsX = obs1(1:2:end);
obsY = obs1(2:2:end);

    
nx = 12;
nu = 3;

% Limits
servotorque = 0.1;                      % N*m
uMax = servotorque * ones(nu,1);
uMin = -uMax;

useJointLimits = true;

phid=68.2840;

qMin = deg2rad([-phid; -90; -90]);     % joints 4:6
qMax = deg2rad([180-phid;  90;  90]);
dqMaxJ = deg2rad([120; 120; 120]);    % joints 4:6

useDqLimits=true;
%useCollision1=true;

% Weights
angleErr = @(des, act) atan2(sin(des-act)+0.000001, cos(des-act)+0.000001); % desired - actual
    
Qx    = diag([200, 200,  20]);        % running EE pose error
Qdx   = diag([  5,   5,   2]);        % running EE velocity error
Qf_x  = diag([2000,2000,2000]);        % terminal EE pose error
Qf_dx = diag([ 100, 100, 20]);        % terminal EE velocity error

R     = 0.02 * eye(nu);               % torque effort
Rdu   = 0.20 * eye(nu);               % smoothing on delta-u

% Light regularization (optional, helps numerics)
Qdq_arm = 0.02 * eye(3);              % penalize dq(4:6) a bit
Qq_arm  = 0.00 * eye(3);              % (usually keep 0 in task-space MPC)

% Initial state
x0 = [qin(:); dqin(:)];               % 12x1

% Reference
xref    = xgoal(:);
xdotref = [0;0;0];

% Warm-start (shift last solution)
persistent lastU
if isempty(lastU) || any(size(lastU) ~= [nu, N])
    lastU = zeros(nu, N);
end

% Shift previous solution one step
U0 = [lastU(:,2:end), lastU(:,end)];

% If warm start is basically zeros, build a cheap task-space PD guess
if norm(U0(:),2) < 1e-8
    U0 = build_taskspace_PD_seed(x0, xref, xdotref, N, dt, uMin, uMax);
end

z0 = reshape(U0, nu*N, 1);

% Decision variable bounds
lb = repmat(uMin, N, 1);
ub = repmat(uMax, N, 1);

% Setup and run fmincon
opts = optimoptions('fmincon', ...
    'Algorithm','sqp', ...
    'Display','off', ...
    'MaxIterations', 120, ...
    'MaxFunctionEvaluations', 2e5, ...
    'ConstraintTolerance', 1e-6, ...
    'StepTolerance', 1e-6);
[zstar,~,~,~] = fmincon(@cost_fun, z0, [],[],[],[], lb, ub, @nonlcon_fun, opts);

U = reshape(zstar, nu, N);
lastU = U;

% Optimal output trajectory rollout
X = zeros(nx, N+1);
X(:,1) = x0;
xk = x0;
for k = 1:N
    uk = U(:,k);
    xk = rk4_step(xk, uk, dt);
    X(:,k+1) = xk;
end

%%%%%%%%%%%%%%%%%%%%
% Helper functions %
%%%%%%%%%%%%%%%%%%%%

    function J = cost_fun(z)
        % % debug display
        % xee0 = ee_fk(x0(1:6));
        % disp([xref(:).'; xee0(:).'])

        Uloc = reshape(z, nu, N);

        J = 0;
        xk = x0;

        u_prev = Uloc(:,1); % for k=1 smoothing convention
        for k = 1:N
            uk = Uloc(:,k);

            q  = xk(1:6);
            dq = xk(7:12);

            % EE pose & velocity
            xee  = ee_fk(q);
            Jee  = ee_jacobian(q);
            xdot = Jee * dq;

            % Pose error with wrapped angle
            ex = xee - xref;
            ex(3) = angleErr(xref(3), xee(3));   % desired - actual, wrapped


            exdot = xdot - xdotref;

            % Regularization
            dq_arm = dq(4:6);
            q_arm  = q(4:6);
            
            % DEBUGGING, TEMP ADD THIS BLOCK
            % Avoiding joint limits
            % Soft barrier near joint limits (prevents pinning at bounds)
            margin = deg2rad(8);
            wlim   = 50;  % tune 10–500
            J = J + wlim * joint_limit_barrier(q_arm, qMin, qMax, margin);


            % Stage cost
            J = J + ex.'*Qx*ex + exdot.'*Qdx*exdot ...
                  + uk.'*R*uk ... 
                  + (uk - u_prev).'*Rdu*(uk - u_prev) ...
                  + dq_arm.'*Qdq_arm*dq_arm ...
                  + q_arm.'*Qq_arm*q_arm;

            u_prev = uk;

            % Propagate
            xk = rk4_step(xk, uk, dt);
        end

        % Terminal cost
        qN  = xk(1:6);
        dqN = xk(7:12);

        xN   = ee_fk(qN);
        JeeN = ee_jacobian(qN);
        xdotN = JeeN * dqN;

        eN = xN - xref;
        eN(3) = angleErr(xref(3), xN(3));    % desired - actual

        edN = xdotN - xdotref;

        J = J + eN.'*Qf_x*eN + edN.'*Qf_dx*edN;
        
        % % Anti-drift posture regulation
        % q_arm0 = x0(4:6);             % current arm posture at solve time
        % Wdrift = diag([0.0005 0.050 0.0005]);  % small
        % J = J + (q_arm - q_arm0).'*Wdrift*(q_arm - q_arm0);

    end

    function [c, ceq] = nonlcon_fun(z)
        % Enforce joint/dq limits along the predicted rollout
        % c <= 0, ceq == 0
        Uloc = reshape(z, nu, N);

        ceq = zeros(0,1);

        if ~(useJointLimits || useDqLimits)
            c = zeros(0,1);
            return;
        end

        % Worst-case size: per step add:
        %  - joint: (q_arm - qMax) (3) and (qMin - q_arm) (3) => 6
        %  - dq:    (dq_arm - dqMax) (3) and (-dq_arm - dqMax) (3) => 6
        % total 12 per step
        c = zeros((12+1)*N, 1); % 12 states, 1 collision check
        idx = 1;

        xk = x0;
        for k = 1:N
            q  = xk(1:6);
            dq = xk(7:12);

            q_arm  = q(4:6);
            dq_arm = dq(4:6);



            if useCollision1
                 % ---- collision constraint (1 per step) ----
                xee = ee_fk(q);          % [x; y; phi]
                xpt = xee(1);
                ypt = xee(2);
                
                margin = 0.1;  % meters
                sd = signedDistPointPolygon(xpt, ypt, obsX, obsY);  % + outside, 0 boundary, - inside
                
                % enforce sd >= margin  <=>  margin - sd <= 0
                c(idx) = margin - sd;
                idx = idx + 1;
            end



            if useJointLimits
                % q_arm <= qMax  -> q_arm - qMax <= 0
                c(idx:idx+2) = q_arm - qMax; idx = idx + 3;
                % q_arm >= qMin  -> qMin - q_arm <= 0
                c(idx:idx+2) = qMin - q_arm; idx = idx + 3;
            else
                c(idx:idx+5) = 0; idx = idx + 6;
            end

            if useDqLimits
                c(idx:idx+2) = dq_arm - dqMaxJ; idx = idx + 3;
                c(idx:idx+2) = -dq_arm - dqMaxJ; idx = idx + 3;
            else
                c(idx:idx+5) = 0; idx = idx + 6;
            end

            % propagate
            uk = Uloc(:,k);
            xk = rk4_step(xk, uk, dt);
        end
    end

    function Useed = build_taskspace_PD_seed(xstart, xref_loc, xdotref_loc, Nloc, h, uMinLoc, uMaxLoc)
        % Simple task-space PD seed mapped to arm torques via J^T
        Useed = zeros(nu, Nloc);

        % Gains for seed only (not the MPC weights)
        Kp_x = diag([200, 200, 40]);
        Kd_x = diag([ 30,  30, 10]);

        xk_loc = xstart;
        for kk = 1:Nloc
            q  = xk_loc(1:6);
            dq = xk_loc(7:12);

            xee  = ee_fk(q);
            Jee  = ee_jacobian(q);
            xdot = Jee * dq;

            ex = xref_loc - xee;
            ex(3) = angleErr(xref_loc(3), xee(3)); % desired - actual
            exdot = xdotref_loc - xdot;

            F = Kp_x*ex + Kd_x*exdot;

            Jee_act = Jee(:,4:6);
            tau = Jee_act.' * F; % 3x1

            % saturate
            tau = min(max(tau, uMinLoc), uMaxLoc);

            Useed(:,kk) = tau;

            xk_loc = rk4_step(xk_loc, tau, h);
        end
    end

    function xnext = rk4_step(x, tau_arm, h)
        % Control vector is tau on joints 4:6; pack into u6
        u6 = [0;0;0; tau_arm(:)];

        k1 = dynamics(x(1:6), x(7:12), u6);
        k2 = dynamics(x(1:6) + 0.5*h*k1(1:6),  x(7:12) + 0.5*h*k1(7:12),  u6);
        k3 = dynamics(x(1:6) + 0.5*h*k2(1:6),  x(7:12) + 0.5*h*k2(7:12),  u6);
        k4 = dynamics(x(1:6) +     h*k3(1:6),  x(7:12) +     h*k3(7:12),  u6);

        xnext = x + (h/6)*(k1 + 2*k2 + 2*k3 + k4);

        % (optional) clip extremely large dq to avoid numeric explosions
        dq_clip = 200; % rad/s hard safety clip
        xnext(7:12) = min(max(xnext(7:12), -dq_clip), dq_clip);
    end

    function dx = dynamics(q, dq, u6)
        ddq = ddq_from_MC(q, dq, u6);
        dx = [dq; ddq];
    end


% Model functions %
%%%%%%%%%%%%%%%%%%%

    % Nested: ddq_from_MC (fixed-size output)
    function ddq = ddq_from_MC(q,dq,u)
        ddq = zeros(6,1); 

        phi=68.2840*pi/180;
        q0=q(3); q1=q(4); q2=q(5); q3=q(6);
        dq0=dq(3); dq1=dq(4); dq2=dq(5); dq3=dq(6);

        % Robot parameters
        m0=16.9478; m1=0.3377; m2=0.3281; m3=0.0111;
        a0=0; a1=0.1933; a2=0.1933; a3=0.0621;
        b0=0.2304; b1=0.1117; b2=0.1057;  b3=0.0159;
        I0=0.2873; I1=0.004171; I2=0.003967; I3=0.00006722*10;

        % Inertia Matrix M
        M11 = m0 + m1 + m2 + m3;
        M12 = 0;
        M13 = (-a1 *m1 - m2* (a1 + b1) - m3* (a1 + b1))* cos(q0 + q1) + (-a2* m2 - m3 *(a2 + b2))* cos(q0 + q1 + q2)+ (-a3* m3) *cos(q0 + q1 + q2 + q3) + (-b0 *m1 - b0* m2 - b0* m3)* sin(phi + q0);
        M14 = (-a1 *m1 - m2* (a1 + b1) - m3* (a1 + b1)) *cos(q0 + q1) + (-a2* m2 - m3 *(a2 + b2)) *cos(q0 + q1 + q2)+ (-a3* m3)* cos(q0 + q1 + q2 + q3);
        M15 = (-a2 *m2 - a2 *m3 - b2 *m3) *cos(q0 + q1 + q2) + (-a3 *m3) *cos(q0 + q1 + q2 + q3);
        M16 = (-a3* m3) *cos(q0 + q1 + q2 + q3);
        M21 = 0;
        M22 = m0 + m1 + m2 + m3;
        M23 = (b0 *m1 + b0* m2 + b0 *m3)* cos(phi + q0) + (-a1* m1 - m2 *(a1 + b1) - m3 *(a1 + b1)) *sin(q0 + q1)+ (-a2 *m2 - m3 *(a2 + b2)) *sin(q0 + q1 + q2) + (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M24 = (-a1* m1 - m2 *(a1 + b1) - m3* (a1 + b1)) *sin(q0 + q1) + (-a2* m2 - m3* (a2 + b2))* sin(q0 + q1 + q2)+ (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M25 = (-a2 *m2 - a2 *m3 - b2* m3)* sin(q0 + q1 + q2) + (-a3 *m3) *sin(q0 + q1 + q2 + q3);
        M26 = (-a3* m3)* sin(q0 + q1 + q2 + q3);
        M31 = M13;
        M32 = M23;
        M33 = (2 *a1* a2* m2 + 2 *a1 *a2* m3 + 2 *a2* b1* m2 + 2 *a1* b2* m3 + 2* a2* b1* m3 + 2* b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3)+ (2* a1* b0 *m1 + 2 *a1* b0* m2 + 2 *a1* b0* m3 + 2* b0* b1* m2 + 2* b0 *b1 *m3)* sin(phi - q1)+ (-2 *a2* b0* m2 - 2 *a2* b0* m3 - 2* b0* b2* m3)* sin(q1 - phi + q2) + (-2 *a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I0 + I1 + I2 + I3 + a1^2* m1 + a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b0^2* m1 + b0^2* m2+ b0^2 *m3 + b1^2 *m2 + b1^2* m3 + b2^2 *m3 + 2 *a1* b1 *m2 + 2 *a1* b1* m3 + 2 *a2 *b2* m3;
        M34 = (2* a1* a2* m2 + 2* a1 *a2* m3 + 2* a2* b1* m2 + 2 *a1* b2* m3 + 2 *a2 *b1 *m3 + 2* b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3)+ (a1* b0* m1 + a1* b0* m2 + a1* b0* m3 + b0* b1* m2 + b0* b1* m3)* sin(phi - q1)+ (-1*a2* b0* m2 - a2* b0* m3 - b0* b2* m3)* sin(q1 - phi + q2) + (-a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I1 + I2 + I3 + a1^2* m1 + a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2 *m3 + a3^2 *m3 + b1^2* m2 + b1^2 *m3 + b2^2* m3+ 2* a1* b1* m2 + 2* a1 *b1* m3 + 2 *a2 *b2* m3;
        M35 = (a1* a2* m2 + a1* a2 *m3 + a2* b1* m2 + a1* b2* m3 + a2* b1* m3 + b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2 *a3 *b2* m3) *cos(q3) + (a1 *a3* m3 + a3* b1* m3) *cos(q2 + q3)+ (-a2* b0* m2 - a2* b0* m3 - b0* b2* m3) *sin(q1 - phi + q2) + (-a3* b0* m3)* sin(q1 - phi + q2 + q3)+ I2 + I3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b2^2* m3 + 2* a2* b2* m3;
        M36 = (a2* a3* m3 + a3* b2* m3)* cos(q3) + (a1* a3* m3 + a3 *b1 *m3)* cos(q2 + q3)+ (-a3* b0* m3) *sin(q1 - phi + q2 + q3) + m3 *a3^2 + I3;
        M41 = M14;
        M42 = M24;
        M43 = M34;
        M44 = (2 *a1 *a2 *m2 + 2* a1* a2* m3 + 2* a2 *b1* m2 + 2* a1* b2* m3 + 2* a2* b1* m3 + 2 *b1 *b2 *m3)* cos(q2)+ (2* a2* a3* m3 + 2 *a3 *b2* m3)* cos(q3) + (2* a1* a3* m3 + 2* a3* b1* m3)* cos(q2 + q3) + I1 + I2 + I3 + a1^2* m1+ a1^2* m2 + a1^2* m3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b1^2* m2 + b1^2* m3 + b2^2 *m3 + 2 *a1* b1* m2 + 2 *a1* b1* m3+ 2* a2* b2* m3;
        M45 = (a1* a2* m2 + a1* a2* m3 + a2* b1* m2 + a1* b2* m3 + a2* b1* m3 + b1* b2* m3)* cos(q2)+ (2* a2* a3* m3 + 2* a3* b2 *m3) *cos(q3) + (a1 *a3* m3 + a3* b1* m3)* cos(q2 + q3) + I2 + I3 + a2^2* m2 + a2^2 *m3+ a3^2 *m3 + b2^2 *m3 + 2 *a2* b2 *m3;
        M46 = (a2* a3 *m3 + a3* b2* m3) *cos(q3) + (a1 *a3* m3 + a3 *b1 *m3) *cos(q2 + q3) + m3* a3^2 + I3;
        M51 = M15;
        M52 = M25;
        M53 = M35;
        M54 = M45;
        M55 = (2* a2* a3* m3 + 2* a3 *b2* m3) *cos(q3) + I2 + I3 + a2^2* m2 + a2^2* m3 + a3^2* m3 + b2^2* m3 + 2 *a2 *b2 *m3;
        M56 = (a2 *a3 *m3 + a3 *b2 *m3) *cos(q3) + m3 *a3^2 + I3;
        M61 = M16;
        M62 = M26;
        M63 = M36;
        M64 = M46;
        M65 = M56;
        M66 = m3* a3^2 + I3;
        M=[M11,M12,M13,M14,M15,M16;M21,M22,M23,M24,M25,M26;M31,M32,M33,M34,M35,M36;M41,M42,M43,M44,M45,M46;M51,M52,M53,M54,M55,M56;M61,M62,M63,M64,M65,M66];
        
        
 C11 = 0;
            C12 = 0;
            C13 = (-dq0*(b0*m1 + b0*m2 + b0*m3)) * cos(q(5) + q0) ...
                + (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * cos(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a1 + b1)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*dq0 - a2*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * cos(q0 + q1 + q2 + q3 + pi/2);
        
            C14 = (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * cos(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a2*m3*dq0 - a2*m3*dq1 - a2*m3*dq2 - a2*m3*dq3) * cos(q0 + q1 + q2 + q3 + pi/2);
        
            C15 = (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * cos(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*(dq0+dq1+dq2+dq3)) * cos(q0 + q1 + q2 + q3 + pi/2);
        
            C16 = (a3*m3*(dq0 + dq1 + dq2 + dq3)) * sin(q0 + q1 + q2 + q3);
        
            C21 = 0;
            C22 = 0;
            C23 = (-dq0*(b0*m1 + b0*m2 + b0*m3)) * sin(q(5) + q0) ...
                + (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * sin(q0 + q1 + pi/2) ...
                + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
                + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);
        
        C24 = (-dq0*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1)) - dq1*(a1*m1 + m2*(a1 + b1) + m3*(a1 + b1))) * sin(q0 + q1 + pi/2) ...
            + (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
            + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);
        
        C25 = (-dq0*(a2*m2 + m3*(a2 + b2)) - dq1*(a2*m2 + m3*(a2 + b2)) - dq2*(a2*m2 + m3*(a2 + b2))) * sin(q0 + q1 + q2 + pi/2) ...
            + (-a3*m3*dq0 - a3*m3*dq1 - a3*m3*dq2 - a3*m3*dq3) * sin(q0 + q1 + q2 + q3 + pi/2);
        
        C26 = (-a3*m3*(dq0 + dq1 + dq2 + dq3)) * cos(q0 + q1 + q2 + q3);
        
        C31 = 0;
        C32 = 0;
        
        C33 = (-a1*b0*m1*dq1 - a1*b0*m2*dq1 - a1*b0*m3*dq1 - b0*b1*m3*dq1 - b0*b1*m3*dq1) * cos(q0 - q1) ...
            + (-a2*b0*m2*dq1 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);
        
        C34 = (-a1*b0*m1*dq0 - a1*b0*m1*dq1 - a1*b0*m2*dq0 - a1*b0*m2*dq1 - a1*b0*m3*dq0 - a1*b0*m3*dq1 ...
            - b0*b1*m2*dq0 - b0*b1*m2*dq1 - b0*b1*m3*dq0 - b0*b1*m3*dq1) * cos(q0 - q1) ...
            + (-a2*b0*m2*dq0 - a2*b0*m2*dq1 - a2*b0*m3*dq0 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 ...
            - b0*b2*m3*dq0 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq0 - a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a3*a1*m3*dq3) * sin(q2 + q3);
        
        C35 = (-a2*b0*m2*dq0 - a2*b0*m2*dq1 - a2*b0*m3*dq0 - a2*b0*m2*dq2 - a2*b0*m3*dq1 - a2*b0*m3*dq2 ...
            - b0*b2*m3*dq0 - b0*b2*m3*dq1 - b0*b2*m3*dq2) * cos(q1 - q0 + q2) ...
            + (-a3*b0*m3*dq0 - a3*b0*m3*dq1 - a3*b0*m3*dq2 - a3*b0*m3*dq3) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq0 - a1*b2*m3*dq0 - a2*b1*m2*dq1 - a2*b1*m3*dq0 - a1*b2*m3*dq1 - a2*b1*m2*dq2 ...
            - a2*b1*m3*dq1 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq0) * sin(q2) ...
            + (-b1*b2*m3*dq1 - b1*b2*m3*dq2 - a1*a2*m2*dq0 - a1*a2*m2*dq1 - a1*a2*m3*dq0 - a1*a2*m2*dq2 ...
            - a1*a2*m3*dq1 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq0 - a3*b1*m3*dq1 - a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq0 - a1*a3*m3*dq1 ...
            - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);
        
        C36 = (-a3*b0*m3*(dq0 + dq1 + dq2 + dq3)) * cos(q1 - q0 + q2 + q3) ...
            + (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3) ...
            + (-a3*m3*(a1 + b1)*(dq0 + dq1 + dq2 + dq3)) * sin(q2 + q3);
        
        C41 = 0;
        C42 = 0;
        
        C43 = (a1*b0*m1*dq0 + a1*b0*m2*dq0 + a1*b0*m3*dq0 + b0*b1*m2*dq0 + b0*b1*m3*dq0) * cos(q0 - q1) ...
            + (a2*b0*m2*dq0 + a2*b0*m3*dq0 + b0*b2*m3*dq0) * cos(q1 - q0 + q2) ...
            + (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);
        
        
        C44 = (-a2*b1*m2*dq2 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq2 - a1*a2*m2*dq2 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);
        
        C45 = (-a2*b1*m2*dq0 - a1*b2*m3*dq0 - a2*b1*m2*dq1 - a2*b1*m3*dq0 - a1*b2*m3*dq1 - a2*b1*m2*dq2 ...
            - a2*b1*m3*dq1 - a1*b2*m3*dq2 - a2*b1*m3*dq2 - b1*b2*m3*dq0) * sin(q2) ...
            + (-b1*b2*m3*dq1 - b1*b2*m3*dq2 - a1*a2*m2*dq0 - a1*a2*m2*dq1 - a1*a2*m3*dq0 ...
            - a1*a2*m2*dq2 - a1*a2*m3*dq1 - a1*a2*m3*dq2) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (-a3*b1*m3*dq0 - a3*b1*m3*dq1 - a3*b1*m3*dq2 - a3*b1*m3*dq3 - a1*a3*m3*dq0 ...
            - a1*a3*m3*dq1 - a1*a3*m3*dq2 - a1*a3*m3*dq3) * sin(q2 + q3);
        
        C46 = (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3) ...
            + (-a3*m3*(a1 + b1)*(dq0 + dq1 + dq2 + dq3)) * sin(q2 + q3);
        
        C51 = 0;
        
        C52 = 0;
        
        C53 = (a2*b0*m2*dq0 + a2*b0*m3*dq0 + b0*b2*m3*dq0) * cos(q1 - q0 + q2) ...
            + (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (a2*b1*m2*dq0 + a1*b2*m3*dq0 + a2*b1*m2*dq1 + a2*b1*m3*dq0 + a1*b2*m3*dq1 + a2*b1*m3*dq1 ...
            + b1*b2*m3*dq0 + b1*b2*m3*dq1 + a1*a2*m2*dq0 + a1*a2*m2*dq1 + a1*a2*m3*dq0 + a1*a2*m3*dq1) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (a3*b1*m3*dq0 + a3*b1*m3*dq1 + a1*a3*m3*dq0 + a1*a3*m3*dq1) * sin(q2 + q3);
        
        C54 = (a2*b1*m2*dq0 + a1*b2*m3*dq0 + a2*b1*m2*dq1 + a2*b1*m3*dq0 + a1*b2*m3*dq1 + a2*b1*m3*dq1 ...
            + b1*b2*m3*dq0 + b1*b2*m3*dq1 + a1*a2*m2*dq0 + a1*a2*m2*dq1 + a1*a2*m3*dq0 + a1*a2*m3*dq1) * sin(q2) ...
            + (-a3*b2*m3*dq3 - a2*a3*m3*dq3) * sin(q3) ...
            + (a3*b1*m3*dq0 + a3*b1*m3*dq1 + a1*a3*m3*dq0 + a1*a3*m3*dq1) * sin(q2 + q3);
        
        C55 = (-a3*m3*dq3*(a2 + b2)) * sin(q3);
        
        C56 = (-a3*m3*(a2 + b2)*(dq0 + dq1 + dq2 + dq3)) * sin(q3);
        
        C61 = 0;
        
        C62 = 0;
        
        C63 = (a3*b0*m3*dq0) * cos(q1 - q0 + q2 + q3) ...
            + (a3*m3*(a2*dq0 + a2*dq1 + a2*dq2 + b2*dq0 + b2*dq1 + b2*dq2)) * sin(q3) ...
            + (a3*m3*(a1*dq0 + a1*dq1 + b1*dq0 + b1*dq1)) * sin(q2 + q3);
        
        C64 = (a3*m3*(a2*dq0 + a2*dq1 + a2*dq2 + b2*dq0 + b2*dq1 + b2*dq2)) * sin(q3) ...
            + (a3*m3*(a1*dq0 + a1*dq1 + b1*dq0 + b1*dq1)) * sin(q2 + q3);
        
        C65 = (a3* m3 *(a2 + b2)* ( dq0 + dq1 + dq2))*sin(q3);
        C66=0;     

        C = [0, 0, C13, C14, C15, C16;
             0, 0, C23, C24, C25, C26;
             0, 0, C33, C34, C35, C36;
             0, 0, C43, C44, C45, C46;
             0, 0, C53, C54, C55, C56;
             0, 0, C63, C64, C65, 0];
                
        ddq2=u-C*dq;    
        
        rc = rcond(M);
        if ~(isfinite(rc)) || rc < 1e-9
            M = M + 1e-6*eye(6);
        end

        ddq=M\ddq2;
        % % Saturate joint limits
        % fric=[0;0;0;1;1;1];
        % xlim=[0;0;0;pi/2;pi/2;pi/2];
        % 
        % for r=4:6
        %     if abs(q(r))>=xlim(r)
        %         % Fric
        %         ddq(r)=ddq(r)-fric(r)*dq(r);
        %         % Displacement
        %         ddq(r)=ddq(r)-fric(r)*(q(r)-xlim(r));
        %     end
        % end
    
    end

    function xee = ee_fk(q)
        x_base = q(1); y_base = q(2); th0 = q(3);
        q1 = q(4); q2 = q(5); q3 = q(6);
        phi=68.2840*pi/180;
        
    
        b0=0.2304;
        R0 = [cos(th0) -sin(th0);
              sin(th0)  cos(th0)];
    
        % Arm length geometric model
        L1 = 0.1933 + 0.1117;
        L2 = 0.1933 + 0.1057;
        L3 = 0.0621 + 0.0159;
    
        th1 = th0 + q1 + phi;
        th2 = th1 + q2;
        th3 = th2 + q3;
    
        p_root = [x_base; y_base] + R0*[b0*cos(phi); b0*sin(phi)];
        p_arm  = [ L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
                   L1*sin(th1) + L2*sin(th2) + L3*sin(th3) ];
    
        x_e = p_root(1) + p_arm(1);
        y_e = p_root(2) + p_arm(2);
    
        xee = [x_e; y_e; th3];
    end


    function Jee = ee_jacobian(q)
        %#codegen
        a0=0.15;
        b0=0.2304;
        phi=68.2840*pi/180;
        th0 = q(3);
        q1  = q(4);
        q2  = q(5);
        q3  = q(6);

        L1 = 0.1933;
        L2 = 0.1933;
        L3 = 0.0621;

        % Complete link lengths
        L1 = L1+0.1117;
        L2 = L2+0.1057;
        L3 = L3+0.0159;

        th1 = th0 + q1 + phi;
        th2 = th1 + q2;
        th3 = th2 + q3;

        % d[x;y] wrt base x,y
        J_pos_base = [1,0;
                      0,1];

        % d[x;y] wrt th0,q1,q2,q3


        dxe_root = -b0*sin(th0);
        dye_root =  b0*cos(th0);
        
        dxe_arm  = -L1*sin(th1) - L2*sin(th2) - L3*sin(th3);
        dye_arm  =  L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
        
        dxe_dth0 = dxe_root + dxe_arm;
        dye_dth0 = dye_root + dye_arm;


        %dxe_dth0 = -L1*sin(th1) - L2*sin(th2) - L3*sin(th3);
        dxe_dq1  = dxe_dth0;
        dxe_dq2  = -L2*sin(th2) - L3*sin(th3);
        dxe_dq3  = -L3*sin(th3);

        %dye_dth0 =  L1*cos(th1) + L2*cos(th2) + L3*cos(th3);
        dye_dq1  = dye_dth0;
        dye_dq2  =  L2*cos(th2) + L3*cos(th3);
        dye_dq3  =  L3*cos(th3);

        J_pos_angles = [dxe_dth0, dxe_dq1, dxe_dq2, dxe_dq3;
                        dye_dth0, dye_dq1, dye_dq2, dye_dq3];

        % phi = th0+q1+q2+q3  => phi_dot = [0 0 1 1 1 1] * dq
        J_phi = [0 0 1 1 1 1];

        Jee = [J_pos_base, J_pos_angles;
               J_phi];
    end


    %Foct functiobn - avoid limits (added for debugging)
    function Jlim = joint_limit_barrier(q, qMin, qMax, margin)
        Jlim = 0;
        for i = 1:3
            dLo = q(i) - (qMin(i) + margin);
            dHi = (qMax(i) - margin) - q(i);
    
            if dLo < 0
                Jlim = Jlim + (dLo/margin)^2;
            end
            if dHi < 0
                Jlim = Jlim + (dHi/margin)^2;
            end
        end
    end



    function sd = signedDistPointPolygon(x, y, polyX, polyY)
    % signed distance: positive outside, 0 on boundary, negative inside
    [in, on] = inpolygon(x, y, polyX, polyY);
    d = distPointToPolygonEdges(x, y, polyX, polyY);  % >= 0

    if in || on
        sd = -d;
    else
        sd = d;
    end
end

function dmin = distPointToPolygonEdges(x, y, polyX, polyY)
    % polyX/polyY expected closed (last = first). If not closed, still works.
    n = numel(polyX);
    dmin = inf;

    for i = 1:(n-1)
        x1 = polyX(i);   y1 = polyY(i);
        x2 = polyX(i+1); y2 = polyY(i+1);
        d = distPointToSegment(x, y, x1, y1, x2, y2);
        if d < dmin
            dmin = d;
        end
    end

    % If not explicitly closed, include last->first segment too
    if polyX(1) ~= polyX(end) || polyY(1) ~= polyY(end)
        d = distPointToSegment(x, y, polyX(end), polyY(end), polyX(1), polyY(1));
        if d < dmin
            dmin = d;
        end
    end
end

function d = distPointToSegment(px, py, x1, y1, x2, y2)
    % distance from point P to segment AB
    vx = x2 - x1;  vy = y2 - y1;
    wx = px - x1;  wy = py - y1;

    vv = vx*vx + vy*vy;
    if vv < 1e-12
        % degenerate segment
        dx = px - x1; dy = py - y1;
        d = sqrt(dx*dx + dy*dy);
        return;
    end

    t = (wx*vx + wy*vy) / vv;
    t = min(1, max(0, t));

    projx = x1 + t*vx;
    projy = y1 + t*vy;

    dx = px - projx; dy = py - projy;
    d = sqrt(dx*dx + dy*dy);
end




end
