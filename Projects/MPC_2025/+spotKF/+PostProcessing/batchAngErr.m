function err = batchAngErr(theta1,theta2)
t = length(theta1);
err = zeros(t,1);

for i = 1:1:t
    err(i,1) = NavigationModule_new.Misc.angErr(theta1(i,1), theta2(i,1));
end
end