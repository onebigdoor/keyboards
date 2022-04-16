#include QMK_KEYBOARD_H
#include "matrix.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _ADJUST 1

#define ADJUST TO(_ADJUST)
#define DEFAULT TO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
     ADJUST,  ADJUST,  ADJUST,  ADJUST,  ADJUST,  RESET, \
     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,  \
     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,  \
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6   \
  ),

  [_ADJUST] =  LAYOUT( 
    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RESET  ,  \
    DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT,  \
    RGB_TOG, RGB_TOG, RGB_TOG, RGB_TOG, RGB_TOG, RGB_TOG,  \
    RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD, RGB_MOD   \
  )
};



