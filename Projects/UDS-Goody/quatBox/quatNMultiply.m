% Quaternion Multiplication (Recursive)
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
%
% Description:
%   This function performs quaternion multiplication recursively for n quaternions.
%
% Inputs:
%   varargin: A variable number of quaternion inputs.
%             Each quaternion is a 4x1 vector. Optionally, the last argument
%             can be the 'representation' string ('scalarFirst' or 'scalarLast').
%
% Outputs:
%   r (4x1): The resulting quaternion from the multiplication of all inputs.
%
function [r] = quatNMultiply(varargin)

    % Validate input arguments
    if nargin < 2
        error('At least two quaternions are required for multiplication.');
    end

    % Check if the last argument is the 'representation' string
    if ischar(varargin{end}) || isstring(varargin{end})
        representation = varargin{end};
        quaternions = varargin(1:end-1);
    else
        representation = 'scalarLast'; % Default representation
        quaternions = varargin;
    end

    % Ensure all quaternions are 4x1 vectors
    for i = 1:numel(quaternions)
        q = quaternions{i};
        if ~isvector(q) || numel(q) ~= 4
            error('Each quaternion must be a 4-element vector.');
        end
        if size(q, 1) == 1
            quaternions{i} = q'; % Transpose to make 4x1 if 1x4
        elseif size(q, 1) ~= 4 || size(q, 2) ~= 1
            error('Each quaternion must be a 4x1 or 1x4 vector.');
        end
    end

    % Base case: If only two quaternions, call the original quatMultiply
    if numel(quaternions) == 2
        q = quaternions{1};
        p = quaternions{2};
        % Compute quaternion conjugate based on representation
        switch representation
            case 'scalarFirst'
                % For scalar-first: q = [scalar; vector]
                scalar = q(1);
                vector = [q(2); q(3); q(4)];
                q_tilda = [scalar, -vector'; vector, scalar*eye(3) + skew(vector)];

                r = q_tilda*p;
            case 'scalarLast'
                % For scalar-second: q = [vector; scalar]
                scalar = q(4);
                vector = [q(1); q(2); q(3)];
                q_tilda = [scalar, -vector'; vector, scalar*eye(3) + skew(vector)];

                r = q_tilda*p;
            otherwise
                error('Unexpected representation. This should not occur.');
        end
        return;
    end

    % Recursive case: Multiply the first quaternion with the result of the rest
    r = quatNMultiply(quaternions{1}, quatMultiplyRecursive(quaternions{2:end}, representation), representation);
end
