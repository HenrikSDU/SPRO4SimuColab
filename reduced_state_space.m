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

sys_reduced = ss(A_r, B_r, C_r, D_r);


x0_r = [0;0;0;0;0;0;0;0;];%initial condition
%%
Max_z = 0.4; % Max distance allowed on z _axis (m)
Max_r = 2*(pi/180); % Max roll allowed (°)
Max_p = 2 *(pi/180); % Max pitch allowed (°)
Max_ya = 2 *(pi/180); % Max yaw allowed (°)
 

Max_z_dot = 0.05; % Maximum allowed velocity on the z - axis (m/s)
Max_r_dot = 0.57; % Maximum allowed roll rate (degree/s)
Max_p_dot = 0.57; % Maximum allowed picth rate (degree/s)
Max_ya_dot = 0.57; % Maximum allowed yaw rate (degree/s)
 
Max_Mx = 5.17e-3; % Max moment on x - axis kgm^2
Max_My = 5.17e-3; % Max moment on y - axis kgm^2
Max_Mz = 1.7e-2;  % Max moment on z - axis kgm^2

Max_U = 1.2 * 9.81; % Maximum thrust - maximum allowable current to esc is 60A ==> 15A per motor
              % motor with less that 15A has 581g of thrust at 13.28A
              % (581*4)/1000 to get kg


Q_reduced = [0.9/(Max_z)^2 0 0 0 0 0 0 0;
             0 0.6/(Max_r)^2 0 0 0 0 0 0;
             0 0 1/(Max_p)^2 0 0 0 0 0;
             0 0 0 1/(Max_ya)^2 0 0 0 0;
             0 0 0 0 0.105/(Max_z_dot)^2 0 0 0;
             0 0 0 0 0 225/(Max_r_dot)^2 0 0;
             0 0 0 0 0 0 156/(Max_p_dot^2) 0;
             0 0 0 0 0 0 0 156/(Max_ya_dot)^2;];
R_reduced = [0.5/(Max_U)^2 0 0 0;
             0 5/(Max_Mx)^2 0 0;
             0 0 35/(Max_My)^2 0;
             0 0 0 35/(Max_Mz)^2;];

K_LQR_reduced = lqr(A_r, B_r, Q_reduced, R_reduced, 0)



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
%% 
step(sys_LQR_reduced_contr)


