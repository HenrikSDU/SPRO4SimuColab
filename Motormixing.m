%% Motor Mixing

dis = 81.17 * 10^-3; % Perpendicular distance from x/y axis to motor 
dr = drag_co / lift_co;
% ths matrix is used in formula:
%  [Thrust, Mx,My,Mz] = K_mm_FtoU * [F1,F2,F3,F4]
K_mm_FtoU = [   1    1    1    1;
               dis  -dis  -dis dis;
               dis  dis  -dis -dis;
                dr  -dr   dr   -dr;];
% we need it like this
% [F1,F2,F3,F4] = [Thurst,Mx,My,Mz]*K_mm^(-1)
K_mm = inv(K_mm_FtoU);

