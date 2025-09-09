% Recursive Dual Quaternion Multiply
% Ryan Goodridge
% 1/17/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
% Multiplies multiple dual quaternions recursively, returning the resulting dual quaternion.
% A dual quaternion q = [q_r, q_d] where q_r (real part) and q_d (dual part)
% are 4x1 quaternions represented as [w, x, y, z] (scalar-first convention).
%
% Inputs:
% varargin: A variable number of 4x2 dual quaternions.
%           Optionally, the last argument can be the 'representation' string.
%
% Output:
%   dq: A 4 by 2 array representing the Dual Quaternion. 
%      The first 4 elements represent the real part (rotation quaternion), 
%      and the last 4 elements represent the dual part (translation quaternion).
%      The order of scalar and vector components within each quaternion 
%      follows the specified 'representation'.
%
function dq = dqNMultiply(varargin)
    % Validate input arguments
    if nargin < 2
        error('At least two dual quaternions are required for multiplication.');
    end

    % Check if the last argument is the 'representation' string
    if ischar(varargin{end}) || isstring(varargin{end})
        representation = varargin{end};
        dualQuaternions = varargin(1:end-1);
    else
        representation = 'scalarLast'; % Default representation
        dualQuaternions = varargin;
    end

    % Ensure all dual quaternions are 4x2 matrices
    for i = 1:numel(dualQuaternions)
        dq = dualQuaternions{i};
        if ~ismatrix(dq) || size(dq, 1) ~= 4 || size(dq, 2) ~= 2
            error('Each dual quaternion must be a 4x2 matrix.');
        end
    end

    % Base case: If only two dual quaternions, call the original dqMultiply
    if numel(dualQuaternions) == 2
        q = dualQuaternions{1};
        p = dualQuaternions{2};
        dq = [quatMultiply(q(:,1), p(:,1),representation), ...
            quatMultiply(q(:,1), p(:,2),representation) + ...
            quatMultiply(q(:,2), p(:,1),representation)];
        return;
    end

    % Recursive case: Multiply the first dual quaternion with the result of the rest
    dq = dqNMultiply(dualQuaternions{1}, dqMultiplyRecursive(dualQuaternions{2:end}, representation), representation);
end
