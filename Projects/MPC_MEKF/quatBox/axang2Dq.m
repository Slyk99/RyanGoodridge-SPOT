% Axis Angle to Dual Quaternion 
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a 4-element axis-angle representation of a rotation
%   to a dual quaternion. The axis-angle representation consists of a unit vector
%   (the axis of rotation) and an angle (the amount of rotation about that axis).
%   The output dual quaternion can be represented with either a scalar element 
%   as the first element (scalar first) or the last element (scalar last).
% 
% Inputs:
%   a (4x1): The axis-angle representation, where the first three elements
%            represent the axis of rotation and the fourth element represents
%            the angle of rotation.
%   representation (optional, string): The desired output format of the
%            quaternion. Valid options are 'scalarFirst' (default) or
%            'scalarLast'.
% 
% Outputs:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
%
function dq = axang2Dq(a,representation)
    % Check if the axis is a 4x1 vector
    if numel(a) ~= 4 || ~isvector(a)
        error('Axis must be a 4x1 vector');
    end

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
    qr = axang2Quat(a,representation);
    
    % Dual Part of the Dual Quaternion
    qd = 0*qr;
    
    % Assemble the Dual Quaternion
    dq = [qr,qd];
end