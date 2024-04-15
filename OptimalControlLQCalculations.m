%% Optimal Control

%% Controlability & Reachability

C_r = ctrb(A,B);
if rank(C_r) == 12
    fprintf("System is reachable and controlable!")
else
    fprintf("System is not reachable!")
end

%step(glb_state_space)
%pzmap(glb_state_space)

%% LQR Section

Q = [ 1 0 0 0 0 0 0 0 0 0 0 0;
      0 1 0 0 0 0 0 0 0 0 0 0;
      0 0 1 0 0 0 0 0 0 0 0 0;
      0 0 0 1 0 0 0 0 0 0 0 0;
      0 0 0 0 1 0 0 0 0 0 0 0;
      0 0 0 0 0 1 0 0 0 0 0 0;
      0 0 0 0 0 0 1 0 0 0 0 0;
      0 0 0 0 0 0 0 1 0 0 0 0;
      0 0 0 0 0 0 0 0 1 0 0 0;
      0 0 0 0 0 0 0 0 0 1 0 0;
      0 0 0 0 0 0 0 0 0 0 1 0;
      0 0 0 0 0 0 0 0 0 0 0 1;];
%penalizes actuators
R = [ 1 0 0 0;
      0 1 0 0;
      0 0 1 0;
      0 0 0 1;];
%find K
K_LQR = lqr(A, B, Q, R);
%closed loop system
sys_LQR = ss((A-B*K_LQR),B,C,D);
step(sys_LQR)
%pzmap(sys_LQR)
fprintf('done')
%% plotting the system response with K


%% LQI Section

% Define Extended State Space
A_e = [A zeros(12,6);
       C zeros(6,6);];
B_e = [B;
      -D];

C_e = [C zeros(6,6)];

D_e = D;

C_r_lqi = ctrb(A_e, B_e);
rank(C_r_lqi);