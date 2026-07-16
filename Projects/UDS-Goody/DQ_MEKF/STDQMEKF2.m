function [x_new, P_new, y, H, V] = STDQMEKF(z_meas, dt, x, P, Q, R, V, r, rho, dmax, dq_red,Fhndl,Fargs)
% DQMEKF implements a dual quaternion MEKF.
%
%   [x, P] = DQMEKF(z_meas, dt, x, P, Q, R)
%
% Inputs:
%   z_meas - measured dual quaternion (8x1 vector: [q_r; q_d], scalarFirst)
%   dt     - time step (seconds)
%   x      - previous state (14x1): [q_r (4x1); q_d (4x1); b_omega (3x1); b_v (3x1)]
%   P      - previous covariance (12x12) corresponding to error state delta_x
%   Q      - process noise covariance (12x12, discrete)
%   R      - measurement noise covariance (6x6)
%
% Outputs:
%   x      - updated state (14x1)
%   P      - updated covariance (12x12)
%
% This implementation assumes no velocity measurements. The effective twist is
% then -[b_omega; b_v]. The pose is propagated using a Cayley-transform update.
%
% Author: Ryan Goodridge
% Date: 3/01/2025
%

%% Time Update
[x_k, Phi] = Fhndl(x, dt, Fargs); % State transition function
P_k = Phi * P * Phi' + Q;

%% Measurement Update
% Inflate noise of state to reduce effects of quantization
if ~anynan(z_meas)
    C = C3((rand(1,1)-0.5)*r);
    T = [C, zeros(3,1); zeros(1,3), 1];
    delta_dq = htform2Dq(T,'scalarFirst');
    z_meas = dqMultiply(delta_dq,z_meas,'scalarFirst');
    else
    x_new = x_k;
    P_new = P_k;
    y = NaN(6,1);
    H = [eye(6), zeros(6)];
    V = H*P_k*H' + R;
    return
end

% dqInv(z_pred) ⊗ (z_meas ⊗ dq_red)
q_pred_inv = dqInv([x_k(1:4), x_k(5:8)], 'scalarFirst');
z_meas = dqMultiply(dq_red,z_meas,'scalarFirst');
delta_q = dqMultiply(q_pred_inv, z_meas, 'scalarFirst'); % [z_meas(1:4), z_meas(5:8)]
delta_q = smalldq(delta_q,'scalarFirst');

% Extract the vector (imaginary) parts of the real and dual components:
y = [ delta_q(2:4, 1);
      delta_q(2:4, 2)];   % 6x1 innovation vector

% Measurement sensitivity matrix:
H = [eye(6), zeros(6)];

%% Mahalanobis distance
    [reject, ~] = Mahalanobis2(y, H * P_k * H' + R, dmax);

    if reject
        x_new = x_k;
        P_new = P_k ;
        y = NaN(6,1);
        H = [eye(6), zeros(6)];
        V = H*P_k*H' + R;
        return
    end

%% ST Algorythm
% Find better estimate of S
if reject
else
    V = optPzz1(V,rho,y);
end
% V = optPzz3(Pzz,rho,y);

% Find Lambda
% Pzz = H * P_k * H' + R;
% L = corrP1(V,Pzz,R);
% L = corrP2(V,R,H,Q,P_k);
% L = corrP3(V,R,H,Q,Pzz);
L = corrP4DQ(P_k, H, R, V);

% Corrct Covar
P_k = L*P_k*L;
V = rho*V;
    
%% DQ EKF Update
% Kalman gain:
Pzz = H * P_k * H' + R;
K = P_k * H' / Pzz;

% Update covariance (Joseph form):
I12 = eye(12);
P_new = (I12 - K * H) * P_k * (I12 - K * H)' + K * R * K';

% Compute error state correction:
delta_x = K * y;  % 12x1 vector

%% State Correction
dq_corr = findScalar(delta_x(1:6));

% Update pose: multiplicative update
q_updated = dqMultiply([x_k(1:4), x_k(5:8)], dq_corr, 'scalarFirst');

% Update bias additively:
b_omega_new = x_k(9:11) + delta_x(7:9);
b_v_new     = x_k(12:14) + delta_x(10:12);

% Assemble updated state:
x_new = [ q_updated(:,1); q_updated(:,2); b_omega_new; b_v_new ];
end

