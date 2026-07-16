function [xStack, PStack] = packStates(x_INS, P_INS, x_GNS, P_GNS, x12, P12)
    % Determine state dimensions
    n = size(x_INS, 1);

    % Preallocate stack arrays
    xStack = zeros(n, 1, 3);
    PStack = zeros(n, n, 3);

    % Assign each filter to the stack
    xStack(:, :, 1) = x_INS;
    PStack(:, :, 1) = P_INS;

    xStack(:, :, 2) = x_GNS;
    PStack(:, :, 2) = P_GNS;

    xStack(:, :, 3) = x12;
    PStack(:, :, 3) = P12;
end