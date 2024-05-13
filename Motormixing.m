%% Motor Mixing

dis = 81.17 * 10^-3; % Perpendicular distance from x/y axis to motor 
dr = drag_co / lift_co;

K_mm = [   1    1    1    1;
         dis  dis -dis -dis;
        -did  dis  dis -dis;
          dr   dr  -dr  -dr;
        ];

