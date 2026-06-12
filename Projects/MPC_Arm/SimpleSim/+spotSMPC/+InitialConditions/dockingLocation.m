% dockingLocation  Compute docking-port trajectory in inertial frame
%
% Inputs:
%   xTstack         n×N matrix of target states over horizon
%                   (assumes rows 1–2 = [x; y], row 3 = heading θ)
%   docking_Offset  2×1 vector [dx; dy] in the target’s body frame
%   r_hold          Holding Radius (2,1)
%   N               Horizon length (number of columns in xTstack)
%
% Output:
%   DockingPort     2×N matrix of inertial docking-port positions
%
function [DockingPort, DockingRadius] = dockingLocation(xTstack, docking_Offset, r_hold, N)

% Preallocate
DockingPort = zeros(2, N);
DockingRadius = DockingPort;

% Find desired point that is not within r_hold
y = sqrt(r_hold(1)^2 - docking_Offset(1)^2);
y = max(y, docking_Offset(2));
docking_Offset(2) = y;

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
% cla
% hold on
% plot(pos(1,:), pos(2,:), 'k*')
% 
% for i = 1:N
%     param = [xTstack(1:3,i); 2];
%     alpha = (N - i + 1)/N;
%     [spacecraft] = spotSMPC.PostProcessing.Plots.DrawSpacecraft(param);
%     patch(spacecraft(:,1), spacecraft(:,2), 'w', 'facealpha', 0.5, 'edgecolor', 'k', 'edgealpha',alpha,'Linewidth',0.5)
% end
% plot(DockingPort(1,:), DockingPort(2,:), 'r*')
% grid on
% box on
% axis equal
% xlim([0 3.5])
% ylim([0 2.4])
% disp('next')
end
