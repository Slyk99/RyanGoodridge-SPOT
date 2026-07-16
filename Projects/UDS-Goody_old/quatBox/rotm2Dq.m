% rotm2Dq - Rotation Matrix to Dual Quaternion
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% 
% Description:
% This function converts a 3x3 Rotation Matrix matrix (DCM) 
% representing a rigid body rotation into a Dual Quaternion.
% 
% Inputs:
%   C: 3x3 Rotation Matrix matrix. 
%      Must be a valid C with a det(C) == 1.
%   representation (optional, string): The representation of the quaternion 
%                                     ('scalarFirst' or 'scalarLast'). 
%                                     Defaults to 'scalarLast'.
% 
% Outputs:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
% 
function dq = rotm2Dq(C,representation)

% Set default representation if not provided
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end

    % Validate representation input
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end

% Pure Part of the Dual Quaternion
qr = rotm2Quat(C(1:3,1:3)',representation);

% Dual Part of the Dual Quaternion
qd = 0*qr;

% Assemble the Dual Quaternion
dq = [qr,qd];
end