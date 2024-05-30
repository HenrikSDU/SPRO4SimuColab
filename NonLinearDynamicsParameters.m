%% This file is for the initial conditions of the nonlinear dynamics

coder.extrinsic(rotor_sp_rec, non_linear_model)

% Angles in the earth frame
psi = 0; % yaw
theta = 0; % pitch
phi = 0; % roll


% Rotation Matrix
T_E_B = [1 -sin(phi)*tan(theta) cos(phi)*tan(theta);
         0       cos(theta)         -sin(phi);
         0  sin(phi)* cos(theta)   cos(phi)/cos(theta) ];

% Calculation of lift coefficient could most likely also be based on the following    
% https://wiki.control.fel.cvut.cz/mediawiki/images/5/5e/Dp_2017_gopalakrishnan_eswarmurthi.pdf

% But 
b = 2 * 10^-4 / 0.1047198; % based on paper that compares lq vs Hinf in N/rpm converted to rad/s
% And drag coeeficient
d = 7 * 10^-5 / 0.1047198;