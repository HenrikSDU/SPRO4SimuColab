%% Entering State-Space
% https://www.youtube.com/watch?v=TKBm1GzxUO8&t=1208s
% This video illustrates how to build a statespace model from/for a drone.
% The naming references can be found on teams under Modeling -> Matlab &
% Simulink.
% https://www.youtube.com/watch?v=zIiF44h5um0&t=388s
% This video illustrates how to implement a statespace model in simulink


% Mechanical Parameters
% (tempory until actual come in)
%m = 0.5; % Mass of entire drone in kg
m = 0.4259; % Mass of entire drone in kg from Table 1 (LQvsHinf paper)
r = 0.1148; % Distance between center of quad and propeller in m
%I_x = 0.0196; % Moment of inertia around x axis kgm^2
%I_y = 0.0196; % Moment of inertia around y axis kgm^2
%I_z = 0.0264; % Moment of inertia around z axis kgm^2
I_x = 0.0012; % Moment of inertia around x axis kgm^2
I_y = 0.0012; % Moment of inertia around y axis kgm^2
I_z = 0.0017; % Moment of inertia around z axis kgm^2
I_p = 0.0001; % Moment of inertia of propeller
c = 0.1; % Force to moment scaling facto in m^-1
g = 9.81; % Acceleration due to gravity m/s^2

Inertia_Mat = [I_x    0    0; % Used in 6DOF-block
                 0  I_y    0;
                 0    0  I_z];
% Matrixes for state space
% ... for State Equation A & B

A = [0 0 0 0 0 0 1 0 0 0 0 0;
     0 0 0 0 0 0 0 1 0 0 0 0;
     0 0 0 0 0 0 0 0 1 0 0 0;
     0 0 0 0 0 0 0 0 0 1 0 0;
     0 0 0 0 0 0 0 0 0 0 1 0;
     0 0 0 0 0 0 0 0 0 0 0 1;
     0 0 0 0 g 0 0 0 0 0 0 0;
     0 0 0 -g 0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0 0 0 0 0;];

B = [0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     0 0 0 0;
     1/m 0 0 0;
     0 1/I_x 0 0;
     0 0 1/I_y 0;
     0 0 0 1/I_z];

C = [1 0 0 0 0 0 0 0 0 0 0 0;
     0 1 0 0 0 0 0 0 0 0 0 0;
     0 0 1 0 0 0 0 0 0 0 0 0;
     0 0 0 1 0 0 0 0 0 0 0 0;
     0 0 0 0 1 0 0 0 0 0 0 0;
     0 0 0 0 0 1 0 0 0 0 0 0;];
     
D = zeros(6,4);

glb_state_space = ss(A, B, C, D);

%% Discretize State Space



%% System Definition

%% Initial conditions
x0 = [0;0;0;0;0;0;0;0;0;0;0;0;];

%% reachability, stability and observability
%% LQR gain calculations
%% LQR Section
Max_x = 0.1; %max distance allowed on the x_axis(m)
Max_y = 0.1; %max distance allowed on y-axis (m)
Max_z = 0.4; %max distance allowed on z _axis (m)
Max_r = 2*(pi/180); %max roll allowed (°)
Max_p = 2 *(pi/180);%max pitch allowed (°)
Max_ya = 2 *(pi/180);%max yaw allowed (°)

Max_x_dot = 0.05; %maximum allowed velocity on the x-axis (m/s)
Max_y_dot = 0.05; %maximum allowed velocity on the y -axis (m/s)
Max_z_dot = 0.135; %maximum allowed velocity on the z - axis (m/s)
Max_r_dot = 0.57; %maximum allowed roll rate (degree/s)
Max_p_dot = 0.57; %maximum allowed picth rate (degree/s)
Max_ya_dot = 0.57; %maximum allowed yaw rate (degree/s)

Max_Mx = 5.17e-3; %Max moment on x - axis kgm^2
Max_My = 5.17e-3; %Max moment on x - axis kgm^2
Max_Mz = 1.7e-2;  %Max moment on x - axis kgm^2

Max_U = 1.2 * 9.81; %Maximum thrust = 11.772 N  - maximum allowable current to esc is 60A ==> 15A per motor
                   % motor with less that 15A has 581g of thrust at 13.28A
                   % (581*4)/1000 to get kg

Q = [ 4/(Max_x)^2 0 0 0 0 0 0 0 0 0 0 0;
      0 5/(Max_y)^2 0 0 0 0 0 0 0 0 0 0;
      0 0 5/(Max_z)^2 0 0 0 0 0 0 0 0 0;
      0 0 0 3.2/(Max_r)^2 0 0 0 0 0 0 0 0;
      0 0 0 0 1/(Max_p)^2 0 0 0 0 0 0 0;
      0 0 0 0 0 1/(Max_ya)^2 0 0 0 0 0 0;
      0 0 0 0 0 0 0.4/(Max_x_dot)^2 0 0 0 0 0;
      0 0 0 0 0 0 0 0.45/(Max_y_dot)^2 0 0 0 0;
      0 0 0 0 0 0 0 0 0.46/(Max_z_dot)^2 0 0 0;
      0 0 0 0 0 0 0 0 0 1/(Max_r_dot)^2 0 0;
      0 0 0 0 0 0 0 0 0 0 8/(Max_p_dot)^2 0;
      0 0 0 0 0 0 0 0 0 0 0 1/(Max_ya_dot)^2;];
%penalizes actuators
R = [ 100/(Max_U)^2 0 0 0;
      0 1/(Max_Mx)^2 0 0;
      0 0 1/(Max_My)^2 0;
      0 0 0 10/(Max_Mz)^2;];
%find K


%closed loop system

K_LQR = lqr(A, B, Q, R, 0)

%closed loop system
%pzmap(sys_LQR)

fprintf('////////////////////DONE///////////////////////////')

%% %% pz plot 
LQR_contr_sys = ss(A - B * K_LQR, B, C, D);
pzmap(LQR_contr_sys)
C_r = ctrb(A,B);
if rank(C_r) == 12
    fprintf("\nSystem is reachable and controlable!")
else
    fprintf("\nSystem is not reachable!")
end

Ob = obsv(LQR_contr_sys);
unobsv = length(A) - rank(Ob);

if unobsv==0
    fprintf("\nState space is observable, %d", unobsv)
else
    fprintf("\nSystem is un-observable and number of unobservable states is %d",unobsv)
end




