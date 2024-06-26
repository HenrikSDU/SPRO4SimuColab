%% LQI Section

% Define Extended State Space
A_e = [A zeros(12,4);
       -C_lqi zeros(4,4);];
B_e = [B;
      -D_lqi];

C_e = [C_lqi zeros(4,4)];

D_e = D_lqi;

sys_LQI = ss(A_e,B_e,C_e,D_e);
% Check Controllability
C_r_lqi = ctrb(A_e, B_e);
rank(C_r_lqi)

Q_lqi = [1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1;];
        
R_lqi = [1 0 0 0;
         0 1 0 0;
         0 0 1 0;
         0 0 0 1;];

[K_lqi,~,~] = lqr(sys_LQI,Q_lqi,R_lqi);

% Verify by finding the poles of the closed loop system
sys_lqi_controlled = ss(A_e - B_e * K_lqi, B_e, C_e, D_e);

figure; % Create a new figure window
pzmap(sys_lqi_controlled)
title('Closed loop poles & zeros LQI Controlled System'); 

figure; % Create a new figure window
step(sys_lqi_controlled); 
title('Step Response of LQI Controlled System'); 

% Extract control matrixes Kx % Ki
Kx_lqi = K_lqi(:,1:12);
Ki_lqi = K_lqi(:,13:16);