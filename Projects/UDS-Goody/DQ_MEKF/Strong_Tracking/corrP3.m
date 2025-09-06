function L = corrP3(V,R,H,Q,Pzz)
    % Inputs:
    % Pzz    - Time Updated Pzz
    % H      - Measurement Jacobian
    % Q      - Process covar
    % R      - Measurement covar
    % V      - True Pzz
    % Find lambda (scalar form)
    M = Pzz; 
    N = V - R - H*Q*H';
    lambda2 = trace(N) / trace(M); % This calculates lambda^2
    L = sqrt(max(1,lambda2)); % The covarience can only increase when there is a manuver
end