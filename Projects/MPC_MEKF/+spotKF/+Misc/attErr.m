function e_out = attErr(ref,act)
    Ax = [cos(act) sin(act); -sin(act) cos(act)]*[1;0];
    Rx = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[1;0];
    Ry = [cos(ref) sin(ref); -sin(ref) cos(ref)]*[0;1];
    
    e_in = Rx - Ax;
    
    a = sign(Ry'*e_in);
    e_out = -a*norm(e_in);
end