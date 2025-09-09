% Ryan Goodridge 
% 101147736
% ryangoodridge@cmail.carleton.ca
% Date performed: 03/26/2023
% rotation matrix - rotation about the y axis
function A = C2(x)
if nargin > 1
    error('Too many inputs.  See help file')
end
A = [cos(x)  0     sin(x);
    0        1        0;
   -sin(x)   0     cos(x)];
end
