function dq_rel = meas(dq_black, dq_red)
    dq_red = dqInv(dq_red,'scalarFirst');
    dq_rel = dqMultiply(dq_black,dq_red,'scalarFirst');
end