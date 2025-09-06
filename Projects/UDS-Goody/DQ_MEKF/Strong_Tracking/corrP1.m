function L = corrP1(V,Pzz,R)
    % Inputs:
    % Pzz    - Predicted Pzz
    % R      - Measurement covar
    % V      - True Pzz

    % Find lambda (scalar form)
    M = Pzz; % redundant code, but required for theory
    N = V - R;
    lambda2 = trace(N) / trace(M); % This calculates lambda^2
    L = sqrt(max(1,lambda2)); % The covarience can only increase when there is a manuver
end