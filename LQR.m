
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


