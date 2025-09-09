% Dual Quaternion Normalization
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Normalizes a dual quaternion so that its real part is a unit quaternion.
%   This ensures that the rotation component remains valid.
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Output:
%   dq_normalized  - The normalized dual quaternion as a 4x2 matrix.
%
function dq_normalized = normalizeDq(dq, representation)
    %% Input Validation
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    %% Compute Normalization
    norm_dq = dqNorm(dq, representation); % Compute the norm using dqNorm function
    
    if norm_dq == 0
        error('Cannot normalize a zero dual quaternion.');
    end
    
    q_r = dq(:,1);  % Real part
    q_d = dq(:,2);  % Dual part
    
    q_r_normalized = q_r / norm_dq; % Normalize the real quaternion
    q_d_normalized = q_d / norm_dq; % Scale the dual part accordingly
    
    dq_normalized = [q_r_normalized, q_d_normalized];
end

