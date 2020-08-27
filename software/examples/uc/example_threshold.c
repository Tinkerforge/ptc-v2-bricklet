#include "bindings/hal_common.h"
#include "bindings/bricklet_ptc_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your PTC Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


// Callback function for temperature callback
static void temperature_handler(TF_PTCV2 *device, int32_t temperature, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Temperature: %d 1/%d °C\n", temperature, 100.0);
}

static TF_PTCV2 ptc;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_ptc_v2_create(&ptc, UID, hal), "create device object");

	// Register temperature callback to function temperature_handler
	tf_ptc_v2_register_temperature_callback(&ptc,
	                                        temperature_handler,
	                                        NULL);

	// Configure threshold for temperature "greater than 30 °C"
	// with a debounce period of 1s (1000ms)
	tf_ptc_v2_set_temperature_callback_configuration(&ptc, 1000, false, '>', 30*100, 0);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
