function [y, prev] = pseDerivative(v, prev, Ts, tau)
% pseDerivative  - smoothed derivative via diff + 1st-order LPF
% v   - current velocity sample (scalar or Nx1 vector)
% Ts  - sample time
% tau - filter time constant (seconds). Suggested: 0.01 .. 0.2 depending on signal freq.
%
% Implementation: compute backward difference then apply
% a discrete 1st-order low-pass: y[k] = alpha*y[k-1] + (1-alpha)*diff/Ts
% where alpha = tau/(tau+Ts).

v_prev = prev(:,1);
y_prev = prev(:,2);

% compute backward difference (handle first sample gracefully)
if Ts == 0
    Ts = 0.00001;
end
dv = (v - v_prev) / Ts;

% low-pass filter parameter
alpha = tau / (tau + Ts);
% update output (elementwise)
y = alpha .* y_prev + (1 - alpha) .* dv;

% update persistent states
prev = [v, y];
end
