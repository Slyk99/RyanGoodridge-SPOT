function [x, P, V] = STEKF(dt, z, x, u, P, rho, V, Q, R, Fhndle, Hhndle, ST, OLR, dmax)
% --- PREDICT ---------------------------------------------------------
[xk, F, G] = Fhndle(x,  dt, u);
Pk         = F*P*F' + G*Q*G';

% --- Measurement -----------------------------------------------------
[zPred, H] = Hhndle(xk);
y          = z - zPred;

% --- Angle Innovation (wrapped difference) ---------------------------
y(3)       =  spotKF.Misc.attErr(z(3),zPred(3));

% --- Outlier Rejection -----------------------------------------------
Pzz    = H*Pk*H' + R;
reject = false;
if OLR
    dm     = y'*inv(Pzz)*y;
    if dm >= dmax
        reject = true;
    end
end

% --- For no Measurments ----------------------------------------------
if anynan(z) || reject
    x = xk;
    P = Pk;
    V = rho*V;
    return
end

% --- Strong Tracking -------------------------------------------------
if ST
    if det(V) == 0
        V = rho*(y*y');
    else
        V = rho*(rho*V + y*y') / (1 + rho);
    end
    
    M = Pzz;
    N = V - R;
    L2 = trace(N) / trace(M); % This calculates lambda^2;
    L = sqrt(L2);
    Pk = L*Pk*L';
end

% --- UPDATE ----------------------------------------------------------
Pzz        = H*Pk*H' + R;
K          = Pk* H' / Pzz;

corr       = K*y;
x          = xk + corr;
I          = eye(size(K,1));
P          = (I - K*H)*Pk*(I - K*H)' + K*R*K';

end