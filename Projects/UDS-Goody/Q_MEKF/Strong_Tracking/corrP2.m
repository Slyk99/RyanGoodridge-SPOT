function L = corrP2(V,R,H,Q,P_k)
    % Inputs:
    % P_K    - Time Updated Covar
    % H      - Measurement Jacobian
    % Q      - Process covar
    % R      - Measurement covar
    % V      - True Pzz
    % Find lambda (scalar form)
    M = H*Q*H'; 
    N = V - R - H*P_k*H';
    lambda2 = trace(N) / trace(M); % This calculates lambda^2
    L = sqrt(max(1,lambda2)); % The covarience can only increase when there is a manuver
end