%% Quadcopter Attributes

% Inertia (Mass, Moment of Inertia etc.)

% so far in state space file but I would suggest to move it


% Measures (Radius etc.)




% Constants & Other Parameters
battery_voltage = 25;

%%%% Calculation of lift & drag coefficient based on experimental data

% Motor: Ethix Flat Rats V2 1507 Motor - 2800 KV
% KV can be assumed to be a linear property
% - > Note: This disregards the inertia of the propellers (load), motor
%     efficiency and air resistance.

KV_rating = 2800;

% Taking the data of the test run with 100% throttle as a reference at a
% ESC Value of 2000 µS we have a thrust of 0.2807455505434443 KgF, a torque
% of 0.0456147908219349 Nm and a battery voltage of 24.42409064251908 V 
% (Time: 10.339799999999984)
% 
% According to the paper (Full Linear Control of a Quadrotor UAV, LQ vs H∞)
% (the VERYGOOD one) the thust of the motor can be modelled as b * omega^2.

thrust_kgf = 0.2807455505434443; % KgF
thrust_N = thrust_kgf * 9.81; % N

ex_battery_v = 24.42409064251908; % V

no_rot = ex_battery_v * KV_rating;

% Solving for lift coefficient
lift_co = thrust_N / no_rot^2; % N/rpm
disp("Lift coefficient:")
disp(lift_co)

% Solving for drag coefficient
torque_Nm = 0.0456147908219349; % Nm
drag_co = torque_Nm / no_rot^2; % N/rpm
disp("Drag coefficient:")
disp(drag_co)

% Test
disp("Testing Lift coefficient:")
disp(calc_thrust(1500,25,lift_co))
disp("Testing Drag coefficient:")
disp(calc_torque(1500,25,drag_co))


function thrust_kgf = calc_thrust(ESC, bat_V, lift_co)
    
    duty_cycle = (ESC - 1000)/1000;
    rot_speed = duty_cycle * bat_V * 2800;
    thrust_kgf = lift_co * rot_speed^2 / 9.81;

end

function torque_Nm = calc_torque(ESC, bat_V, drag_co)
    
    duty_cycle = (ESC - 1000)/1000;
    rot_speed = duty_cycle * bat_V * 2800;
    torque_Nm = drag_co * rot_speed^2 / 9.81;

end