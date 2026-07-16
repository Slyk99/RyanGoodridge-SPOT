% Dual Quaternion Multiply
% Ryan Goodridge
% 1/17/2025 (Updated 2/06/2025)
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Multiplies two dual quaternions, q and p, and returns the resulting dual quaternion.
%   A dual quaternion is represented as a 4x2 matrix:
%       - The first column is the real (rotation) quaternion.
%       - The second column is the dual (translation) quaternion.
%
%   The multiplication is defined as:
%
%       dq = [ dq_r, dq_d ] 
%
%   where:
%       dq_r = quatMultiply(q_r, p_r, representation)
%       dq_d = quatMultiply(q_r, p_d, representation) + quatMultiply(q_d, p_r, representation)
%
%   It is assumed that the function quatMultiply exists and accepts two 4x1 quaternions.
%
% Inputs:
%   q             - A 4x2 dual quaternion. The first column is the real part and
%                   the second column is the dual part.
%   p             - A 4x2 dual quaternion. The first column is the real part and
%                   the second column is the dual part.
%   representation- (Optional) A string specifying the quaternion representation.
%                   Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq            - The resulting dual quaternion, a 4x2 matrix.
%
function dq = dqMultiply(q, p, representation)
    % Validate number of inputs
    if nargin < 2
        error('At least two dual quaternions are required for multiplication.');
    end
    
    % Set default representation if not provided
    if nargin < 3 || isempty(representation)
        representation = 'scalarLast';
    end
    
    % Validate representation input
    validRepresentations = {'scalarFirst','scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    
    % Validate input dimensions for q and p (should be 4x2 matrices)
    if ~ismatrix(q) || any(size(q) ~= [4,2])
        error('Input q must be a 4x2 matrix representing a dual quaternion.');
    end
    if ~ismatrix(p) || any(size(p) ~= [4,2])
        error('Input p must be a 4x2 matrix representing a dual quaternion.');
    end
    
    % Extract the real and dual parts from q and p
    q_r = q(:,1);  % Real part of q (rotation quaternion)
    q_d = q(:,2);  % Dual part of q (translation quaternion)
    p_r = p(:,1);  % Real part of p
    p_d = p(:,2);  % Dual part of p

    % Compute the multiplication according to dual quaternion algebra:
    %   dq_r = q_r * p_r
    %   dq_d = q_r * p_d + q_d * p_r
    dq_r = quatMultiply(q_r, p_r, representation);
    dq_d = quatMultiply(q_r, p_d, representation) + quatMultiply(q_d, p_r, representation);
    
    % Assemble the result as a 4x2 matrix.
    dq = [dq_r, dq_d];
end
