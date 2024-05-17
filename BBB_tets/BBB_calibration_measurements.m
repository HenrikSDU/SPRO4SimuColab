%simout_bbb=sim("C:\Users\Dario\Desktop\semester 4\Project\matlab & simulink\Drone simulink\SPRO4SimuColab\BBB_tets\BBB_calibration.slx", "StopTime", "10");
bbblue = beagleboneblue;
%stop the model from running on BBB
%stopModel(bbblue,'BBB_calibration')

%check if model is running, 1 if it is, 0 if it is not
%isModelRunning(bbblue,'BBB_calibration')

%see contents of a log file
system(bbblue,'cat BBB_calibration.log')

%getFiule saves a file to a current matlab directory
%getFile(bbblue,'BBB_calibration.log')

% Load the saved Simulink data
load('BBB_calibration.slx'); % Replace 'simulink_data.mat' with the actual filename

% Access the Scope data
time = ScopeData1.time;
output = ScopeData1.signals.values;

% Print out each data point
fprintf('Time \t Output\n');
for i = 1:length(time)
    fprintf('%.4f \t %.4f\n', time(i), output(i));
end