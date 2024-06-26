%% LQI Section

%% LQI State Space 
C_lqi = [1 0 0 0 0 0 0 0 0 0 0 0;
         0 1 0 0 0 0 0 0 0 0 0 0;
         0 0 1 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 1 0 0 0 0 0 0;];

D_lqi = zeros(4,4);


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

Max_x_error = 0.5;
Max_y_error = 0.5;
Max_z_error = 0.4;
Max_yaw_error = 1;

Q_lqi = [1/(Max_x)^2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 1/(Max_y)^2 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 1/(Max_z)^2 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 1/(Max_r)^2 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 1/(Max_p)^2 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 1/(Max_ya)^2 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 1/(Max_x_dot)^2 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 1/(Max_y_dot)^2 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 1/(Max_z_dot)^2 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 1/(Max_r_dot)^2 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 1/(Max_p_dot)^2 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 1/(Max_ya_dot)^2 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_x_error)^2 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_y_error)^2  0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_z_error)^2 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_yaw_error)^2;];
        
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