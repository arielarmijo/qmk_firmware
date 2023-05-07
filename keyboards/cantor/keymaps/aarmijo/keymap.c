#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION
};

enum custom_keycodes {
  RUT  = SAFE_RANGE,
  EMAIL,
  ARROW_FN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FUNCTION MO(_FUNCTION)
#define DEL_FUNCTION LT(_FUNCTION, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
            QK_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, LT(RAISE, KC_BSPC),
  LT(LOWER, KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    LSFT_T(KC_CAPS),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
                                               KC_LGUI,   LOWER,  LCTL_T(KC_SPC),    KC_SPC,   RAISE, KC_RALT
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
   FUNCTION, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_TRNS,  KC_GRV,
    KC_LSFT, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT,                             RALT(KC_N), KC_MUTE, KC_TRNS,ARROW_FN, KC_HOME, RSFT_T(KC_END),  
                                        KC_TRNS,FUNCTION, KC_TRNS,      RCTL_T(KC_TRNS),  ADJUST, KC_LALT
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
            KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  LT(FUNCTION, KC_DEL),
            KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_TRNS,                                 KC_TRNS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS,
    LSFT_T(KC_HOME), KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT,                                 KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_RSFT,
                                                KC_TRNS,  ADJUST, LCTL_T(KC_TRNS),      KC_TRNS, FUNCTION, KC_LALT
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   NK_ON,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  EE_CLR,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  NK_OFF,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  QK_RBT,
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FUNCTION] = LAYOUT_split_3x6_3(
       KC_PWR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,     RUT,                        KC_BRID,  KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,
      KC_TRNS,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   EMAIL,                        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MNXT,                        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
  )
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RUT:
      if (record->event.pressed) {
        SEND_STRING("13658100-7");
      }
      break;
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("arielarmijo@yahoo.es");
      }
      break;
    case ARROW_FN:
      if (record->event.pressed) {
        SEND_STRING("() => {}");
      }
      break;
  }
  return true;
}
