% updateAngle  Add a docking‐offset to each reference heading
%
% Inputs:
%   x_ref              (n*N×1) stacked reference vector from genReference
%   dockingOffsetAngle scalar or 1×N vector of angles [rad]
%   n                  state dimension (e.g. 6)
%   N                  horizon length
%
% Output:
%   x_ref              same size, but heading entries incremented
%
function x_ref = updateAngle(x_ref, dockingOffsetAngle, n, N)

    % If they passed a scalar, make it into a vector
    if isscalar(dockingOffsetAngle)
        offset = dockingOffsetAngle * ones(1, N);
    else
        assert(numel(dockingOffsetAngle)==N, ...
            'dockingOffsetAngle must be scalar or length-N');
        offset = dockingOffsetAngle(:)';
    end

    % Loop through each time block and adjust the 3rd state (heading)
    for k = 1:N
        idx_theta = (k-1)*n + 3;         % index of θ in the big vector
        x_ref(idx_theta) = x_ref(idx_theta) + offset(k);
    end
end
