%%only hover, no x and y
A_r = [0 0 0 0 1 0 0 0;
       0 0 0 0 0 1 0 0;
       0 0 0 0 0 0 1 0;
       0 0 0 0 0 0 0 1;
       0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 0 0;
       0 0 0 0 0 0 0 0;];
B_r =[0 0 0 0;
      0 0 0 0;
      0 0 0 0;
      0 0 0 0;
      1/m 0 0 0;
      0 1/I_x 0 0;
      0 0 1/I_y 0;
      0 0 0 1/I_z];
C_r = [1 0 0 0 0 0 0 0;
       0 1 0 0 0 0 0 0;
       0 0 1 0 0 0 0 0;
       0 0 0 1 0 0 0 0;];

D_r = zeros(4,4);

sys = ss(A_r,B_r,C_r,D_r);

obs_reduced = obsv(A_r, C_r);
rank_reduced = rank(obs_reduced)


    