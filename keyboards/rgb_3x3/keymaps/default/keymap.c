#include QMK_KEYBOARD_H
#include "matrix.h"
// Tap Dance declarations
enum {
    TD_LAYER,
};

enum {
	_DEFAULT,
	_RGB
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LAYER] = ACTION_TAP_DANCE_LAYER_MOVE(KC_7, _RGB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    TD(TD_LAYER), KC_8, KC_9,\
    KC_4, KC_5, KC_6,  \
    KC_1, KC_2, KC_3 \
  ),
  [1] = LAYOUT(
    KC_7, TO(_DEFAULT), RESET,\
    RGB_TOG, KC_5, KC_6,  \
    RGB_MOD, KC_2, KC_3 \
  ),
};

