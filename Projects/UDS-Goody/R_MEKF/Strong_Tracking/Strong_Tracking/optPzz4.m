function [V,beta] = optPzz4(V,k,beta,rho,y)
% Inputs:
% V      - True Pzz from last time step
% beta   - Forgetting factor from last time step
% k      - Time step number
% rho    - Tunable parameter 0 < rho < 1
% y      - residual from current time step
%

    % For Initial Condidtions
    if det(V) == 0
            V = beta*(rho*V + y*y');
    end

    % Update beta
    beta = (rho - 1) / (rho^k - 1);
    
    % Find True Pzz
    V = (1-beta)*(rho*V) + beta*(y*y');     

end