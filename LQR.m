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
      0 0 5/(Max_z)^2 0 0 0 0 0 0 0 0 0;
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
R = [ 5/(Max_U)^2 0 0 0;
      0 1/(Max_Ix)^2 0 0;
      0 0 1/(Max_Iy)^2 0;
      0 0 0 1/(Max_Iz)^2;];
%find K


%closed loop system

K_LQR = lqr(A, B, Q, R, 0);

%closed loop system
%pzmap(sys_LQR)

fprintf('////////////////////DONE///////////////////////////')
 %% plotting the system response with K_LQR
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
%% %% Plot for X
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.x
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Position [m]', 'FontSize', font_size)
title("Plot for x", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_X_position_gain", file_type))
end
%% Plot for y
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.y
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
%% %% Plot fo z
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.z
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Position [m]', 'FontSize', font_size)
title("Plot for z", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_Z_position_gain", file_type))
end
%% Plot for roll
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.roll
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Degree [°]', 'FontSize', font_size)
title("Plot for roll", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_roll_angle_gain", file_type))
end
%%  Plot for pitch
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.pitch
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Degree [°]', 'FontSize', font_size)
title("Plot for picth", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_pitch_angle_gain", file_type))
end
%% %% Plot for yaw
simout=sim("DroneModel.slx", "StopTime", "20");
states_out=out.yaw
refs_out = out.refs
position_fig=figure;

plot(states_out.Time, states_out.Data(:, 1), ...
     refs_out.Time, refs_out.Data(:, 1), "--", "LineWidth", lin_width)
xlabel('Time [s]', 'FontSize', font_size)
ylabel('Degree [°]', 'FontSize', font_size)
title("Plot for yaw", 'FontSize', font_size)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size-4, 'Location', 'northeast')
if(save_files)
    exportgraphics(position_fig, append(final_directory, "\LQR_pitch_angle_gain", file_type))
end


