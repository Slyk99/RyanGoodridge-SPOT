function Q = RobinsonMonro_Q(Q, G, alpha_Q, K, y)

%{
© 2025 Carleton University.
Written by: Yazan Chihabi
Date started: 2023
Last modified: July 2025 for Obruta Space Solutions Corp.
Reference: https://arc.aiaa.org/doi/10.2514/6.2024-0627
%}

% Robinson Monro update
Q_Full = K*(y*y')*K';

% Project to noise space
Q_new  = G.'*Q_Full*G;
GG = G.'*G;
Q_new = (Q_new / GG) / GG;

% Fading factor update
Q = (1-alpha_Q).*Q + alpha_Q.*Q_new;

end