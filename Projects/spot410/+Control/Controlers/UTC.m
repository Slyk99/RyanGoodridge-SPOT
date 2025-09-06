function [u, P] = UTC(dt, x_ref, x_act, P, W0, Q, R, m, CTLHndle, DynHndle, Params)
% This function implements the one step unscented transform controller 

% Predict the control input
u_bar = CTLHndle(x_ref, x_act, Params);

% Generate weights
W = [W0; ones(2*m,1)*(1 - W0)/(2*m)];

% Generate sigma points
L = chol(P * (m / (1 - W0)))';

U = [u_bar, bsxfun(@plus, u_bar, L), bsxfun(@minus, u_bar, L)];

% Generate sigma points for Y
Y = zeros(length(x_act), 2*m+1);
for i = 1:1:2*m+1
    Y(:,i) = DynHndle(x_act, U(:,i), dt, Params);
end

u_bar = U * W; % Predicted input mean
y_bar = Y * W; % Predicted state mean

U_diff = U - u_bar;
P_bar = U_diff * diag(W) * U_diff' + Q; 

Y_diff = Y - y_bar;
P_yy = Y_diff * diag(W) * Y_diff' + R;
P_uy = U_diff * diag(W) * Y_diff'; 

K = P_uy/P_yy;

u = u_bar + K*(x_ref - y_bar);

P = P_bar - K*P_yy*K';
end