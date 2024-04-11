%% Optimal Control

%% Controlability & Reachability

C_r = ctrb(A,B);
rank(C_r);
%% LQR Section





%% LQI Section

% Define Extended State Space
A_e = [A zeros(12,6);
       C zeros(6,6);];
B_e = [B;
      -D];

C_e = [C zeros(6,6)];

D_e = D;

C_r_lqi = ctr