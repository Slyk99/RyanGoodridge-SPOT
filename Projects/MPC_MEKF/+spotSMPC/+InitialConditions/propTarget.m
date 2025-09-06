function [xstack, Pstack] = propTarget(x0, P0, Ad, Bd, Q, n, N)
% Propagate state trajectory for next N steps
xstack = zeros(n,N);
Pstack = zeros(n,n,N);
x = x0;

for i = 1:N
    x = Ad*x;
    xstack(:,i) = x;

    % Covar Propagation
    P0 = Ad*P0*Ad' + Bd*Q*Bd';
    Pstack(:,:,i) = P0;
end

end