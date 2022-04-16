#include "rgb_3x3.h"
#include "rgblight_list.h"

void matrix_init_kb(void) {
	 //rgblight_enable();
	 //rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
	 //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
	 //rgblight_sethsv(HSV_MAGENTA); 
	 
	// rgblight_mode(RGBLIGHT_MODE_BREATHING);
    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);
	rgb_matrix_enable();
	rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);

	matrix_init_user();
};

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
      { 0,  1,  2 },\
      { 3,  4,  5 },\
      { 6,  7,  8 },\
  },
  {
    // LED Index to Physical Position
          /*    0    */ /*    1    */ /*    2    */ 
/*  0 */ {   0,   0 }, {  112,   0 }, { 224,   0 },\
/*  1 */ {   0,  32 }, {  112,  32 }, { 224,  32 },\
/*  2 */ {   0,  64 }, {  112,  64 }, { 224,  64 }\
  },
  {
    // LED Index to Flag
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, 
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,     
  }
};

