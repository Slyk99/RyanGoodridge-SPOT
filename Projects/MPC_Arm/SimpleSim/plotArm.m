% function plotArm(q, params)

close all
figure
hold on

x = [1,1,0,0.3,1,0,0,0]';

[sc] = DrawSpacecraft(x)

% P is n-by-2 where column1 = x, column2 = y
P_closed = [sc; sc(1,:)];         % repeat first vertex to close the polygon
plot(P_closed(:,1), P_closed(:,2))
axis equal

% pg = polyshape(P); 
% plot(pg, 'FaceColor', 'none', 'EdgeColor', 'k', 'LineWidth', 1);
% axis equal

% end

% Plot table
Table_Corners = [0, 3.5, 3.5, 0, 0;
                 0, 0,   2.5, 2.5, 0]';
plot(Table_Corners(:,1), Table_Corners(:,2), 'k', 'LineWidth', 2);


axis equal