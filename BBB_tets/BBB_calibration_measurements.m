simout_bbb=sim("BBB_calibration.slx", "StopTime", "65");
out_bar = out.barometer
plot(out_bar.Time, out_bar.Data(:, 1))