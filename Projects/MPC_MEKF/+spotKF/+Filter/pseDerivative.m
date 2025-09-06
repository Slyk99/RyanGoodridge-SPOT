function y = pseDerivative(v, Ts, a)
% pseudo derivative
% v  - current velocity sample
% Ts - sample time (constant)
% a  - low pass constant
% a low pas filter tf = a / (s + a) and the tf for a derivative is s
% The multiplication gives a smoothed derivative with the tf as/(s+a)
% than can be computed discretely as below

persistent x
if isempty(x)
    x = zeros(length(v),1);
end

% Update state
x = (1 - a*Ts)*x + a*Ts*v;

% Output
y = -a*x + a*v;
end
