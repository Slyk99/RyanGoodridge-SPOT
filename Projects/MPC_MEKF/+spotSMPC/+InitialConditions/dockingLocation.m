% dockingLocation  Compute docking-port trajectory in inertial frame
%
% Inputs:
%   xTstack         n×N matrix of target states over horizon
%                   (assumes rows 1–2 = [x; y], row 3 = heading θ)
%   docking_Offset  2×1 vector [dx; dy] in the target’s body frame
%   N               Horizon length (number of columns in xTstack)
%
% Output:
%   DockingPort     2×N matrix of inertial docking-port positions
%
function [DockingPort, DockingRadius] = dockingLocation(xTstack, docking_Offset, N)

% Preallocate
DockingPort = zeros(2, N);
DockingRadius = DockingPort;

% Extract positions and headings
pos = xTstack(1:2, :);      % 2×N
theta = xTstack(3, :);      % 1×N

% Compute rotation and offset for each step
for k = 1:N
    c = cos(theta(k));
    s = sin(theta(k));
    R = [c, -s; 
         s,  c];
    r_I = R * docking_Offset(1:2);
    DockingPort(:,k) = pos(:,k) + r_I;
    DockingRadius(:,k) = r_I;
end

end
