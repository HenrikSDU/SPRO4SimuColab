%% Optimal Control

%% Controlability & Reachability

C_r = ctrb(A,B);
if rank(C_r) == 12
    fprintf("System is reachable and controlable!")
else
    fprintf("System is not reachable!")
end


%step(glb_state_space)
%pzmap(glb_state_space)

%% LQR Section
Max_x = 0.1 %max distance allowed on the x_axis(m)
Max_y = 0.1 %max distance allowed on y-axis (m)
Max_z = 0.35 %max distance allowed on z _axis (m)
Max_r = 2 %max roll allowed (°)
Max_p = 2 %max pitch allowed (°)
Max_y = 2 %max yaw allowed (°)

Max_x_dot = 0.135 %maximum allowed velocity on the x-axis (m/s)
Max_y_dot = 0.135 %maximum allowed velocity on the y -axis (m/s)
Max_z_dot = 0.135 %maximum allowed velocity on the z - axis (m/s)
Max_r_dot = 0.57 %maximum allowed roll rate (degree/s)
Max_p_dot = 0.57 %maximum allowed picth rate (degree/s)
Max_ya_dot = 0.57 %maximum allowed yaw rate (degree/s)

Max_Ix = 5.17e-3 %Max inertia on x - axis kgm^2
Max_Iy = 5.17e-3 %Max inertia on x - axis kgm^2
Max_Iz = 1.7e-2  %Max inertia on x - axis kgm^2

Max_U = 2.324 %Maximum thrust - maximum allowable current to esc is 60A ==> 15A per motor
              % motor with less that 15A has 581g of thrust at 13.28A
              % (581*4)/1000 to get kg

Q = [ 3/(Max_x)^2 0 0 0 0 0 0 0 0 0 0 0;
      0 3/(Max_y)^2 0 0 0 0 0 0 0 0 0 0;
      0 0 6/(Max_z)^2 0 0 0 0 0 0 0 0 0;
      0 0 0 1/(Max_r)^2 0 0 0 0 0 0 0 0;
      0 0 0 0 1/(Max_p)^2 0 0 0 0 0 0 0;
      0 0 0 0 0 1/(Max_y)^2 0 0 0 0 0 0;
      0 0 0 0 0 0 1/(Max_x_dot)^2 0 0 0 0 0;
      0 0 0 0 0 0 0 1/(Max_y_dot)^2 0 0 0 0;
      0 0 0 0 0 0 0 0 1/(Max_z_dot)^2 0 0 0;
      0 0 0 0 0 0 0 0 0 1/(Max_r_dot)^2 0 0;
      0 0 0 0 0 0 0 0 0 0 1/(Max_p_dot)^2 0;
      0 0 0 0 0 0 0 0 0 0 0 1/(Max_ya_dot)^2;];
%penalizes actuators
R = [ 2/(Max_U)^2 0 0 0;
      0 1/(Max_Ix)^2 0 0;
      0 0 1/(Max_Iy)^2 0;
      0 0 0 1/(Max_Iz)^2;];
%find K


%closed loop system

K_LQR = lqr(A, B, Q, R, 0);

%closed loop system
%pzmap(sys_LQR)

fprintf('////////////////////DONE///////////////////////////')
%% plotting the system response with K
file_type=".emf";

font_size=18;

lin_width=1.5;

window_max=0;
%use your won directory
final_directory='C:/Users/Dario/Desktop/semester 4/Project/matlab & simulink/LQR/LQR_plots';

if (~isfolder(final_directory))
    %Then create it!
    mkdir(final_directory);
end

save_files=true;
fprintf('done')
% End of settings
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.states
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Position [m]', 'FontSize', font_size)
title("Plot for y", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_Y_position_gain", file_type))
end
%% LQI Section

% Define Extended State Space
A_e = [A zeros(12,4);
       -C_lqi zeros(4,4);];
B_e = [B;
      -D_lqi];

C_e = [C_lqi zeros(4,4)];

D_e = D_lqi;

sys_LQI = ss(A_e,B_e,C_e,D_e);
% Check Controllability
C_r_lqi = ctrb(A_e, B_e);
rank(C_r_lqi)

Q_lqi = [1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0;
         0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1;];
        
R_lqi = [1 0 0 0;
         0 1 0 0;
         0 0 1 0;
         0 0 0 1;];

[K_lqi,~,~] = lqr(sys_LQI,Q_lqi,R_lqi);

% Verify by finding the poles of the closed loop system
sys_lqi_controlled = ss(A_e - B_e * K_lqi, B_e, C_e, D_e);

figure; % Create a new figure window
pzmap(sys_lqi_controlled)
title('Closed loop poles & zeros LQI Controlled System'); 

figure; % Create a new figure window
step(sys_lqi_controlled); 
title('Step Response of LQI Controlled System'); 

% Extract control matrixes Kx % Ki
Kx_lqi = K_lqi(:,1:12);
Ki_lqi = K_lqi(:,13:16);

