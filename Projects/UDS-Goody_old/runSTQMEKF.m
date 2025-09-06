function [y, H, x, P, V] = runSTQMEKF(z, dt, Chaser, x, P, V, Q, R, r, rho, dmax)
%% Constants
a = 1;
f = 1;
Fargs.m = 12;
Fargs.J = 0.2;
Hargs.red = Chaser;

%% Call the MEKF
[x, P, y, H, V] = STQMEKF(z, dt, x, P, a, f, Q, R, r, V, rho, dmax, @qmekfProp, Fargs, @qmekfMeas, Hargs);
end
