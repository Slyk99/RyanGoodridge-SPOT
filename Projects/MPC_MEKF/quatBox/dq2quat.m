% Dual Quaternion to Quaternion & Translation Vector
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Converts a dual quaternion into its equivalent rotation quaternion and
%   translation vector. The dual quaternion is given as a 4x2 matrix:
%       dq = [qr, qd]
%   where qr is the real (rotation) quaternion and qd is the dual (translation) quaternion.
%
%   For a unit dual quaternion the translation vector is given by:
%
%       t = 2 * (qd * quatConj(qr))_vec
%
%   where quat multiplication and conjugation assume MATLAB's built-in functions which use
%   the scalar-first convention.
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Outputs:
%   q_rot          - The rotation quaternion (4x1) in the specified representation.
%   t              - The translation vector (3x1).
%
function [q_rot, t] = dq2quat(dq, representation)

    %% Input Validation
    if nargin < 1
        error('At least one input (dq) is required.');
    end
    if nargin < 2 || isempty(representation)
        representation = 'scalarLast';
    end
    validRepresentations = {'scalarFirst','scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end
    if ~ismatrix(dq) || any(size(dq) ~= [4,2])
        error('Input dq must be a 4x2 matrix representing a dual quaternion.');
    end

    %% Extract the rotation (real) and dual parts
    q_r = dq(:,1);  % Rotation quaternion
    q_d = dq(:,2);  % Dual part

    % The output rotation quaternion is simply q_r.
    q_rot = q_r;
    
    %% Convert to scalar-first for MATLAB's built-in quaternion functions if needed.
    switch representation
        case 'scalarFirst'
            q_r_sf = q_r;
            q_d_sf = q_d;
        case 'scalarLast'
            % Convert from scalar-last [v; s] to scalar-first [s; v]
            q_r_sf = [q_r(4); q_r(1:3)];
            q_d_sf = [q_d(4); q_d(1:3)];
        otherwise
            error('Unexpected representation.');
    end

    %% Compute the translation vector.
    % Compute the product: q_d_sf * quatConj(q_r_sf)
    % MATLAB's built-in functions assume quaternions as 1x4 row vectors.
    prodQuat = quatMultiply(q_d_sf, quatConj(q_r_sf,'scalarFirst'),'scalarFirst');
    % The resulting quaternion has the form [0, t_x, t_y, t_z] (if dq is unit).
    % Extract the vector part and multiply by 2.
    t = 2 * prodQuat(2:4)';
end
