% Modified Rodrigues Parameters to Quaternion
% Ryan Goodridge
% 1/08/2025
% ryangoodridge@cmail.carleton.ca
% 
% Description:
%   This function converts a modified Rodrigues parameters (MRP) representation
%   of a rotation to a quaternion. The MRP representation consists of a 3-element
%   vector and two parameters, a and f.
%
% Inputs:
%   mrp (3x1): The modified Rodrigues parameters vector.
%   a (scalar, optional): The first MRP parameter. Defaults to 0.
%   f (scalar, optional): The second MRP parameter. Defaults to 1.
%   representation (optional, string): The desired output format of the
%            quaternion. Valid options are 'scalarFirst' (default) or
%            'scalarLast'.
%
% Notes:
%   - The default setting (a = 0, f = 1) represents the Gibbs vector.
%   - If a = 1, the function produces the standard set of MRPs.
%   - If f = 2(a + 1), for small angles |r| ≈ θ (rotation angle in radians).
%
% Outputs:
%   q (4x1): The quaternion representing the rotation.
%
function q = mrp2quat(mrp, a, f, representation)
    % Validate input dimensions
    if ~isvector(mrp) || length(mrp) ~= 3
        error('Input MRP vector must be a 3x1 vector.');
    end

    % Set default values for optional parameters
    if nargin < 2 || isempty(a)
        a = 0; % Default value for a
    end
    if nargin < 3 || isempty(f)
        f = 1; % Default value for f
    end
    if nargin < 4 || isempty(representation)
        representation = 'scalarLast'; % Default representation
    end

    % Validate representation input
    validRepresentations = {'scalarFirst', 'scalarLast'};
    if ~any(strcmp(representation, validRepresentations))
        error('Invalid representation. Choose either ''scalarFirst'' or ''scalarLast''.');
    end

    % Compute the scalar part (n) of the quaternion
    norm_mrp = norm(mrp);
    n = -a * (norm_mrp^2) + f * sqrt(f^2 + (norm_mrp^2) * (1 - a)^2);
    n = n / (f^2 + (norm_mrp^2));

    % Compute the vector part (eps) of the quaternion
    eps = mrp .* (a + n) / f;

    % Assemble the quaternion based on the desired representation
    switch representation
        case 'scalarFirst'
            q = [n; eps]; % Scalar part first
        case 'scalarLast'
            q = [eps; n]; % Scalar part last
        otherwise
            error('Unexpected representation. This should not occur.');
    end
end

