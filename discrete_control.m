% discretize the LQR controller
% sample time Ts
Ts = 0.01;

discrete_sys_reduced = c2d(sys_reduced,Ts);
[A_r_d,B_r_d,C_r_d,D_r_d] = ssdata(discrete_sys_reduced);

discrete_sys_reduced_lqi = c2d(sys_lqi_controlled_a,Ts);
[A_r_e_d,B_r_e_d,C_r_e_d,D_r_e_d] = ssdata(discrete_sys_reduced_lqi);
pzmap(discrete_sys_reduced_lqi)
K_D_LQR_reduced = lqrd(A_r, B_r, Q_reduced, R_reduced, Ts);
K_DD_LQR_reduced_ = lqrd(A_r, B_r, Q_reduced, R_reduced, Ts);

%% LQI discrete
K_D_LQI_reduced = lqrd(A_r_e_d, B_r_e_d, Q_lqi_reduced_a, R_lqi_reduced_a, Ts);
Kx_D_lqi_reduced_a = K_lqi_reduced_a(:,1:8);
Ki_D_lqi_reduced_a = K_lqi_reduced_a(:,9:12);
disp("Discrete Success!")

%% Printing

