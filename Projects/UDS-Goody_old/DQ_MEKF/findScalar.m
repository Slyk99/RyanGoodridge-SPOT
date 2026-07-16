function dq_corr = findScalar(dqv)
%% Extract Components
delta_theta = dqv(1:3);
delta_t     = dqv(4:6);

%% Build the correction dual quaternion Δ*δq from the pose error (delta_theta, delta_t).
norm_theta = norm(delta_theta);
if norm_theta <= 1
    % Use small-error formula (Eq. (135)):
    scalar_corr = sqrt(1 - norm_theta^2);
    dq_corr_rot = [ scalar_corr; delta_theta ];   % 4x1 rotation correction
    dq_corr_dual_scalar = - (delta_theta' * delta_t) / scalar_corr;
    dq_corr_dual = [ dq_corr_dual_scalar; delta_t ]; % 4x1 translation correction
else
    % Use alternative scaling (Eq. (136)):
    scale = 1 / sqrt(1 + norm_theta^2);
    dq_corr_rot = [ scale; delta_theta * scale ];
    % Note: denominator becomes 1/scale = sqrt(1+norm_theta^2)
    dq_corr_dual_scalar = - (delta_theta' * delta_t) * sqrt(1 + norm_theta^2);
    dq_corr_dual = [ dq_corr_dual_scalar; delta_t ];
end

%% Return the unit dual quaternion correction (4x2):
dq_corr = [ dq_corr_rot, dq_corr_dual ];

end