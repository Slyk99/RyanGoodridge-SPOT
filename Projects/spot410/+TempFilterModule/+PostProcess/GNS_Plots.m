%%
figure
for i = 1:1:2
    subplot(2,1,i)
    plot(data.PS(:,i), 'k*')
    hold on
    plot(data.x_GNS(:,i),'r')
    grid on
end

figure
for i = 3:1:4
    subplot(2,1,i-2)
    plot(data.PS(:,i), 'k*')
    hold on
    plot(data.x_GNS(:,i),'r')
    grid on
end

figure
for i = 5:1:6
    subplot(2,1,i-4)
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
    plot(data.x_GNS(:,i),'r')
    if i == 8
        plot(data.IMU(:,2),'b*')
        plot(data.x_GNS(:,i)+ data.x_GNS(:,i+1),'g') % bias
    end
    grid on
end

%%
% P = recoverP(data.P_GNS);
% V = data.V;
% 
% figure
% for i = 1:1:5
%     P_angle = squeeze(P(i,i,:) + navOpts.R_GNS(i,i));
%     V_angle = squeeze(V(i,i,:));
% 
%     subplot(5,1,i)
%     plot(P_angle, 'k')
%     hold on
%     plot(V_angle,'r')
%     grid on
%     ylim([0,1e-2])
% end
% 
% figure
% for i = 1:1:5
%     subplot(5,1,i)
%     plot(data.d(:,i),'k')
%     grid on
% end

function P = recoverP(ud)
P = zeros(size(ud));

    % UD is n-by-n combined matrix
    n = size(ud,1);
    idx = 1:(n+1):n*n;        % linear indices of diagonal entries

for i = 1:1:length(P)
    UD = ud(:,:,i);
    dvec = UD(idx);          % extract diagonal as vector
    D = diag(dvec);          % full diagonal matrix (optional)
    U = UD;                  
    U(idx) = 1;              % set diagonal to ones -> unit upper triangular U
    P(:,:,i) = U*D*U';
end

end