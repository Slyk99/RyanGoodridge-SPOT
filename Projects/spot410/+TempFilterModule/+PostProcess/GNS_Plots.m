%%
figure
for i = 1:1:3
    subplot(3,1,i)
    plot(data.PS(:,i), 'k*')
    hold on
    plot(data.x_GNS(:,i),'r')
    grid on
end

figure
for i = 4:1:6
    subplot(3,1,i-3)
    plot(data.PS(:,i), 'k*')
    hold on
    plot(data.x_GNS(:,i),'r')
    grid on
end

figure
for i = 7:1:8
    subplot(2,1,i-6)
    plot(data.PS(:,i), 'k*')
    hold on
    plot(data.IMU(:,i-6), 'b*')
    plot(data.x_GNS(:,i),'r')
    plot(data.bias(:,i+8),'g')
    grid on
end

%%
P = recoverP(data.P_GNS);
V = data.V;

figure
for i = 1:1:5
    P_angle = squeeze(P(i,i,:) + navOpts.R_GNS(i,i));
    V_angle = squeeze(V(i,i,:));

    subplot(5,1,i)
    plot(P_angle, 'k')
    hold on
    plot(V_angle,'r')
    grid on
    ylim([0,1e-2])
end

figure
for i = 1:1:5
    subplot(5,1,i)
    plot(data.d(:,i),'k')
    grid on
end