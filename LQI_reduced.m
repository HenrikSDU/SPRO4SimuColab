%% Reduced LQI

% Define extended reduced state space
C_r_alt = [1 0 0 0 0 0 0 0;
           0 1 0 0 0 0 0 0;
           0 0 1 0 0 0 0 0;
           0 0 0 1 0 0 0 0;
           0 0 0 0 0 1 0 0;
           0 0 0 0 0 0 1 0;
           0 0 0 0 0 0 0 1;];
A_e_r = [A_r zeros(8,4);
        -C_r zeros(4,4);];
B_e_r = [B_r;
        -zeros(4,4)];
C_e_r = [C_r zeros(4,4)];

sys_lqi_reduced = ss(A_e_r, B_e_r,C_e_r,0);

controlability = ctrb(A_e_r,B_e_r);

rank(controlability)

rank(ctrb(transpose(A_e_r),transpose(C_e_r)))

Max_z_error = 0.05;
Max_r_error = Max_r;
Max_p_error = Max_p;
Max_yaw_error = Max_y;
Q_lqi_reduced = [1/(Max_z)^2 0 0 0 0 0 0 0 0 0 0 0;
             0 1/(Max_r)^2 0 0 0 0 0 0 0 0 0 0;
             0 0 1/(Max_p)^2 0 0 0 0 0 0 0 0 0;
             0 0 0 1/(Max_ya)^2 0 0 0 0 0 0 0 0;
             0 0 0 0 1/(Max_z_dot)^2 0 0 0 0 0 0 0;
             0 0 0 0 0 1/(Max_r_dot)^2 0 0 0 0 0 0;
             0 0 0 0 0 0 1/(Max_p_dot^2) 0 0 0 0 0;
             0 0 0 0 0 0 0 1/(Max_ya_dot)^2 0 0 0 0;
             0 0 0 0 0 0 0 0 1/(Max_z_error)^2 0 0 0;
             0 0 0 0 0 0 0 0 0 1/(Max_r_error)^2 0 0;
             0 0 0 0 0 0 0 0 0 0 1/(Max_p_error)^2 0;
             0 0 0 0 0 0 0 0 0 0 0 1/(Max_yaw_error)^2];
R_lqi_reduced = [1/(Max_U)^2 0 0 0;
                0 1/(Max_Mx)^2 0 0;
                0 0 1/(Max_My)^2 0;
                0 0 0 1/(Max_Mz)^2;];

[K_lqi_reduced,~,~] = lqr(sys_lqi_reduced,Q_lqi_reduced,R_lqi_reduced);


% Extract control matrixes Kx % Ki
Kx_lqi_reduced = K_lqi(:,1:8);
Ki_lqi_reduced = K_lqi(:,9:12);


%% 
% Verify by finding the poles of the closed loop system
sys_lqi_controlled = ss(A_e_r - B_e_r * K_lqi_reduced, B_e_r, C_e_r, zeros(4,4));

figure; % Create a new figure window
pzmap(sys_lqi_controlled)
title('Closed loop poles & zeros LQI Controlled System'); 

figure; % Create a new figure window
step(sys_lqi_controlled); 
title('Step Response of LQI Controlled System'); 