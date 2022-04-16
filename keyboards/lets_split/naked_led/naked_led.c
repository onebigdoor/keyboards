#include "lets_split.h"
#include "drivers/led/issi/is31fl3731-simple.h"


// this might need to be LED_DRIVER_COUNT? i changed it to match doc example
const is31_led __flash g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  LED address
 *   |  | */
    {0, C3_1}, {0, C4_1}, {0, C5_1}, {0, C6_1}, {0, C7_1}, {0, C8_1},
    {0, C3_2}, {0, C4_2}, {0, C5_2}, {0, C6_2}, {0, C7_2}, {0, C8_2},
    {0, C3_3}, {0, C3_4}, {0, C5_3}, {0, C6_3}, {0, C7_3}, {0, C8_3},
    {0, C4_3}, {0, C4_4}, {0, C5_4}, {0, C6_4}, {0, C7_4}, {0, C8_4},
};
// const is31_led g_is31_leds[LED_DRIVER_LED_COUNT] = {
// /* Refer to IS31 manual for these locations
//  *   driver
//  *   |  LED address
//  *   |  | */
//     {0, C3_1}, {0, C4_1}, {0, C5_1}, {0, C6_1}, {0, C7_1}, {0, C8_1},
//     {0, C3_2}, {0, C4_2}, {0, C5_2}, {0, C6_2}, {0, C7_2}, {0, C8_2},
//     {0, C3_3}, {0, C3_4}, {0, C5_3}, {0, C6_3}, {0, C7_3}, {0, C8_3},
//     {0, C4_3}, {0, C4_4}, {0, C5_4}, {0, C6_4}, {0, C7_4}, {0, C8_4},
//     {1, C3_1}, {1, C4_1}, {1, C5_1}, {1, C6_1}, {1, C7_1}, {1, C8_1},
//     {1, C3_2}, {1, C4_2}, {1, C5_2}, {1, C6_2}, {1, C7_2}, {1, C8_2},
//     {1, C3_3}, {1, C3_4}, {1, C5_3}, {1, C6_3}, {1, C7_3}, {1, C8_3},
//     {1, C4_4}, {1, C4_4}, {1, C5_4}, {1, C6_4}, {1, C7_4}, {0, C8_4},
// };

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
      { 0,  1,  2,  3,  4,  5, },\
      { 6,  7,  8,  9, 10, 11, },\
      {12, 13, 14, 15, 16, 17, },\
      {18, 19, 20, 21, 22, 23, }\
  },
  {
    // LED Index to Physical Position
          /*    0    */ /*    1    */ /*    2    */ 
/*  0 */ {   0,   0 }, {   45,   0 }, { 90,   0 }, { 135,   0 }, { 180,   0 }, { 224,   0 },\
/*  1 */ {   0,  21 }, {   45,  21 }, { 90,  21 }, { 135,  21 }, { 180,  21 }, { 224,  21 },\
/*  2 */ {   0,  42 }, {   45,  42 }, { 90,  42 }, { 135,  42 }, { 180,  42 }, { 224,  42 },\
/*  3 */ {   0,  64 }, {   45,  64 }, { 90,  64 }, { 135,  64 }, { 180,  64 }, { 224,  64 }\
  },
  {
    // LED Index to Flag
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,    
  }
};


void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);
	matrix_init_user();
    led_matrix_mode(2); // breathing
    led_matrix_enable();
    //backlight_level(3);
};

