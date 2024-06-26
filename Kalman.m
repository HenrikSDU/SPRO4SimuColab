% Prompt the user to input data points
data_accel3 = [0.1744, 0.2603, 0.2794, 0.2054, 0.203, 0.215, 0.2436, 0.2078, 0.2006, 0.1911, 0.2627, 0.2815, 0.2269, 0.2221, 0.2245, 0.2887, 0.2388, 0.203, 0.2293, 0.2436, 0.215, 0.1887, 0.1317, 0.1508, 0.2436, 0.2245, 0.203, 0.2317, 0.2245, 0.2412, 0.2293, 0.2078, 0.2579, 0.2317, 0.2341, 0.2579, 0.203, 0.2054, 0.2818, 0.2556, 0.2221, 0.215, 0.2958, 0.2197, 0.2388, 0.215, 0.1911, 0.2173, 0.2675, 0.2102, 0.2484];

% Calculate the mean
mean_value = mean(data_accel3);

% Calculate the squared differences from the mean
squared_diff = (data_accel3 - mean_value).^2;

% Calculate the variance
variance_accel3 = sum(squared_diff) / length(data_accel3);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_accel3)]);


data_GyroPitch = [-0.1831, -0.06104, -0.1221, 0, -0.18310, -0.06104, 0, -0.1221, 0, -0.1221, 0, 0, 0, 0, 0, -0.1221, -0.2441, -0.1221, 0, -0.1221, -0.1831, -0.3662, -0.1221, 0, -0.06104, -0.1831, 0, -0.06104, -0.06104, -0.2441, 0, -0.1221, 0, -0.3052, -0.1221, -0.1831, -0.2441, 0, 0, 0, -0.1831, -0.6104, -0.1221, -0.1221, -0.1221, -0.1831, -0.1221, 0.06104, 0, -0.1221];

% Calculate the mean
mean_value = mean(data_GyroPitch);

% Calculate the squared differences from the mean
squared_diff = (data_GyroPitch - mean_value).^2;

% Calculate the variance
variance_GyroPitch = sum(squared_diff) / length(data_GyroPitch);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_GyroPitch)]);


data_Mag1 = [4.802,6.236,3.606,3.367,3.845,5.041,3.845,4.802,5.280,5.280,4.802,6.475,4.323,4.802,3.128,6.714,6.475,2.889,4.802,5.519,2.650,4.323,3.845,4.563,3.606,4.802,4.323,5.758,5.519,3.363,4.802,5.563,2.411,5.997,3.606,6.475,5.280,5.997,5.997,4.323,5.519,4.323,6.236,5.997, 2.889,3.606,6.714,5.519,5.041,3.845,5.041];
% Calculate the mean
mean_value = mean(data_Mag1);
% Calculate the squared differences from the mean
squared_diff = (data_Mag1 - mean_value).^2;

% Calculate the variance
variance_Mag1 = sum(squared_diff) / length(data_Mag1);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_Mag1)]);


data_Height = [6.107e-1, -1.353e-1, -3.603e-1, 1.695e-1, 3.945e-1, -5.762e-1, 3.232e-1, 2.720e-2, -4.379e-2, -2.688e-1, 4.0059e-1, 2.525e-1, -1.148e-1, 4.059e-1, 2.720e-2, -1.148e-1, 4.176e-1, 2.525e-1, -1.861e-1, -3.239e-2, -1.031e-1, 1.216e-1, 3.466e-1, -3.284e-1, 4.176e-1, 1.929e-1, -3.239e-2, -1.031e-1, 2.639e-1, -1.031e-1, -3.239e-2, 4.886e-1, -1.031e-1, -4.818e-1, 3.892e-2, -1.031e-1, 4.886e-1, 7.139e-1, 1.929e-1, -4.818e-1, 9.386e-1, 4.176e-1, 9.386e-1, -3.239e-2, 2.639e-1, 4.771e-2,4.886e-1];
mean_value = mean(data_Height);
squared_diff = (data_Height - mean_value).^2;
variance_Height = sum(squared_diff) / length(data_Height);
disp(['The variance of the data points is: ' num2str(variance_Height)]);

data_rollAngle = [6.057e-2, 5.645e-2, 6.353e-2, 6.134e-2, 6.173e-2, 6.302e-2, 5.677e-2, 6.110e-2, 6.151e-2, 5.798e-2, 6.088e-2, 5.804e-2, 6.259e-2, 5.653e-2, 6.012e-2, 6.099e-2, 6.133e-2, 5.967e-2, 5.976e-2, 5.863e-2, 6.009e-2, 6.093e-2, 5.898e-2, 5.749e-2, 6.028e-2, 6.227e-2, 6.026e-2, 6.100e-2, 6.096e-2, 5.713e-2, 6.084e-2, 5.749e-2, 5.857e-2, 6.091e-2, 5.893e-2, 5.961e-2, 5.923e-2, 6.130e-2, 5.546e-2, 5.816e-2, 6.236e-2, 5.978e-2, 5.859e-2, 5.923e-2, 6.107e-2, 6.169e-2, 6.226e-2, 6.033e-2, 6.074e-2, 6.144e-2];
mean_value = mean(data_rollAngle);
squared_diff = (data_rollAngle - mean_value).^2;
variance_rollAngle = sum(squared_diff) / length(data_rollAngle);
disp(['The variance of the data points is: ' num2str(variance_rollAngle)]);


data_pitchAngle = [1.217e-2, 1.363e-2, 7.551e-3, 5.976e-3, 1.046e-2, 6.599e-3, 1.292e-2, 1.272e-2, 1.103e-2, 1.004e-2, 1.340e-2, 1.201e-2, 1.283e-2, 7.281e-3, 7.793e-3, 1.074e-2, 9.535e-3, 6.142e-3, 1.361e-2, 1.198e-2, 1.022e-2, 1.384e-2, 8.256e-3, 9.017e-3, 1.790e-2, 9.567e-3, 1.191e-2, 1.240e-2, 1.191e-2, 5.351e-3, 1.329e-2, 1.145e-2, 9.767e-3, 8.288e-3, 1.101e-2, 8.555e-3, 1.044e-2, 1.022e-2, 9.167e-3, 7.032e-3, 1.101e-2, 1.099e-2, 6.350e-3, 9.796e-3, 1.175e-2, 1.293e-2, 1.290e-2, 1.042e-2, 1.143e-2, 8.320e-3];
mean_value = mean(data_pitchAngle);
squared_diff = (data_pitchAngle - mean_value).^2;
variance_pitchAngle = sum(squared_diff) / length(data_pitchAngle);
disp(['The variance of the data points is: ' num2str(variance_pitchAngle)]);

data_YawAngle = [1.217e-2, 1.363e-2, 7.551e-3, 5.976e-3, 1.046e-2, 6.599e-3, 1.292e-2, 1.272e-2, 1.103e-2, 1.004e-2, 1.340e-2, 1.201e-2, 1.283e-2, 7.281e-3, 7.793e-3, 1.074e-2, 9.535e-3, 6.142e-3, 1.361e-2, 1.198e-2, 1.022e-2, 1.384e-2, 8.256e-3, 9.017e-3, 1.790e-2, 9.567e-3, 1.191e-2, 1.240e-2, 1.191e-2, 5.351e-3, 1.329e-2, 1.145e-2, 9.767e-3, 8.288e-3, 1.101e-2, 8.555e-3, 1.044e-2, 1.022e-2, 9.167e-3, 7.032e-3, 1.101e-2, 1.099e-2, 6.350e-3, 9.796e-3, 1.175e-2, 1.293e-2, 1.290e-2, 1.042e-2, 1.143e-2, 8.320e-3];
mean_value = mean(data_YawAngle);
squared_diff = (data_YawAngle - mean_value).^2;
variance_Yaw = sum(squared_diff) / length(data_YawAngle);
disp(['The variance of the data points is: ' num2str(variance_Yaw)]);

data_GyroRoll = [0, -6.104e-2, 6.104e-2, -6.104e-2, 0, -2.411e-1, -6.104e-2, 6.104e-2, -6.104e-2, 0, -6.104e-2, 0, -1.831e-1, 0, -6.104e-2, 0, 6.104e-2, 0, -6.104e-2, 0, 6.104e-2, -1.831e-1, -6.104e-2, 0, 6.104e-2, -6.104e-2, -1.831e-1, -6.104e-2, -6.104e-2, 0, -6.104e-2, -1.221e-1, -6.104e-2,1.221e-1,0];
mean_value = mean(data_GyroRoll);
squared_diff = (data_GyroRoll - mean_value).^2;
variance_GyroRoll = sum(squared_diff) / length(data_GyroRoll);
disp(['The variance of the data points is: ' num2str(variance_GyroRoll)]);

data_GyroYaw = [1.221e-1, 0, -1.221e-1, 0, -1.221e-1, 0, -1.221e-1, 6.104e-2, 0, 1.221e-1, 0, -1.221e-1, 0, -1.221e-1, 0, 0, 1.221e-1, 0, -1.221e-1, 0, 6.104e-2, -1.221e-1, -1.831e-1, 0, -1.831e-1, 0, 6.104e-2, 0, 6.104e-2, 0, 0, 0, 1.221e-1, 6.104e-2, 0, 3.052e-1, 1.831e-1,6.104e-2];
mean_value = mean(data_GyroYaw);
squared_diff = (data_GyroYaw - mean_value).^2;
variance_GyroYaw = sum(squared_diff) / length(data_GyroYaw);
disp(['The variance of the data points is: ' num2str(variance_GyroYaw)]);
%% Plotting
figure;
histogram(data_Height)
title('Histogram Height')
figure;
histogram(data_pitchAngle)
title('Histogram Pitch Angle')
%%
figure;
histogram(data_rollAngle)
title('Histogram Roll Angle')
%%
figure;
histogram(data_YawAngle)
title('Histogram Yaw Angle')
figure;
histogram(data_GyroRoll)
title('Histogram Roll Rate')
%%
figure;
histogram(data_GyroPitch)
title('Histogram Pitch Rate')
%%
histogram(data_GyroYaw)
title('Histogram Yaw Rate')
% Define the noise variances for each sensor
%sigma_gyro = variance_Gyro;  % Gyro sensor noise variance
%sigma_baro = variance_Bar1;  % Barometer sensor noise variance
%sigma_mag = variance_Mag1;   % Magnometer noise variance
%sigma_acc1 = variance_rollAngle;  % Accel1 sensor noise variance
%sigma_acc2 = variance_pitchAngle;  % Accel2 sensor noise variance
%sigma_acc3 = 0;  % Accel3 sensor noise variance
%%


%% 
% Construct the R matrix
%R = diag([1,sigma_acc1,sigma_acc2, 1,sigma_baro,sigma_mag]);
R_kalman = diag([variance_Height,variance_pitchAngle , variance_rollAngle, variance_Yaw, variance_GyroRoll, variance_GyroPitch, variance_GyroYaw]);
Q_kalman = diag([0,0,0,0,0.0000000001,0.0000000001,0.00000000001,0.00000000001]);
Q_kalman_d = diag([0,0,0,0,0.000000000001,0.00000000001,0.00000000001,0.00000000001]);
Q_kalman_d2 = diag([0,0,0,0,0.00000000001,0.0000000001,0.00000000001,0.00000000001]);
Q_kalman_3 = diag([0,0,0,0,0.0000001,0.0000001,0.00000001,0.0000001]);
Q_kalman_d_lqi = diag([0,0,0,0,0.00001,0.00001,0.00001,0.00001]);
% Display the R matrix
disp(R_kalman);
%disp(Q_kalman);
fprintf("done")
%% Actual variances
accel1_min = -1.243e+01;
accel1_max = 1.051e+01;
accel2_min = -9.247e+00;
accel2_max = 1.107e+01;

angr_1_min = -3.723e+00;
angr_1_max = 2.014e+00;
angr_2_min = -2.625e+00;
angr_2_max = 2.197e+00;

angr_3_min = -1.953e+00;
angr_3_max = 3.052e+00;

var_angr_1 = clc_var(angr_1_min, angr_1_max);
var_angr_2 = clc_var(angr_2_min, angr_2_max);
var_angr_3 = clc_var(angr_3_min, angr_3_max);

ang_r_min = -1.127e+00;
ang_r_max = 9.491e-01;
var_r = clc_var(ang_r_min,ang_r_max);

ang_p_min = -1.249e+00;
ang_p_max = 9.917e-01;
var_p = clc_var(ang_p_min,ang_p_max);

var_ya = clc_var(-pi,pi);


R_kalman_a = diag([0.001 var_p var_r 0.001 var_angr_1 var_angr_2 0.001]);

function var = clc_var(min,max)
    
    dif = abs(max - min);
    sig = dif / 3;
    var = sig^2;

end


%% Kalman Filter ref1

var_alt = 0.001;
var_rp = 0.000005;  
var_yaw = 0.0005;
var_rpy_rate = 0.0000025;
pn = 0.00000001; % process noise, some will be 0!
Q_k = diag([0.000001 0.000001 pn pn pn pn pn pn]); % 8 since we have 8 state variables
R_k = diag([var_alt var_rp var_rp var_yaw var_rpy_rate var_rpy_rate var_rpy_rate]); % 7 since we have 7 outputs


%% Kalman Filter v2
roll_pp = 1.783e00;
pitch_pp = 2.195;
yaw_pp = 6.280;
roll_dot_pp = 7.670e-02;
pitch_dot_pp = 1.108e-01;
yaw_dot_pp = 7.244e-02;
z_pp = 3.16800;

var_roll_pp = clc_varpp(pitch_pp) * 1.1; % Note pitch is here
var_pitch_pp = clc_varpp(pitch_pp) * 1.1;
var_yaw_pp = clc_varpp(yaw_pp) * 1.1;
var_roll_dot_pp = clc_varpp(roll_dot_pp);
var_pitch_dot_pp = clc_varpp(pitch_dot_pp);
var_yaw_dot_pp = clc_varpp(yaw_dot_pp);
var_z_pp = clc_varpp(z_pp);

R_kalman_pp = diag([var_z_pp var_roll_pp var_pitch_pp var_yaw_pp var_roll_dot_pp var_pitch_dot_pp var_yaw_dot_pp]);

function var = clc_varpp(pp)
    
    dif = pp;
    sig = dif / 6;
    var = sig^2;

end