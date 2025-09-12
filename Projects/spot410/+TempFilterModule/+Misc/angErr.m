function e_out = angErr(ref,act)
    % ref
    rx = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[1;0];
    ry = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[0;1];
    
    % Act
    ax = [cos(act) sin(act); -sin(act) cos(act)]*[1;0];
    
    % diff
    dx = rx - ax;
    
    % Angle Error
    a = sign(ry'*dx);
    e_out = -a*norm(dx);
end