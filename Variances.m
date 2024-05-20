% Prompt the user to input data points
data_accel1 = [0.1744, 0.2603, 0.2794, 0.2054, 0.203, 0.215, 0.2436, 0.2078, 0.2006, 0.1911, 0.2627, 0.2815, 0.2269, 0.2221, 0.2245, 0.2887, 0.2388, 0.203, 0.2293, 0.2436, 0.215, 0.1887, 0.1317, 0.1508, 0.2436, 0.2245, 0.203, 0.2317, 0.2245, 0.2412, 0.2293, 0.2078, 0.2579, 0.2317, 0.2341, 0.2579, 0.203, 0.2054, 0.2818, 0.2556, 0.2221, 0.215, 0.2958, 0.2197, 0.2388, 0.215, 0.1911, 0.2173, 0.2675, 0.2102, 0.2484];

% Calculate the mean
mean_value = mean(data_accel1);

% Calculate the squared differences from the mean
squared_diff = (data_accel1 - mean_value).^2;

% Calculate the variance
variance_accel1 = sum(squared_diff) / length(data_accel1);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_accel1)]);


data_Gyro = [-0.1831, -0.06104, -0.1221, 0, -0.18310, -0.06104, 0, -0.1221, 0, -0.1221, 0, 0, 0, 0, 0, -0.1221, -0.2441, -0.1221, 0, -0.1221, -0.1831, -0.3662, -0.1221, 0, -0.06104, -0.1831, 0, -0.06104, -0.06104, -0.2441, 0, -0.1221, 0, -0.3052, -0.1221, -0.1831, -0.2441, 0, 0, 0, -0.1831, -0.6104, -0.1221, -0.1221, -0.1221, -0.1831, -0.1221, 0.06104, 0, -0.1221];

% Calculate the mean
mean_value = mean(data_Gyro);

% Calculate the squared differences from the mean
squared_diff = (data_Gyro - mean_value).^2;

% Calculate the variance
variance_Gyro = sum(squared_diff) / length(data_Gyro);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_Gyro)]);


data_Mag1 = [4.802,6.236,3.606,3.367,3.845,5.041,3.845,4.802,5.280,5.280,4.802,6.475,4.323,4.802,3.128,6.714,6.475,2.889,4.802,5.519,2.650,4.323,3.845,4.563,3.606,4.802,4.323,5.758,5.519,3.363,4.802,5.563,2.411,5.997,3.606,6.475,5.280,5.997,5.997,4.323,5.519,4.323,6.236,5.997, 2.889,3.606,6.714,5.519,5.041,3.845,5.041];
% Calculate the mean
mean_value = mean(data_Mag1);
% Calculate the squared differences from the mean
squared_diff = (data_Mag1 - mean_value).^2;

% Calculate the variance
variance_Mag1 = sum(squared_diff) / length(data_Mag1);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_Mag1)]);


data_Bar1 = [1.074e3+1e5, 1.070e3+1e5,1.069e3+1e5,1.070e3+1e5,1.072e3+1e5,1.075e3+1e5,1.076e3+1e5,1.071e3+1e5,1.069e3+1e5,1.074e3+1e5,1.072e3+1e5,1.074e3+1e5,1.068e3+1e5,1.071e3+1e5,1.076e3+1e5,1.078e3+1e5,1.0171e3+1e5,1.074e3+1e5,1.072e3+1e5,1.077e3+1e5,1.074e3+1e5,1.079e3+1e5,1.071e3+1e5,1.074e3+1e5,1.070e3+1e5,1.071e3+1e5,1.077e3+1e5,1.072e3+1e5,1.073e3+1e5,1.076e3+1e5,1.076e3+1e5,1.075e3+1e5,1.077e3+1e5,1.073e3+1e5,1.075e3+1e5,1.077e3+1e5,1.075e3+1e5,1.074e3+1e5,1.075e3+1e5,1.070e3+1e5,1.065e3+1e5,1.0704e3+1e5,1.068e3+1e5,1.069e3+1e5];
mean_value = mean(data_Bar1);
squared_diff = (data_Bar1 - mean_value).^2;
variance_Bar1 = sum(squared_diff) / length(data_Bar1);
disp(['The variance of the data points is: ' num2str(variance_Bar1)]);


data_rollAngle = [6.057e-2, 5.645e-2, 6.353e-2, 6.134e-2, 6.173e-2, 6.302e-2, 5.677e-2, 6.110e-2, 6.151e-2, 5.798e-2, 6.088e-2, 5.804e-2, 6.259e-2, 5.653e-2, 6.012e-2, 6.099e-2, 6.133e-2, 5.967e-2, 5.976e-2, 5.863e-2, 6.009e-2, 6.093e-2, 5.898e-2, 5.749e-2, 6.028e-2, 6.227e-2, 6.026e-2, 6.100e-2, 6.096e-2, 5.713e-2, 6.084e-2, 5.749e-2, 5.857e-2, 6.091e-2, 5.893e-2, 5.961e-2, 5.923e-2, 6.130e-2, 5.546e-2, 5.816e-2, 6.236e-2, 5.978e-2, 5.859e-2, 5.923e-2, 6.107e-2, 6.169e-2, 6.226e-2, 6.033e-2, 6.074e-2, 6.144e-2];
mean_value = mean(data_rollAngle);
squared_diff = (data_rollAngle - mean_value).^2;
variance_rollAngle = sum(squared_diff) / length(data_rollAngle);
disp(['The variannce oof the data points is: ' num2str(variance_rollAngle)]);


data_pitchAngle = [1.217e-2, 1.363e-2, 7.551e-3, 5.976e-3, 1.046e-2, 6.599e-3, 1.292e-2, 1.272e-2, 1.103e-2, 1.004e-2, 1.340e-2, 1.201e-2, 1.283e-2, 7.281e-3, 7.793e-3, 1.074e-2, 9.535e-3, 6.142e-3, 1.361e-2, 1.198e-2, 1.022e-2, 1.384e-2, 8.256e-3, 9.017e-3, 1.790e-2, 9.567e-3, 1.191e-2, 1.240e-2, 1.191e-2, 5.351e-3, 1.329e-2, 1.145e-2, 9.767e-3, 8.288e-3, 1.101e-2, 8.555e-3, 1.044e-2, 1.022e-2, 9.167e-3, 7.032e-3, 1.101e-2, 1.099e-2, 6.350e-3, 9.796e-3, 1.175e-2, 1.293e-2, 1.290e-2, 1.042e-2, 1.143e-2, 8.320e-3];
mean_value = mean(data_pitchAngle);
squared_diff = (data_pitchAngle - mean_value).^2;
variance_pitchAngle = sum(squared_diff) / length(data_pitchAngle);
disp(['The variannce oof the data points is: ' num2str(variance_pitchAngle)]);

% figure;
% histogram(data_pitchAngle)
% figure;
% histogram(data_rollAngle)
% figure;
% histogram(data_Gyro)


% Define the noise variances for each sensor
sigma_gyro = variance_Gyro;  % Gyro sensor noise variance
sigma_baro = variance_Bar1;  % Barometer sensor noise variance
sigma_mag = variance_Mag1;   % Magnometer noise variance
sigma_acc1 = variance_rollAngle;  % Accel1 sensor noise variance
sigma_acc2 = variance_pitchAngle;  % Accel2 sensor noise variance
sigma_acc3 = 0;  % Accel3 sensor noise variance

% Construct the R matrix
%R = diag([1, variace_rollAngle, variace_pitchAngle, 1, variace_Bar1, variance_Mag1,);

% Display the R matrix
disp(R);