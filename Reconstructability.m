%% Checking reachability of the state spaces:

reconstr_mat = ctrb(transpose(A_e),transpose(C_e));

rank(reconstr_mat)