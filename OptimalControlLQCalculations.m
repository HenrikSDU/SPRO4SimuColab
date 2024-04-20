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
Max_x = 0.1 %max distance allowed on the x_axis(m)
Max_y = 0.1 %max distance allowed on y-axis
Max_z = 0.35 %max distance allowed on z _axis
Max_r = 2 %max roll allowed
Max_p = 2 %max pitch allowed
Max_y = 2 %max yaw allowed

Max_x_dot = 0.135 %maximum allowed velocity on the x-axis
Max_y_dot = 0.135 %maximum allowed velocity on the y -axis
Max_z_dot = 0.135 %maximum allowed velocity on the z - axis
Max_r_dot = 0.01 %maximum allowed roll rate
Max_p_dot = 0.01 %maximum allowed picth rate
Max_y_dot = 0.01 %maximum allowed yaw rate
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


%closed loop system

K_LQR = lqr(A, B, Q, R, 0);

%closed loop system
sys_LQR = ss((A-B*K_LQR),B,C,D);
figure;
t = 0:0.01:5;
step(sys_LQR,10);
title('Step Response of LQR Controlled System'); 
%pzmap(sys_LQR)

fprintf('done')
%% plotting the system response with K
%states_timeseries = simout.States

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

