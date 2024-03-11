%% Entering State-Space
% https://www.youtube.com/watch?v=TKBm1GzxUO8&t=1208s
% This video illustrates how to build a statespace model from/for a drone.
% The naming references can be found on teams under Modeling -> Matlab &
% Simulink.
% https://www.youtube.com/watch?v=zIiF44h5um0&t=388s
% This video illustrates how to implement a statespace model in simulink


% Mechanical Parameters
% (tempory until actual come in)
m = 0.5; % Mass of entire drone in kg
r = 0.25; % Distance between center of quad and propeller in m
I_x = 0.0196; % Moment of inertia around x axis kgm^2
I_y = 0.0196; % Moment of inertia around y axis kgm^2
I_z = 0.0264; % Moment of inertia around z axis kgm^2
c = 0.1; % Force to moment scaling facto in m^-1
g = -9.81; % Acceleration due to gravity m/s^2

% Matrixes for state space
% ... for State Equation A & B
A = [0 0 0 1 0 0 0 0 0 0 0 0; 
    0 0 0 0 1 0 0 0 0 0 0 0; 
    0 0 0 0 0 1 0 0 0 0 0 0;
    0 0 0 0 0 0 0 -g 0 0 0 0;
    0 0 0 0 0 0 g 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 1 0 0;
    0 0 0 0 0 0 0 0 0 0 1 0;
    0 0 0 0 0 0 0 0 0 0 0 1;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0 0 0 0 0 0];

B = [0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    1/m 1/m 1/m 1/m;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 r/I_x 0 -r/I_x;
    r/I_y 0 -r/I_y 0;
    -c/I_z c/I_z -c/I_z c/I_z];
% ... for Output Equation C & D

C = [1 0 0 0 0 0 0 0 0 0 0 0;
    0 1 0 0 0 0 0 0 0 0 0 0;
    0 0 1 0 0 0 0 0 0 0 0 0;
    0 0 0 0 0 0 1 0 0 0 0 0;
    0 0 0 0 0 0 0 1 0 0 0 0;
    0 0 0 0 0 0 0 0 1 0 0 0];

D = [0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0;
    0 0 0 0];

% Initial conditions
x0 = [0;0;0;0;0;0;0;0;0;0;0;0;];



