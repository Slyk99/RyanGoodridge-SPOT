function [Up, Dp, K] = modifiedAgeeTurner(U, D, ri, Hi, tol)
    % modifiedAgeeTurner   Modified Agee-Turner rank-one UD update
    %   [Up, Dp, K] = modifiedAgeeTurner(U, D, ri, Hi)
    %   Inputs:
    %     U  : n-by-n unit upper-triangular prior factor (tilde U)
    %     D  : n-by-n diagonal prior factor (tilde D)
    %     ri : scalar measurement noise variance r_i
    %     Hi : measurement vector (n-by-1)
    %   Outputs:
    %     Up : updated n-by-n unit upper-triangular factor (U^+)
    %     Dp : updated n-by-n diagonal factor (D^+)
    %     K  : n-by-1 Kalman gain vector
    %
    % Preallocate n by 1 vectors
    Hi = Hi(:);
    n = length(Hi);
    alpha = zeros(n,1);
    dvec  = zeros(n,1);   % holds updated diagonal entries 

    % ensure Hi is a column vector
    if nargin == 4
        tol = eps;
    end
    
    w = U'*Hi;
    v = D*w;
    
    % Initial values
    alpha(1) = ri + v(1)*w(1);
    alpha(1) = max(alpha(1), tol); % Clip poor conditioned values
    dvec(1)  = (ri * D(1,1)) / alpha(1);
    Up   = U;
    Kacc = v(1) * Up(:,1);        % n-by-1 vector
    
    for i = 2:1:n
        alpha(i) = alpha(i-1) + v(i)*w(i);
        alpha(i) = max(alpha(i), tol); % Clip poor conditioned values
        dvec(i) = (alpha(i-1)/alpha(i))*D(i,i);
        
        lambda = - w(i)/alpha(i-1);
        Up(:,i) = U(:,i) + lambda*Kacc;
        Kacc = Kacc + v(i)*U(:,i);
    end % End i loop
    K = Kacc/alpha(end);
    Dp = diag(dvec);
end % End function