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
