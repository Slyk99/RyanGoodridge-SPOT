function y = residual(z,z_bar,a,f)
    %% Extract components
    % Quaternions states
    q_obs = z(1:4);        % Measured quaternion
    q_prop = z_bar(1:4);   % Predicted quaternion
    
    %% Linear state residual
    z_error = z(5:end) - z_bar(5:end);

    %% Quaternion residual
    q_err = quatMultiply(q_obs', quatConj(q_prop, 'scalarFirst'),'scalarFirst'); % Quaternion error (observed - predicted)
    q_err = smallQuat(q_err,'scalarFirst');

    g = quat2mrp(q_err, a, f, 'scalarFirst'); % Convert quaternion error to MRP

    % Concatenate quaternion and non-quaternion components
    y = [g; z_error];                         % Concatenated residuals

end