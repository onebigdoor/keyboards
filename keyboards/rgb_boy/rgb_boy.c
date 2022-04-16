#include "rgb_boy.h"

void matrix_init_kb(void) {
	 rgblight_enable();
	 //rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
	 //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
	 rgblight_sethsv(HSV_MAGENTA); 
	// rgblight_mode(RGBLIGHT_MODE_BREATHING);
    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);

	matrix_init_user();
};

