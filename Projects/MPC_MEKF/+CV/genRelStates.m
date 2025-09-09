function xrel_noise = genRelStates(xRed, xobs, noise, std, FOV)
% Red rotation matrix from inertial to body fixed frames
R_IB_red = C3(xRed(3));
yaw_rel = xRed(3) + xobs(3);


% Relative vector from black and blue to red in reds body fixed frame
xrel_true = R_IB_red(1:2,1:2)*(xobs(1:2) - xRed(1:2));

% Add noise to the measurements
xrel_noise = [xrel_true; yaw_rel] + noise(1:3);

% Add outliers 
if abs(noise(4)) > std
    xrel_noise = xrel_noise + 10*noise(1:3);
end

% Add integrated noise (non-gaussian)
xrel_noise = xrel_noise + noise(5:7);

% Add distortion at the edge of the FOV
xrel_noise = xrel_noise + noise(5:7)*sin(pi*yaw_rel/FOV);
% ^ note on that: the worst case is yaw_rel == FOV/2 
% and also sin(pi/2) gives the largest value, so (pi/2)*yaw_rel/(FOV/2) == pi*yaw_rel/FOV 

% Wrong face out of CV
persistent flip
if isempty(flip)
    flip = 0;
elseif noise(8) > std
    flip = flip + pi;
elseif noise(8) < -std
    flip = flip - pi;
end
xrel_noise(3) = xrel_noise(3) + flip;
end