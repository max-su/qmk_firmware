#include QMK_KEYBOARD_H
#include "version.h"

#define BASE_LINUX 0 // Default layer (Mac OSX)
#define BASE_WINDOWS 1 // Default layer (Windows)
#define SYMB 2  // Symbols
#define ARRW 3  // HJKL => Arrow keys, fn keys
#define NUMB 4  // Numbers
#define MEDIA 5 // Media keys
#define RGBLIGHT_COLOR_LAYER_0 203, 46, 100 // Pink
#define RGBLIGHT_COLOR_LAYER_1 203, 46, 100 // Pink
#define RGBLIGHT_COLOR_LAYER_2 0xe7, 0xcc, 0xf1 // Eggshell White
#define RGBLIGHT_COLOR_LAYER_3 0xdc, 0x14, 0x3c // Deeper Pink
#define RGBLIGHT_COLOR_LAYER_4 0x76, 0xD7, 0xD6 // Cyan


enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | Swap |           | Prtsc|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|    '   |
 * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   -  |   +  | Ctrl | Alt  | LGUI |                                       | LGUI |  Alt | Ctrl |      |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Back | Fwd  |       | VolDn| VolUp |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Play |       | Mute |        |      |
 *                                 | Space|Backsp|------|       |------|  LGUI  |Enter |
 *                                 |      |ace   |  L3  |       | Ctrl |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE_LINUX] = LAYOUT_ergodox(
  // Left Hand.
  KC_ESC,  KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    TG(ARRW),
  KC_TAB,  KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    MO(ARRW),
  KC_CAPS, KC_A,        KC_S,          KC_D,    LT(ARRW, KC_F),   KC_G,
  KC_LSFT, KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB),
  KC_MINS, KC_PLUS,     KC_LCTRL,      KC_LALT,  KC_LGUI,
                                                                KC_MPRV,  KC_MNXT,
                                                                          KC_MPLY,
                                                         KC_SPC, KC_BSPC, MO(NUMB),
  // Right Hand.
  KC_PSCR,  KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  MO(ARRW), KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_H,     KC_J,    KC_K,    KC_L,    LT(ARRW, KC_SCLN), KC_QUOT,
  MO(SYMB), KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH, KC_RSFT,
  KC_RCTRL,  KC_DOWN, KC_UP, DF(BASE_WINDOWS), DF(BASE_LINUX),
  KC_VOLD, KC_VOLU,
  KC_MUTE,
  KC_LCTRL, KC_LGUI, KC_ENT
),

// Basically the same thing but CAPS/ESC are flipped
[BASE_WINDOWS] = LAYOUT_ergodox(
  KC_CAPS, KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    TG(ARRW),
  KC_TAB,  KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    MO(ARRW),
  KC_ESC,  KC_A,        KC_S,          KC_D,    LT(ARRW, KC_F),    KC_G,
  KC_LSFT, KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB),
  KC_MINS, KC_PLUS,     KC_LCTRL,      KC_LALT,  KC_LGUI,
                                                                KC_MPRV,  KC_MNXT,
                                                                          KC_MPLY,
                                                         KC_SPC, KC_BSPC, MO(NUMB),
  // Right Hand.
  KC_PSCR,  KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  MO(ARRW),  KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_H,     KC_J,    KC_K,    KC_L,    LT(ARRW, KC_SCLN), KC_QUOT,
  MO(SYMB), KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH, KC_RSFT,
  KC_TRNS,  KC_TRNS, KC_TRNS, DF(BASE_WINDOWS), DF(BASE_LINUX),
  KC_VOLD, KC_VOLU,
  KC_MUTE,
  KC_LCTRL, KC_LGUI, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  %   |  @   |  ~   |      |      |           |      |      |   `  |   ?  |   $  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  [   |  {   |  (   |  :   |  +   |------|           |------|  *   |   =  |   )  |   }  |  ]   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  \   |  ^   |  &   |  #   |  !   |      |           |      |  0   |   /  |   -  |   _  |  |   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // Left Hand.
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_PERC, KC_AT,   KC_TILD, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LBRC, KC_LCBR, KC_LPRN, KC_COLN, KC_PLUS,
  KC_TRNS, KC_BSLS, KC_CIRC, KC_AMPR, KC_HASH, KC_EXLM, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // Right Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_GRV,  KC_QUES, KC_DLR,  KC_TRNS, KC_TRNS,
  KC_ASTR, KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_TRNS,
  KC_TRNS, KC_0,    KC_SLSH, KC_MINS, KC_UNDS, KC_PIPE, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Arrow and Fn Keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  | F10  | F11  |  F12 |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRW] = LAYOUT_ergodox(
  // Left Hand.
  TG(ARRW), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // Right Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |  0   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox(
  // Left Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_POWER,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // Right Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_7,   KC_8,   KC_9,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_4,    KC_5,   KC_6,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_1,   KC_2,   KC_3,    KC_0,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MEDIA] = LAYOUT_ergodox(
  // Left Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_POWER,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // Right Hand.
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_7,   KC_8,   KC_9,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_4,    KC_5,   KC_6,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_1,   KC_2,   KC_3,    KC_0,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgblight_enable();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

/* [BASE_OSX] = LAYOUT_ergodox( */
/*   // Left Hand. */
/*   KC_CAPS, KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    DF(BASE_WINDOWS), */
/*   KC_TAB,  KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    MO(ARRW), */
/*   KC_ESC,  KC_A,        KC_S,          LT(NUMB, KC_D),    LT(ARRW, KC_F),    KC_G, */
/*   KC_LSFT, KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB), */
/*   KC_MINS, KC_PLUS,     KC_LCTRL,       KC_LALT,  KC_LGUI, */
/*                                                                 KC_MRWD,  KC_MFFD, */
/*                                                                           KC_MPLY, */
/*                                                          KC_SPC, KC_BSPC, MO(NUMB), */
/*   // Right Hand. */
/*   KC_LGUI,  KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS, */
/*   MO(ARRW),  KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS, */
/*   KC_H,     KC_J,    KC_K,    KC_L,    LT(ARRW, KC_SCLN), KC_QUOT, */
/*   MO(SYMB), KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH, KC_RSFT, */
/*   KC_LGUI,  KC_LALT, KC_LCTRL, KC_LEFT, KC_RGHT, */
/*   KC__VOLDOWN, KC__VOLUP, */
/*   KC__MUTE, */
/*   TG(ARRW), KC_TAB, KC_ENT */
/* ), */
