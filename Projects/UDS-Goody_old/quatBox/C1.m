% Ryan Goodridge 
% 101147736
% ryangoodridge@cmail.carleton.ca
% Date performed: 03/26/2023
% rotation matrix - rotation about the x axis
function A = C1(x)
if nargin > 1
    error('Too many inputs.  See help file')
end
A = [   1        0     0;
        0   cos(x)  sin(x);
        0   -sin(x) cos(x)];
end