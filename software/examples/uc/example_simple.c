#include "bindings/hal_common.h"
#include "bindings/bricklet_ptc_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your PTC Bricklet 2.0

void check(int rc, const char* msg);

TF_PTCV2 ptc;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_ptc_v2_create(&ptc, UID, hal), "create device object");

	// Get current temperature
	int32_t temperature;
	check(tf_ptc_v2_get_temperature(&ptc, &temperature), "get temperature");

	tf_hal_printf("Temperature: %d 1/%d °C\n", temperature, 100.0);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
