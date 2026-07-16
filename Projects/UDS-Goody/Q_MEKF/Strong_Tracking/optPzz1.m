function V = optPzz1(V,rho,y)
% Inputs:
% V      - True Pzz from last time step
% rho    - Tunable parameter 0 < rho < 1
% y      - residual from current time step
%
    % For Initial Condidtions
    if det(V) == 0
        V = y*y';
    end

    V = (rho*V + y*y') / (1 + rho);
end