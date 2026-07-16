function R = buildRot(u)

% Compute the rotation angle theta
    theta = norm(u);

% Compute the unit rotation axis u (handle the zero case separately)
    if theta > 1e-8  % Avoid division by zero
        u = u / theta;
    else
        u = [0; 0; 0];  % If theta is zero, the axis is undefined
    end

    R = eye(3) + sin(theta)*skew(u) + (1 - cos(theta))*skew(u)^2;
end