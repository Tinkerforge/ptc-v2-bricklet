<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletPTCV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletPTCV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your PTC Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$ptc = new BrickletPTCV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current temperature
$temperature = $ptc->getTemperature();
echo "Temperature: " . $temperature/100.0 . " °C\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
