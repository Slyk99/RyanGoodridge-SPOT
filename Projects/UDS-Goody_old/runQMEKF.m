function [y, H, x, P] = runQMEKF(z, dt, Chaser, x, P, Q, R, r, dmax)
%% Constants
a = 1;
f = 1;
Fargs.m = 12;
Fargs.J = 0.2;
Hargs.red = Chaser;

%% Call the MEKF
[x, P, y, H] = QMEKF(z, dt, x, P, a, f, Q, R, r, dmax, @qmekfProp, Fargs, @qmekfMeas, Hargs);

end