function [x_INS, P_INS, x_GNS, P_GNS, x12, P12] = unpackStates(xStack, PStack)
    % Unpack each estimate from the stack
    x_INS = xStack(:, :, 1);
    P_INS = PStack(:, :, 1);

    x_GNS = xStack(:, :, 2);
    P_GNS = PStack(:, :, 2);

    x12 = xStack(:, :, 3);
    P12 = PStack(:, :, 3);
end
