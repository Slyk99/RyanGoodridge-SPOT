function [V, lambda] = srtongTracking(V, y, Pzz, R, rho)
% Note: in the literature this gives lambda^2 however 
% P = lambda^2*P_prediction, so the square was left out for simplicity
%
if det(V) == 0
    V = y*y';
else
    V = rho*(rho*V + y*y')/(1+rho);
end

M = Pzz;
N = V - R;

lambda = trace(N)/trace(M);
lambda = max(1, lambda);
end