function L = corrP4DQ(P_k, H, R, V)
    % Inputs:
    % P_K    - Time Updated Covar
    % H      - Measurement Jacobian
    % R      - Measurement covar
    % V      - True Pzz
    %
    % Find lambda Matrix
    % Initial guess for Lambda
    n = length(P_k);
    Lambda0 = ones(n/2,1); % Starting with an identity scaled by 2

    % Solve using Levenberg-Marquardt
    options = optimoptions('lsqnonlin', 'Algorithm', 'levenberg-marquardt','display','off');
    lb = ones(n/2,1);
    % Call lsqnonlin.
    Lambda_sol = lsqnonlin(@(x) objFun(x, eye(6), P_k, H, R, V), Lambda0, lb, [], options);
    L = blkdiag(diag(Lambda_sol(1:6)), diag(Lambda_sol(1:6)));
end

function res = objFun(diagLambda, Izz, P, H, R, V)
    % Convert the vector of diagonal entries into a diagonal matrix Lambda.
    Lambda = blkdiag(diag(diagLambda(1:6)), ...
                     diag(diagLambda(1:6)));
    
    % Update the state covariance using the matrix fading factor.
    P_new = Lambda * P * Lambda;
    
    % Compute the measurement covariance.
    Pzz = H * P_new * H' + R;
    
    % Compute the residual. The goal is to have Pzz^{-1} * V as close as possible
    % to the identity Izz.
    % (Depending on your filter design, you may have a different function to minimize.)
    resMat = Izz - inv(Pzz) * V;
    
    % Return the residual as a vector (by stacking the matrix columns).
    res = resMat(:);
end
