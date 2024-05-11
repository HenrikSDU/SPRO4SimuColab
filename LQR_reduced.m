
% Max_z = 0.4 %max distance allowed on z _axis (m)
% Max_r = 2*(pi/180) %max roll allowed (°)
% Max_p = 2 *(pi/180)%max pitch allowed (°)
% Max_ya = 2 *(pi/180)%max yaw allowed (°)
% 

% Max_z_dot = 0.135 %maximum allowed velocity on the z - axis (m/s)
% Max_r_dot = 0.57 %maximum allowed roll rate (degree/s)
% Max_p_dot = 0.57 %maximum allowed picth rate (degree/s)
% Max_ya_dot = 0.57 %maximum allowed yaw rate (degree/s)
% 
% Max_Mx = 5.17e-3 %Max moment on x - axis kgm^2
% Max_My = 5.17e-3 %Max moment on x - axis kgm^2
% Max_Mz = 1.7e-2  %Max moment on x - axis kgm^2

%Max_U = 1.2 * 9.81 %Maximum thrust - maximum allowable current to esc is 60A ==> 15A per motor
              % motor with less that 15A has 581g of thrust at 13.28A
              % (581*4)/1000 to get kg


Q_reduced = [1/(Max_z)^2 0 0 0 0 0 0 0;
             0 1/(Max_r)^2 0 0 0 0 0 0;
             0 0 1/(Max_p)^2 0 0 0 0 0;
             0 0 0 1/(Max_ya)^2 0 0 0 0;
             0 0 0 0 1/(Max_z_dot)^2 0 0 0;
             0 0 0 0 0 1/(Max_r_dot)^2 0 0;
             0 0 0 0 0 0 1/(Max_p_dot^2) 0;
             0 0 0 0 0 0 0 1/(Max_ya_dot)^2;];
R_reduced = [1/(Max_U)^2 0 0 0;
             0 1/(Max_Mx)^2 0 0;
             0 0 1/(Max_My)^2 0;
             0 0 0 1/(Max_Mz)^2;];

K_LQR_reduced = lqr(A_r, B_r, Q_reduced, R_reduced, 0)


sys_LQR_reduced_contr = ss(A_r - B_r * K_LQR_reduced, B_r, C_r, D_r);

step(sys_LQR_reduced_contr)

%%  %% plotting the system response with K_LQR
file_type_reduced=".emf";

font_size_reduced=18;

lin_width_reduced=1.5;

window_max_reduced=0;
%use your won directory
final_directory_reduced='C:/Users/Dario/Desktop/semester 4/Project/matlab & simulink/LQR/LQR_reduced_plots';

if (~isfolder(final_directory_reduced))
    %Then create it!
    mkdir(final_directory_reduced);
end

save_files_reduced=true;
fprintf('done')
%% Plot for z
simout_reduced=sim("DroneModelV2.slx", "StopTime", "20");
states_out_reduced=out.z_r
refs_out_reduced = out.refs_r
position_fig_reduced=figure;

plot(states_out_reduced.Time, states_out_reduced.Data(:, 1), ...
     refs_out_reduced.Time, refs_out_reduced.Data(:, 1), "--", "LineWidth", lin_width_reduced)
xlabel('Time [s]', 'FontSize', font_size_reduced)
ylabel('Position [m]', 'FontSize', font_size_reduced)
title("Plot for z", 'FontSize', font_size_reduced)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size_reduced-4, 'Location', 'northeast')
if(save_files_reduced)
    exportgraphics(position_fig_reduced, append(final_directory_reduced, "\LQR_X_position_gain", file_type_reduced))
end
%% plot for roll with reduced state - space
simout_reduced=sim("DroneModelV2.slx", "StopTime", "20");
states_out_reduced=out.roll1_r
refs_out_reduced = out.refs_r
position_fig_reduced=figure;

plot(states_out_reduced.Time, states_out_reduced.Data(:, 1), ...
     refs_out_reduced.Time, refs_out_reduced.Data(:, 1), "--", "LineWidth", lin_width_reduced)
xlabel('Time [s]', 'FontSize', font_size_reduced)
ylabel('Position [m]', 'FontSize', font_size_reduced)
title("Plot for roll", 'FontSize', font_size_reduced)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size_reduced-4, 'Location', 'northeast')
if(save_files_reduced)
    exportgraphics(position_fig_reduced, append(final_directory_reduced, "\LQR_X_position_gain", file_type_reduced))
end
%% plot for pitch with reduced state - space
simout_reduced=sim("DroneModelV2.slx", "StopTime", "20");
states_out_reduced=out.roll_r
refs_out_reduced = out.refs_r
position_fig_reduced=figure;

plot(states_out_reduced.Time, states_out_reduced.Data(:, 1), ...
     refs_out_reduced.Time, refs_out_reduced.Data(:, 1), "--", "LineWidth", lin_width_reduced)
xlabel('Time [s]', 'FontSize', font_size_reduced)
ylabel('Position [m]', 'FontSize', font_size_reduced)
title("Plot for roll", 'FontSize', font_size_reduced)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size_reduced-4, 'Location', 'northeast')
if(save_files_reduced)
    exportgraphics(position_fig_reduced, append(final_directory_reduced, "\LQR_X_position_gain", file_type_reduced))
end
%% plot for yaw with reduced state - space
simout_reduced=sim("DroneModelV2.slx", "StopTime", "20");
states_out_reduced=out.yaw_r
refs_out_reduced = out.refs_r
position_fig_reduced=figure;

plot(states_out_reduced.Time, states_out_reduced.Data(:, 1), ...
     refs_out_reduced.Time, refs_out_reduced.Data(:, 1), "--", "LineWidth", lin_width_reduced)
xlabel('Time [s]', 'FontSize', font_size_reduced)
ylabel('Position [m]', 'FontSize', font_size_reduced)
title("Plot for yaw", 'FontSize', font_size_reduced)
grid on;
%Xlim
ylim padded;
legend({'Position', 'Reference'}, 'FontSize', font_size_reduced-4, 'Location', 'northeast')
if(save_files_reduced)
    exportgraphics(position_fig_reduced, append(final_directory_reduced, "\LQR_X_position_gain", file_type_reduced))
end
