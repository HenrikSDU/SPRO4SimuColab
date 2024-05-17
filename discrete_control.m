% discretize the LQR controller

K_D_LQR_reduced = lqrd(A_r, B_r, Q_reduced, R_reduced, 1)
K_LQR_reduced;