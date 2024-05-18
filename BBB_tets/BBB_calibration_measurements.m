% Prompt the user to input data points
data_accel1 = [0.1744, 0.2603, 0.2794, 0.2054, 0.203, 0.215, 0.2436, 0.2078, 0.2006, 0.1911, 0.2627, 0.2815, 0.2269, 0.2221, 0.2245, 0.2887, 0.2388, 0.203, 0.2293, 0.2436, 0.215, 0.1887, 0.1317, 0.1508, 0.2436, 0.2245, 0.203, 0.2317, 0.2245, 0.2412, 0.2293, 0.2078, 0.2579, 0.2317, 0.2341, 0.2579, 0.203, 0.2054, 0.2818, 0.2556, 0.2221, 0.215, 0.2958, 0.2197, 0.2388, 0.215, 0.1911, 0.2173, 0.2675, 0.2102, 0.2484]

% Calculate the mean
mean_value = mean(data_accel1);

% Calculate the squared differences from the mean
squared_diff = (data_accel1 - mean_value).^2;

% Calculate the variance
variance_accel1 = sum(squared_diff) / length(data_accel1);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_accel1)]);


data_Gyro = [-0.1831, -0.06104, -0.1221, 0, -0.18310, -0.06104, 0, -0.1221, 0, -0.1221, 0, 0, 0, 0, 0, -0.1221, -0.2441, -0.1221, 0, -0.1221, -0.1831, -0.3662, -0.1221, 0, -0.06104, -0.1831, 0, -0.06104, -0.06104, -0.2441, 0, -0.1221, 0, -0.3052, -0.1221, -0.1831, -0.2441, 0, 0, 0, -0.1831, -0.6104, -0.1221, -0.1221, -0.1221, -0.1831, -0.1221, 0.06104, 0, -0.1221]

% Calculate the mean
mean_value = mean(data_Gyro);

% Calculate the squared differences from the mean
squared_diff = (data_Gyro - mean_value).^2;

% Calculate the variance
variance_Gyro = sum(squared_diff) / length(data_Gyro);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_Gyro)]);


data_Mag1 = [4.802,6.236,3.606,3.367,3.845,5.041,3.845,4.802,5.280,5.280,4.802,6.475,4.323,4.802,3.128,6.714,6.475,2.889,4.802,5.519,2.650,4.323,3.845,4.563,3.606,4.802,4.323,5.758,5.519,3.363,4.802,5.563,2.411,5.997,3.606,6.475,5.280,5.997,5.997,4.323,5.519,4.323,6.236,5.997, 2.889,3.606,6.714,5.519,5.041,3.845,5.041]
% Calculate the mean
mean_value = mean(data_Mag1);
% Calculate the squared differences from the mean
squared_diff = (data_Mag1 - mean_value).^2;

% Calculate the variance
variance_Mag1 = sum(squared_diff) / length(data_Mag1);

% Display the result
disp(['The variance of the data points is: ' num2str(variance_Mag1)]);


data_Bar1 = [1.074e8, 1.070e8,1.069e8,1.070e8,1.072e8,1.075e8,1.076e8,1.071e8,1.069e8,1.074e8,1.072e8,1.074e8,1.068e8,1.071e8,1.076e8,1.078e8,1.0171e8,1.074e8,1.072e8,1.077e8,1.074e8,1.079e8,1.071e8,1.074e8,1.070e8,1.071e8,1.077e8,1.072e8,1.073e8,1.076e8,1.076e8,1.075e8,1.077e8,1.073e8,1.075e8,1.077e8,1.075e8,1.074e8,1.075e8,1.070e8,1.065e8,1.0704e8,1.068e8,1.069e8,]
mean_value = mean(data_Bar1);
squared_diff = (data_Bar1 - mean_value).^2;
variance_Bar1 = sum(squared_diff) / length(data_Bar1);
disp(['The variance of the data points is: ' num2str(variance_Bar1)]);