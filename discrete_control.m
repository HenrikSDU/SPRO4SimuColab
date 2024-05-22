% discretize the LQR controller
% sample time Ts
Ts = 0.001;

discrete_sys_reduced = c2d(sys_reduced,Ts);
[A_r_d,B_r_d,C_r_d,D_r_d] = ssdata(discrete_sys_reduced);
Ad = discrete_sys_reduced.B;


K_D_LQR_reduced = lqrd(A_r, B_r, Q_reduced, R_reduced, Ts);
K_DD_LQR_reduced_ = lqrd(A_r, B_r, Q_reduced, R_reduced, Ts);
K_LQR_reduced;
disp(Ad)
disp(B_r_d)

