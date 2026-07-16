function V = optPzz3(Pzz,rho,y)
% Inputs:
% Pzz      - Current Pzz
% rho    - Tunable parameter 0 < rho < 1
% y      - residual from current time step
%
    V = rho * Pzz + (1 - rho)*(y*y');
end