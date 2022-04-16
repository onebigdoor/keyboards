#include "rgb_split.h"
//#include "rgblight_list.h"

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
    // rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
    rgb_matrix_mode(36);
    //rgb_matrix_mode(5);

    matrix_init_user();
};

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





