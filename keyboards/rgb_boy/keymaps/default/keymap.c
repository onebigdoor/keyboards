#include QMK_KEYBOARD_H
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    RGB_TOG, RGB_MOD, \
    KC_3, KC_4  \
  )
};

