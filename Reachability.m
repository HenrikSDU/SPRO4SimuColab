%% Checking reachability of the state spaces:

reach_mat = obsv(transpose(A_e),transpose(B_e));

rank(reach_mat)