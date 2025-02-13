// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_ptc_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_PTCV2 ptc;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_ptc_v2_create(&ptc, NULL, hal), "create device object");

	// Get current temperature
	int32_t temperature;
	check(tf_ptc_v2_get_temperature(&ptc, &temperature), "get temperature");

	tf_hal_printf("Temperature: %d 1/%d °C\n", temperature, 100);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
