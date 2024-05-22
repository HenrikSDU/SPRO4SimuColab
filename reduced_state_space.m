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
       0 0 0 1 0 0 0 0;
       0 0 0 0 0 1 0 0;
       0 0 0 0 0 0 1 0;
       0 0 0 0 0 0 0 1;      
       ];
D_r = zeros(7,4);

C_r_r = [1 0 0 0 0 0 0 0;
       0 1 0 0 0 0 0 0;
       0 0 1 0 0 0 0 0;
       0 0 0 1 0 0 0 0;
       0 0 0 0 1 0 0 0;
       0 0 0 0 0 1 0 0;
       0 0 0 0 0 0 1 0;
       0 0 0 0 0 0 0 1;      
       ];
sys_reduced = ss(A_r, B_r, C_r, D_r);

if 8 == rank(obsv(A_r,C_r))
    disp('System is observable!')
end


x0_r = [0;0;0;0;0;0;0;0;];%initial condition
%%
Max_z_r = 0.05; % Max distance allowed on z _axis (m)
Max_r_r = 2*(pi/180); % Max roll allowed (°)
Max_p_r = 2 *(pi/180); % Max pitch allowed (°)
Max_ya_r = 2 *(pi/180); % Max yaw allowed (°)
 

Max_z_dot_r = 0.03; % Maximum allowed velocity on the z - axis (m/s)
Max_r_dot_r = 0.1; % Maximum allowed roll rate (rad/s)
Max_p_dot_r = 0.1; % Maximum allowed picth rate (rad/s)
Max_ya_dot_r = 0.01; % Maximum allowed yaw rate (rad/s)
 
Max_Mx_r = 5.17e-3; % Max moment on x - axis kgm^2
Max_My_r = 5.17e-3; % Max moment on y - axis kgm^2
Max_Mz_r = 1.7e-2;  % Max moment on z - axis kgm^2

Max_U_r = 4 * 0.2 * 9.81; % Maximum thrust - maximum allowable current to esc is 60A ==> 15A per motor
              % motor with less that 15A has 581g of thrust at 13.28A
              % (581*4)/1000 to get kg


Q_reduced = [0.9/(Max_z_r)^2 0 0 0 0 0 0 0;
             0 3/(Max_r_r)^2 0 0 0 0 0 0;
             0 0 3/(Max_p_r)^2 0 0 0 0 0;
             0 0 0 3.5/(Max_ya_r)^2 0 0 0 0;
             0 0 0 0 0.5/(Max_z_dot_r)^2 0 0 0;
             0 0 0 0 0 22/(Max_r_dot_r)^2 0 0;
             0 0 0 0 0 0 23/(Max_p_dot_r^2) 0;
             0 0 0 0 0 0 0 0.3/(Max_ya_dot_r)^2;];
R_reduced = [0.5/(Max_U_r)^2 0 0 0;
             0 0.01/(Max_Mx_r)^2 0 0;
             0 0 0.01/(Max_My_r)^2 0;
             0 0 0 1/(Max_Mz_r)^2;];

K_LQR_reduced = lqr(A_r, B_r, Q_reduced, R_reduced, 0);



sys_LQR_reduced_contr = ss(A_r - B_r * K_LQR_reduced, B_r, C_r, D_r);

C_red = ctrb(A_r,B_r);
if rank(C_red) == 8
    fprintf("\nSystem is reachable and controlable!")
else
    fprintf("\nSystem is not reachable!")
end

%% Check robustness
Lo = sys_reduced * K_LQR_reduced;
%diskmargin(Lo)
%% Observability without z_dot and yaw

C_y = [1 0 0 0 0 0 0 0;
       0 1 0 0 0 0 0 0;
       0 0 1 0 0 0 0 0;
       0 0 0 0 0 1 0 0;
       0 0 0 0 0 0 1 0;
       0 0 0 0 0 0 0 1;      
       ];
observ = obsv(A_r,C_y);
rank(observ);
%Dont remove YAW, we gotta figure out how to measure yaw

