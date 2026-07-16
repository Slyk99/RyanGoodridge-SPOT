% Dual Quaternion to Homogeneous Transformation
% Ryan Goodridge
% 2/06/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   Converts a dual quaternion into its equivalent homogeneous transformation matrix.
%   The dual quaternion is given as a 4x2 matrix:
%       dq = [qr, qd]
%   where qr is the real (rotation) quaternion and qd is the dual (translation) quaternion.
%
%   The homogeneous transformation T is given by:
%       T = [ R, t;
%             0 0 0 1 ]
%
%   where R is the rotation matrix corresponding to the rotation quaternion and t is the translation vector,
%   which can be obtained via:
%
%       t = 2 * (qd * quatConj(qr))_vec
%
% Inputs:
%   dq             - A 4x2 dual quaternion matrix.
%   representation - (Optional) A string specifying the quaternion representation.
%                    Options: 'scalarLast' (default) or 'scalarFirst'.
%
% Outputs:
%   T              - A 4x4 homogeneous transformation matrix.
%
function T = dq2Htform(dq, representation)

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

    %% Get the rotation quaternion and translation vector using dq2quat
    [q_rot, t] = dq2quat(dq, representation);

    %% Convert the rotation quaternion to a rotation matrix.
    % MATLAB's built-in function quat2rotm expects quaternions in scalar-first format.
    switch representation
        case 'scalarFirst'
            q_sf = q_rot;
        case 'scalarLast'
            % Convert from scalar-last [v; s] to scalar-first [s; v]
            q_sf = [q_rot(4); q_rot(1:3)];
        otherwise
            error('Unexpected representation.');
    end
    
    % Ensure q_sf is a row vector for quat2rotm.
    R = quat2rotm(q_sf');
    
    %% Assemble the homogeneous transformation matrix.
    T = [R, t; 0 0 0 1];
end
