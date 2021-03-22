/* Copyright 2021 Don Kjer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_GRV_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Grave, twice for Escape
    [TD_GRV_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │`Es│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │End│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │Escape│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgU│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│Alt │GUI │                        │Fn1│Fn2│Ctl│ ← │ ↓ │ → │
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */
  [0] = LAYOUT_65_ansi(
      TD(TD_GRV_ESC),KC_1,KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
      KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
      KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                       MO(1),    MO(2),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RIGHT
  ),
  /* Layer 1
   * ,-----------------------------------------------------------. 
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       | 
   * |-----------------------------------------------------------| 
   * |     |   |   |   |   |   |   |   |   |PScr|Ins|Home|End|Del| 
   * |-----------------------------------------------------------| 
   * |      |   |   |   |   |   |   |   |   |   |PgUp|PgDn|      |
   * |-----------------------------------------------------------| 
   * |        |   |   |   |   |   |   |   |   |   |   |          | 
   * |-----------------------------------------------------------| 
   * |    |Lock|    |                       |    |Fn1 |Fn2 |     | 
   * `-----------------------------------------------------------' 
   */
  [1] = LAYOUT_65_ansi(
      KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
      _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_INS,   KC_HOME,  KC_END,   KC_DEL,   _______,
      KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_PGUP,  KC_PGDN,            _______,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  _______,  _______,                                _______,                      _______,  MO(3),    _______,  _______,  _______,  _______
  ),
  /* Layer 2
   * ,----------------------------------------------------------.
   * |     |   |   |   |   |   |   |   |   |   |   |RGT|RGN|     |
   * |-----------------------------------------------------------|
   * |      |   |RG+|   |   |   |   |   |   |   |    |    |      |
   * |-----------------------------------------------------------|
   * |       |SP-|RG-|SP+|   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                       |    |Fn1 |Fn2 |     |
   * `-----------------------------------------------------------'
   */
  [2] = LAYOUT_65_ansi(
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_TOG,  RGB_MOD,  _______,  _______,
      _______,  _______,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGUP,  _______,  _______,  _______,
      _______,  RGB_SPD,  RGB_VAD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_END,   KC_PGDN,            KC_PGUP,  _______,
      _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  KC_PGDN,  _______,
      _______,  _______,  _______,                                _______,                      MO(3),    _______,  _______,  _______,  _______,  _______
  ),
  /* Layer 3
   * ,-----------------------------------------------------------.
   * |RESET|   |   |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |    |    |      |
   * |-----------------------------------------------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                       |    |Fn1 |Fn2 |     |
   * `-----------------------------------------------------------'
   */
  [3] = LAYOUT_65_ansi(
      RESET,    RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  RGB_SAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_HUI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RESET:
            if (record->event.pressed) {
                // Flash LEDs to indicate bootloader mode is enabled.
                on_all_leds();
            }
            break;
    }
    return true;
}
