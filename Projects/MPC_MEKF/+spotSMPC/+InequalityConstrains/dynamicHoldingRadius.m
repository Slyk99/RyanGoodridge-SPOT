function [Aineq, bineq] = dynamicHoldingRadius( ...
    rhold, z0, xTstack, n, m, N)
% dynamicHoldingRadius  with built-in test plots & violation check
%
% Inputs/Outputs as before…

  % Pre-allocate
  Aineq = zeros(N, (m+n)*N);
  bineq = zeros(N, 1);

  % Body-frame shape matrix
  S = diag(1./(rhold.^2));

  % Extract chaser states x_c,1…x_c,N
  Xc = reshape(z0(m*N+1:end), n, N);

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

    % Chaser pos
    r_c      = Xc(1:2, i);

    % Radial unit from target→chaser
    u        = r_c - r_tar;
    d        = norm(u);
    u        = u / d;

    % Extract semi-(major/minor) axes
    [a_e, b_e] = deal(rhold(1), rhold(2));
    theta_e = acos(u'*R*[1;0]);

    % Compute ellipse radius at current angle
    r_e = a_e*b_e/sqrt((a_e*sin(theta_e))^2 + (b_e*cos(theta_e))^2);

    r0   = r_tar + r_e .* u;

    % Gradient & linear constraint
    E    = (r0 - r_tar)'*M;    % 2×1

    Aineq(i, m*N+1 + n*(i-1):m*N+2 + n*(i-1)) = -2.*E;
    bineq(i,1) = -1-E*(r0 + r_tar);

    %% === Plotting and violation check ===
    figure(i); clf; hold on; axis equal;
    title(sprintf('Holding‐Radius Step %d', i));
    xlabel('x'); ylabel('y');
    
    % 1) Body‐frame ellipse (centered at target)
    phi       = linspace(0,2*pi,200);
    ellipse_b = [a_e*cos(phi); b_e*sin(phi)];   % 2×200
    
    % Plot that ellipse *translated* to r_tar
    ellipse_w = R*ellipse_b + r_tar;            % 2×200
    plot(ellipse_w(1,:), ellipse_w(2,:), 'k-', 'LineWidth',1.5);
    
    % 2) Chaser & tangent point
    plot(r_tar(1),    r_tar(2),    'go', 'MarkerFaceColor','g', 'DisplayName','Target');
    plot(r_c(1),      r_c(2),      'ro', 'MarkerFaceColor','r', 'DisplayName','Chaser');
    plot(r0(1),       r0(2),       'bs', 'MarkerFaceColor','b', 'DisplayName','Tangent Pt');
    
    % 3) Tangent line at r0
    %    Your E row is (r0-r_tar)'*M, and gradient g = 2*M*(r0-r_tar) = 2*(E') 
    g = -2.*E;
    t_dir    = [-g(2); g(1)];                  % tangent direction (perp to gradient)
    t_dir    = t_dir / norm(t_dir);
    L        = max([a_e,b_e])*1.2;
    pts      = [r0 - L*t_dir,  r0 + L*t_dir];  % 2×2
    plot(pts(1,:), pts(2,:), 'r-', 'LineWidth',1.5, 'DisplayName','Tangent Line');
    
    legend('Location','bestoutside');
    
    % 4) Violation check: linearized constraint is g*(x-r0) <= 0
    val = g * r_c ;
    Aineq(i,1:m*N)*z0(1:m*N) ;   % if there are other parts of the state
    if Aineq(i, m*N+1 + n*(i-1):m*N+2 + n*(i-1))*r_c > bineq(i,1)
        disp('[Step %d] VIOLATION');
    else
        disp('[Step %d] OK');
    end

    
    drawnow;
  end
end
