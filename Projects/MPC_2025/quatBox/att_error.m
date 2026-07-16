% Attitude Error of two angles
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   This function finds the smallest angle in-between two angles 
%   ref - act
%
% Inputs:
%   ref = angle in rad
%   act = angle in rad
%
% Outputs:
%   error = angle in rad
%
function error = att_error(ref,act)
u_x_ref = [cos(ref) sin(ref);
          -sin(ref) cos(ref)] * [1; 0];

u_y_ref = [cos(ref) sin(ref);
          -sin(ref) cos(ref)] * [0; 1];

u_x_act = [cos(act) sin(act);
          -sin(act) cos(act)] * [1; 0];

error = -1*norm(u_x_ref - u_x_act)*sign(u_y_ref'*(u_x_ref - u_x_act));

end