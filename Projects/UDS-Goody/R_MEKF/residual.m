function y = residual(z,z_bar,Rot_bar,Rot_obs)
    % Compute the translation residual:
    z_error = z - z_bar;  % 3x1
    
    % Attitude (rotation) error update using Lie algebra
    Rot_error = Rot_bar * Rot_obs';
    
    % Compute the error “angle” using the trace formula:
    trace_R = trace(Rot_error);
    cos_theta = max(min((trace_R - 1)/2, 1), -1);
    theta = acos(cos_theta);
    
    if abs(theta) < 1e-8 % Avoid numerical errors at matrix singularity
        theta_err = zeros(3,1);
    else
        theta_err = (theta*(2*sin(theta))) * [att_error(Rot_error(3,2), Rot_error(2,3));
            att_error(Rot_error(1,3), Rot_error(3,1));
            att_error(Rot_error(2,1), Rot_error(1,2))];
    end
    
    % Concatenate the attitude error and translation residual into one innovation vector:
    y = [theta_err; z_error];  % 6x1
end