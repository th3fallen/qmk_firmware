#include QMK_KEYBOARD_H

#define _______ KC_TRNS

enum custom_keycodes {
    TERMOPEN = SAFE_RANGE,
    OPENCOVERAGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TERMOPEN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_DOWN(X_ZKHK));
        } else {
            SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT)SS_UP(X_ZKHK));
        }
        break;
    case OPENCOVERAGE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_ZKHK) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_UP(X_ZKHK) SS_DELAY(300) "open ~/Sites/When-I-Work/wheniwork-js/reports/coverage/lcov-report/index.html" SS_TAP(X_ENTER));
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    LT(1, KC_ESC),   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MPRV,  KC_MPLY,  KC_MNXT,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    _______,  TERMOPEN,  OPENCOVERAGE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  KC_MUTE,  KC_VOLU,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  CG_TOGG,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}
