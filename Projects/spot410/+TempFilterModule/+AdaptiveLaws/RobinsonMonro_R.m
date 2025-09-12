function R = RobinsonMonro_R(R, alpha_R, y, m)

%{
© 2025 Carleton University.
Written by: Yazan Chihabi
Date started: 2023
Last modified: July 2025 for Obruta Space Solutions Corp.
Reference: https://arc.aiaa.org/doi/10.2514/6.2024-0627
%}

y = y(1:m); % Trim the padded zeros
R = (1-alpha_R).*R + alpha_R.*(y*y');

end