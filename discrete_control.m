% discretize the LQR controller

K_D_LQR_reduced = lqrd(A_r, B_r, Q_reduced, R_reduced, 0.0001);
K_LQR_reduced;

