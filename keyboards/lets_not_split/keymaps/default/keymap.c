#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(\
  BL_TOGG,       KC_Q,         KC_W,           KC_E,           KC_R,               KC_T,                   \
  KC_TAB,       LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D),     LGUI_T(KC_F),       KC_G,                 \
  KC_LSFT,      KC_Z,         KC_X,           KC_C,           KC_V,               KC_B,                  \
  KC_MPLY,      KC_LCTL,      KC_LALT,        KC_LGUI,        LT(LOWER,KC_ESC),   KC_SPC    \
),

[_LOWER] = LAYOUT( \
  KC_TILD,      KC_EXLM,      KC_AT,        KC_HASH,        KC_DLR,       KC_PERC,     \
  _______,      G(KC_GRV),    _______,        C(S(KC_TAB)), C(KC_TAB),    _______,     \
  _______,      KC_GRV,       KC_TILD,      C(KC_LEFT),     C(KC_RGHT),   _______,     \
  BL_INC,       BL_DEC,       BL_TOGG,        _______,      _______,      KC_MPLY     \
),

[_RAISE] = LAYOUT( \
  KC_GRV,       KC_1,         KC_2,           KC_3,         KC_4,         KC_5,              \
  _______,      _______,      _______,        _______,      _______,      _______,            \
  G(KC_Z),      G(KC_X),      G(KC_C),        A(G(KC_BSLS)),_______,      _______,      \
  _______,      _______,      _______,        _______,      _______,      KC_BSPC       \
),



};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LOWER, KC_ESC):
            return false;
        case RAISE:
            return false;
        default:
            return true;
    }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_D):
            return 150;
        case RSFT_T(KC_K):
            return 150;
        case LGUI_T(KC_F):
            return 150;
        case LGUI_T(KC_J):
            return 150;
        default:
            return TAPPING_TERM;
    }
}
