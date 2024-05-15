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
m= 0.8; % Mass of entire drone in kg from Table 1 (LQvsHinf paper)
r = 0.25; % Distance between center of quad and propeller in m
%I_x = 0.0196; % Moment of inertia around x axis kgm^2
%I_y = 0.0196; % Moment of inertia around y axis kgm^2
%I_z = 0.0264; % Moment of inertia around z axis kgm^2
I_x = 5.17e-3; % Moment of inertia around x axis kgm^2
I_y = 5.17e-3; % Moment of inertia around y axis kgm^2
I_z = 1.7e-2; % Moment of inertia around z axis kgm^2
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
%% pz plot 
LQR_contr_sys = ss(A - B * K_LQR, B, C, D);
pzmap(sys_lqi_controlled)





