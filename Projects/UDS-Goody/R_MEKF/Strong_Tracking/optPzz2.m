function V = optPzz2(G1,G2,L,y)
% Inputs:
% V      - True Pzz from last time step
% G1     - Factor of V from last time step
% G2     - Factor of V from last time setp
% y      - residual from current time step
%

    % This method is best when L is a scalar
    G1 = G1/(L*L) + y*y'; % Update G1 
    G2 = G2/(L*L) + 1; % Update G2
    V = G1/G2;
end