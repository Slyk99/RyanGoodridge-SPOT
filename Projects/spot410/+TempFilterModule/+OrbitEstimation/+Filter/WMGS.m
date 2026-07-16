function [Ubar, Dbar] = WMGS(W, D, tol)
    % WMGS  Weighted Modified Gram-Schmidt
    % Used to propagate a UD kalman filter
    %   [Wbar, Dbar] = WMGS(W, D)
    %   Inputs:
    %     W   : n-by-m matrix whose ROWS are w1..wn (F*U, G)
    %     D   : m-by-m diagonal weighting matrix blkdiag(D,Q)
    %     tol : scalar value for the tolerance 
    %   Outputs:
    %     Wbar: n-by-n unit upper-triangular matrix
    %     Dbar: n-by-n diagonal matrix
    %
    if nargin == 2
        tol = eps;
    end

    [n, m] = size(W);
    U    = eye(n);          % will contain u(k,j) for j>k, ones on diag
    V    = zeros(n, m);     % rows will be v1..vn
    dvec = zeros(n,1);      % diagonal entries for Dbar

    for k = n: -1: 1
        wk = W(k,:);
        
        if k == n
            V(k,:) = wk;
        else
            acc = zeros(1,m);
            for j = k+1:1:n
                vj = V(j,:);
                denom = vj * D * vj.';
                if abs(denom) < tol
                    % near-zero norm -> skip projection
                    ujk = 0;
                else
                    ujk = (wk * D * vj.') / denom;
                end

                U(k,j) = ujk;
                acc = acc + ujk*vj;

            end % End j loop
            V(k,:) = wk - acc;
        end % End if Statement

        dval = V(k,:) * D * V(k,:).'; % scalar
        dval = max(dval,tol); % Clip poor conditioned values
        dvec(k) = dval;

    end % End k loop

    Ubar = U;
    Dbar = diag(dvec);
end % End Function