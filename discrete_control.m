% discretize the LQR controller

K_D_LQR_reduced = dlqr(A_r, B_r, Q_reduced, R_reduced, 0);
