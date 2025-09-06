% StochasticHoldingRadius Linearized ellipse constraints
%
% Inputs:
%   rhold     2×1 [a; b] semi-axes of the holding ellipse
%   z0        (mN + nN)×1 previous MPC vector [u; x_chaser]
%   xTstack   6×N target state history over horizon
%   Offset    2 by 1 offset of the constraint to match any geometry
%   n         chaser state dimension (6)
%   m         control dimension
%   N         horizon length
%
% Outputs:
%   Aineq     N×((m+n)*N) LHS of inequality constraints
%   bineq     N×1        RHS
%
function [Aineq, bineq] = StochasticHoldingRadius( ...
    rhold, z0, xTstack, PTstack, Offset, n, m, N, epsilon)

  % Pre-allocate
  Aineq = zeros(N, (m+n)*N);
  bineq = zeros(N, 1);

  % Body-frame shape matrix
  S = diag(1./(rhold.^2));

  % Extract chaser states x_c,1…x_c,N
  Xc = reshape(z0(m*N+1:end), n, N);

  H = [eye(2), zeros(2,4)];

  for i = 1:N
    %% 1) Compute geometry
    % Target pos & heading
    tar_i    = xTstack(:,i);
    r_tar    = tar_i(1:2);
    theta    = tar_i(3);

    % World-frame ellipse matrix
    c = cos(theta);  s = sin(theta);
    R = [c, -s; s, c];
    M        = R * S * R';

    % ---- NEW: world-frame offset of the port/geometry ----
    % Offset is provided in target body frame; rotate into inertial/world.
    c_center = r_tar + R * Offset;   % center of ellipse shifted to account for port offset

    % Chaser pos
    r_c      = Xc(1:2, i);

    % Radial unit from (shifted) center -> chaser
    u        = r_c - c_center;
    d        = norm(u);
    if d < 1e-12
      % Chaser exactly at center – safe default
        u = [1; 0];
        d = 0;
    else
        u = u / d;
    end

    % Extract semi-(major/minor) axes
    [a_e, b_e] = deal(rhold(1), rhold(2));
    % angle relative to ellipse orientation (use rotated center orientation)
    theta_e = acos(u'*R*[1;0]);

    % Compute ellipse radius at current angle
    r_e = a_e*b_e/sqrt((a_e*sin(theta_e))^2 + (b_e*cos(theta_e))^2);

    % ---- Use shifted center here ----
    r0   = c_center + r_e .* u;

    % Gradient & linear constraint (linearize about r0, center = c_center)
    % Note: gradient g = 2*M*(r0 - c_center) -> you used E = (r0 - center)'*M
    E    = (r0 - c_center)'*M;    % 1x2

    % Compute quantile from Gaussian inverse CDF
    z_epsilon = norminv(1 - epsilon);   % scalar

    Pk = PTstack(:, :, i);               % nx x nx
    Sigma_k = H * Pk * H';              % nc x nc

    % Projected std dev along constraint normal
    sigma_proj = sqrt(E * Sigma_k * E');   % scalar

    % Fill inequality row (keep same sign convention as original)
    Aineq(i, m*N+1 + n*(i-1):m*N+2 + n*(i-1)) = -2 .* E;
    % Use c_center instead of r_tar in the constant term
    bineq(i,1) = -1 - E*(r0 + c_center) - z_epsilon .* sigma_proj;

    %% === Plotting (unchanged, use c_center instead of r_tar if plotting) ===
    % (optional plotting code omitted for brevity)
  end
end

    %% === Plotting and violation check ===
    % hold on; axis equal;
    % xlabel('x'); ylabel('y');
    % 
    % % 1) Body‐frame ellipse (centered at target)
    % phi       = linspace(0,2*pi,200);
    % ellipse_b = [a_e*cos(phi); b_e*sin(phi)];   % 2×200
    % 
    % % Plot that ellipse *translated* to r_tar
    % ellipse_w = R*ellipse_b + r_tar;            % 2×200
    % plot(ellipse_w(1,:), ellipse_w(2,:), 'k-', 'LineWidth',1.5);
    % 
    % % 2) Chaser & tangent point
    % grid on
    % plot(r_tar(1),    r_tar(2),    'go', 'MarkerFaceColor','g', 'DisplayName','Target');
    % plot(r_c(1),      r_c(2),      'ro', 'MarkerFaceColor','r', 'DisplayName','Chaser');
    % plot(r0(1),       r0(2),       'bs', 'MarkerFaceColor','b', 'DisplayName','Tangent Pt');
    % 
    % % 3) Tangent line at r0
    % %    Your E row is (r0-r_tar)'*M, and gradient g = 2*M*(r0-r_tar) = 2*(E') 
    % g = -2.*E;
    % t_dir    = [-g(2); g(1)];                  % tangent direction (perp to gradient)
    % t_dir    = t_dir / norm(t_dir);
    % L        = max([a_e,b_e])*1.2;
    % pts      = [r0 - L*t_dir,  r0 + L*t_dir];  % 2×2
    % plot(pts(1,:), pts(2,:), 'r-', 'LineWidth',1.5, 'DisplayName','Tangent Line');
    % 
    % % 4) Violation check: linearized constraint is g*(x-r0) <= 0
    % val = g * r_c ;
    % Aineq(i,1:m*N)*z0(1:m*N) ;   % if there are other parts of the state
    % if Aineq(i, m*N+1 + n*(i-1):m*N+2 + n*(i-1))*r_c > bineq(i,1)
    %     disp('VIOLATION');
    % else
    %     disp('OK');
    % end