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

% Matrixes for state space
% ... for State Equation A & B
%A = [0 0 0 1 0 0 0 0 0 0 0 0; 
 %   0 0 0 0 1 0 0 0 0 0 0 0; 
  %  0 0 0 0 0 1 0 0 0 0 0 0;
   % 0 0 0 0 0 0 0 -g 0 0 0 0;
    %0 0 0 0 0 0 g 0 0 0 0 0;
    %0 0 0 0 0 0 0 0 0 0 0 0;
    %0 0 0 0 0 0 0 0 0 1 0 0;
    %0 0 0 0 0 0 0 0 0 0 1 0;
    %0 0 0 0 0 0 0 0 0 0 0 1;
    %0 0 0 0 0 0 0 0 0 0 0 0;
    %0 0 0 0 0 0 0 0 0 0 0 0;
    %0 0 0 0 0 0 0 0 0 0 0 0];

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
%A = [zeros(3,4) zeros(3,1) zeros(3,1) eye(3) zeros(3,3);
 %    zeros(3,4) zeros(3,1) zeros(3,1) zeros(3,3) eye(3);
  %   zeros(1,4) 0 g zeros(1,3) zeros(1,3);
   %  zeros(1,4) -g 0 zeros(1,3) zeros(1,3);
    % zeros(4,4) zeros(4,1) zeros(4,1) zeros(4,3) zeros(4,3);
    %];
%B = [zeros(8,4);
 %    1/m 0 0 0;
  %   0 1/I_x 0 0;
   %  0  0 1/I_y 0;
    % 0 0 0 1/I_z
     %];

% ... for Output Equation C & D

%C = [1 0 0 0 0 0 0 0 0 0 0 0;
     %0 1 0 0 0 0 0 0 0 0 0 0;
     %0 0 1 0 0 0 0 0 0 0 0 0;
     %0 0 0 0 0 0 1 0 0 0 0 0;
     %0 0 0 0 0 0 0 1 0 0 0 0;
     %0 0 0 0 0 0 0 0 1 0 0 0];

%C = [eye(3) zeros(3,2) zeros(3,1) zeros(3,6);
%    zeros(1,3) zeros(1,2) 1 zeros(1,6);];

C = [1 0 0 0 0 0 0 0 0 0 0 0;
     0 1 0 0 0 0 0 0 0 0 0 0;
     0 0 1 0 0 0 0 0 0 0 0 0;
     0 0 0 1 0 0 0 0 0 0 0 0;
     0 0 0 0 1 0 0 0 0 0 0 0;
     0 0 0 0 0 1 0 0 0 0 0 0;];
     
D = zeros(6,4);

% Initial conditions
x0 = [0;0;0;0;0;0;0;0;0;0;0;0;];



