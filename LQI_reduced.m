%% Reduced LQI

% Define extended reduced state space
E = [1 0 0 0 0 0 0 0;];

A_e_r = [A_r zeros(8,1);
        -E zeros(1);];
B_e_r = [B_r;
        -zeros(1,4)];
C_e_r = [E zeros(1)];

sys_lqi_reduced = ss(A_e_r, B_e_r,C_e_r,0);

controlability = ctrb(A_e_r,B_e_r);

rank(controlability)

observability = obsv(A_e_r, C_e_r);
rank(observability)



Max_z_error = 0.05;
Max_r_error = Max_r;
Max_p_error = Max_p;
Max_yaw_error = Max_y;

Max_r_dot_error = 1;
Max_p_dot_error = 1;
Max_yaw_dot_error = 1;

Q_lqi_reduced = [0.9/(Max_z)^2 0 0 0 0 0 0 0 0;
                 0 100/(Max_r)^2 0 0 0 0 0 0 0;
                 0 0 100/(Max_p)^2 0 0 0 0 0 0;
                 0 0 0 1/(Max_ya)^2 0 0 0 0 0;
                 0 0 0 0 0.5/(Max_z_dot)^2 0 0 0 0;
                 0 0 0 0 0 10/(Max_r_dot)^2 0 0 0;
                 0 0 0 0 0 0 10/(Max_p_dot^2) 0 0;
                 0 0 0 0 0 0 0 1/(Max_ya_dot)^2 0;
                 0 0 0 0 0 0 0 0 1/(1)^2;
                 ];
R_lqi_reduced = [10/(Max_U)^2 0 0 0;
                 0 5/(Max_Mx)^2 0 0;
                 0 0 35/(Max_My)^2 0;
                 0 0 0 35/(Max_Mz)^2;];
%{  
Q_lqi_reduced = [1/(Max_z)^2 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
                 0 1/(Max_r)^2 0 0 0 0 0 0 0 0 0 0 0 0 0;
                 0 0 1/(Max_p)^2 0 0 0 0 0 0 0 0 0 0 0 0;
                 0 0 0 1/(Max_ya)^2 0 0 0 0 0 0 0 0 0 0 0;
                 0 0 0 0 1/(Max_z_dot)^2 0 0 0 0 0 0 0 0 0 0;
                 0 0 0 0 0 1/(Max_r_dot)^2 0 0 0 0 0 0 0 0 0;
                 0 0 0 0 0 0 1/(Max_p_dot^2) 0 0 0 0 0 0 0 0;
                 0 0 0 0 0 0 0 1/(Max_ya_dot)^2 0 0 0 0 0 0 0;
                 0 0 0 0 0 0 0 0 1/(Max_z_error)^2 0 0 0 0 0 0;
                 0 0 0 0 0 0 0 0 0 1/(Max_r_error)^2 0 0 0 0 0;
                 0 0 0 0 0 0 0 0 0 0 1/(Max_p_error)^2 0 0 0 0;
                 0 0 0 0 0 0 0 0 0 0 0 1/(Max_z_error)^2 0 0 0;
                 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_r_dot_error)^2 0 0;
                 0 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_p_dot_error)^2 0;
                 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1/(Max_yaw_dot_error)^2];

R_lqi_reduced = [1/(Max_U)^2 0 0 0;
                 0 1/(Max_Mx)^2 0 0;
                 0 0 1/(Max_My)^2 0;
                 0 0 0 1/(Max_Mz)^2;];
%}
[K_lqi_reduced,~,~] = lqr(sys_lqi_reduced,Q_lqi_reduced,R_lqi_reduced);


% Extract control matrixes Kx % Ki
Kx_lqi_reduced = K_lqi_reduced(:,1:8);
Ki_lqi_reduced = K_lqi_reduced(:,9);


%% 
% Verify by finding the poles of the closed loop system
sys_lqi_controlled = ss(A_e_r - B_e_r * K_lqi_reduced, B_e_r, C_e_r, 0);

figure; % Create a new figure window
pzmap(sys_lqi_controlled)
title('Closed loop poles & zeros LQI Controlled System'); 

figure; % Create a new figure window
step(sys_lqi_controlled); 
title('Step Response of LQI Controlled System'); 

%% Alternative

F = [1 0 0 0 0 0 0 0;
     0 1 0 0 0 0 0 0;
     0 0 1 0 0 0 0 0;
     0 0 0 1 0 0 0 0;];

A_e_r_a = [A_r zeros(8,4);
            -F zeros(4);];
B_e_r_a = [B_r;
        -zeros(4,4)];
C_e_r_a = [F zeros(4,4)];

sys_lqi_reduced_a = ss(A_e_r_a, B_e_r_a,C_e_r_a,0);

controlability = ctrb(A_e_r_a,B_e_r_a);

rank(controlability)

Q_lqi_reduced_a = diag([0.9/(Max_z)^2, 100/(Max_r)^2, 100/(Max_p)^2, ...
                    100/(Max_ya)^2, 0.5/(Max_z_dot)^2, 10/(Max_r_dot)^2, ...
                    10/(Max_p_dot^2), 1/(Max_ya_dot)^2, 1/(0.2)^2,1/0.000002^2, ...
                    1/0.000002^2,1/0.2^2]);
R_lqi_reduced_a = [10/(Max_U)^2 0 0 0;
                 0 5/(Max_Mx)^2 0 0;
                 0 0 35/(Max_My)^2 0;
                 0 0 0 35/(Max_Mz)^2;];

[K_lqi_reduced_a,~,~] = lqr(sys_lqi_reduced_a,Q_lqi_reduced_a,R_lqi_reduced_a);

% Verify by finding the poles of the closed loop system
sys_lqi_controlled_a = ss(A_e_r_a - B_e_r_a * K_lqi_reduced_a, B_e_r_a, C_e_r_a, 0);

%figure; % Create a new figure window
%pzmap(sys_lqi_controlled_a)
%title('Closed loop poles & zeros LQI Controlled System'); 

%figure; % Create a new figure window
step(sys_lqi_controlled_a,10); 
%title('Step Response of LQI Controlled System'); 

Kx_lqi_reduced_a = K_lqi_reduced_a(:,1:8);
Ki_lqi_reduced_a = K_lqi_reduced_a(:,9:12);