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
#define _ARROW 5
#define _ADJUST 16

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_TAB,  LCTL_T(KC_A),    LALT_T(KC_S),    LSFT_T(KC_D),    LGUI_T(KC_F),    KC_G,    KC_H,    LGUI_T(KC_J),    RSFT_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_ENT , \
   KC_MPLY, KC_LCTL, KC_LALT, KC_LGUI, LT(LOWER, KC_V),   LT(ARROW, KC_SPC),  LT(ARROW, KC_SPC),  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  G(KC_TAB),G(KC_GRV),G(KC_S),G(KC_D),G(KC_F), _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, G(KC_Z),G(KC_X),G(KC_C),A(G(KC_BSLS)), _______, _______, _______, _______, _______, G(KC_SLSH), _______, \
  _______, BL_INC, BL_DEC, BL_TOGG, _______, _______, _______, _______, _______,KC_VOLD, KC_VOLU, KC_MNXT \
),
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  G(KC_TAB),G(KC_GRV),G(KC_S),G(KC_D),G(KC_F), _______, _______,KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, G(KC_Z),G(KC_X),G(KC_C),A(G(KC_BSLS)), _______, _______, _______, _______,_______, G(KC_SLSH), _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT \
),
[_ARROW] =  LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(LOWER, KC_V):
            return false;
        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


