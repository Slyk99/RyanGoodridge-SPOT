clc
% SaveExpLog

[RED,BLACK,RKF,STRKF,QKF,STQKF,DQKF,STDQKF,CNN,t] = unpackData(dataClass_rt);

%%
plotData(BLACK,t)
plotData(RED,t)

% plotForce(BLACK,t)

