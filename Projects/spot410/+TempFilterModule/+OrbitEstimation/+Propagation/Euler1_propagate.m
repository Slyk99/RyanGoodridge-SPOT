function [state_next, Phi_next, G] = Euler1_propagate(state, dt, u, args)
% First-order Euler propagation 
%
% Inputs
% State Vector:             states  = [x, y, theta, dx, dy, dtheta, theta_s, w_s, bias]^T;
% Time Step:                dt      = (Scalar)
% Input vector:             u       = [ux, uy, uz]^T;
% Function Arguments:
%                           theta_s = Angle of servicer 
%                           w_s     = Angle rate of servicer
%                           m_s     = Mass of servicer
%                           J_s     = Inertia of servicer
%
% Outputs:
% State_next:   state vector at next step
% Phi_next:     STM at next step
% G:            Noise Distribution Matrix
%

% Unpack Arguments
m_s     = args.m_s;
J_s     = args.J_s;

% State update 
dx = TempFilterModule.OrbitEstimation.Propagation.calcRates(state, u, m_s, J_s);
state_next = state + dx*dt;

%% Noise Distribution Matrix
% Noise is modeled as x = Ax + B(u + w)
G = [zeros(4,5);
     eye(5)];

%% STM update 
omega_s_dot = u(3)/J_s;
F = TempFilterModule.OrbitEstimation.Propagation.Partial(state_next, omega_s_dot);

n = size(F,1);
m = size(G,2);

% Augmented matrix for expm
M = [F, G;
     zeros(m, n+m)];

% Matrix exponential
Md = expm(M*dt);

% Extract results
Phi_next = Md(1:n, 1:n);
G  = Md(1:n, n+1:n+m);
end
