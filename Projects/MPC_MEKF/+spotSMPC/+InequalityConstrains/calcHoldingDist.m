function [r_hold,proximity] = calcHoldingDist(r_hold, proximity, xref, xact, eta, zeta, gamma, r_hold_min)

xref_current = xref(1:3); 
error = xref_current(1:2) - xact(1:2);
ang_err = abs(atan2(sin(xact(3) - xref_current(3)), cos(xact(3) - xref_current(3))));

err_sqr = error'*error;

if err_sqr < eta 
    if ang_err < zeta
        r_hold = gamma*r_hold;
        proximity = true;
    end
end

r_hold = max(r_hold_min, r_hold);
end