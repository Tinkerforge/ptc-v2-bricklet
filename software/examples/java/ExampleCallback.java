import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletPTCV2;

public class ExampleCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your PTC Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletPTCV2 ptc = new BrickletPTCV2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add temperature listener
		ptc.addTemperatureListener(new BrickletPTCV2.TemperatureListener() {
			public void temperature(int temperature) {
				System.out.println("Temperature: " + temperature/100.0 + " °C");
			}
		});

		// Set period for temperature callback to 1s (1000ms) without a threshold
		ptc.setTemperatureCallbackConfiguration(1000, false, 'x', 0, 0);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
