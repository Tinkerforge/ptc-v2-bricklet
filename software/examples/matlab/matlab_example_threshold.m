function matlab_example_threshold()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletPTCV2;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your PTC Bricklet 2.0

    ipcon = IPConnection(); % Create IP connection
    ptc = handle(BrickletPTCV2(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register temperature callback to function cb_temperature
    set(ptc, 'TemperatureCallback', @(h, e) cb_temperature(e));

    % Configure threshold for temperature "greater than 30 °C"
    % with a debounce period of 1s (1000ms)
    ptc.setTemperatureCallbackConfiguration(1000, false, '>', 30*100, 0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for temperature callback
function cb_temperature(e)
    fprintf('Temperature: %g °C\n', e.temperature/100.0);
end
