package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/ptc_v2_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your PTC Bricklet 2.0.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	ptc, _ := ptc_v2_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	ptc.RegisterTemperatureCallback(func(temperature int32) {
		fmt.Printf("Temperature: %f °C\n", float64(temperature)/100.0)
	})

	// Configure threshold for temperature "greater than 30 °C"
	// with a debounce period of 1s (1000ms).
	ptc.SetTemperatureCallbackConfiguration(1000, false, '>', 30*100, 0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
