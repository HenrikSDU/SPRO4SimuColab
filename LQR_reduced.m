
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
simout_reduced=sim("DroneModel.slx", "StopTime", "20");
states_out_reduced=out.z_r
refs_out_reduced = out.ref_z
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
simout_reduced=sim("DroneModel.slx", "StopTime", "20");
states_out_reduced=out.roll_r
refs_out_reduced = out.ref_r
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
simout_reduced=sim("DroneModel.slx", "StopTime", "20");
states_out_reduced=out.picth_r
refs_out_reduced = out.ref_p
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
simout_reduced=sim("DroneModel.slx", "StopTime", "20");
states_out_reduced=out.yaw_r
refs_out_reduced = out.ref_y
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
