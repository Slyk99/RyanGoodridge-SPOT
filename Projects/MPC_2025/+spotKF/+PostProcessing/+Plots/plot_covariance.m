function xy = plot_covariance(mu,Sigma,color,alpha)
    % Draw covariance ellipse (2D)
    [V,D] = eig(Sigma);
    t = linspace(0,2*pi,1000);
    k = sqrt(5.991); % 95% confidence for chi2(2)
    xy = k*V*sqrt(D)*[cos(t);sin(t)] + mu;
    fill(xy(1,:),xy(2,:),color,'FaceAlpha',alpha,'EdgeColor',color,'LineWidth',1.2);

    hold on
    plot(V(1,1), V(2,1), 'k*')
    plot(V(1,2), V(2,2), 'k*')
    plot(0, 0, 'k*')
end