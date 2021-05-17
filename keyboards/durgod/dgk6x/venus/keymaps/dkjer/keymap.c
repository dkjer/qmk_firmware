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

uint16_t typing_mode;
enum {
    TIME_RESET = SAFE_RANGE,
    TIME_EEPRST,
    KC_NOMODE,
    KC_WIDE,
    KC_SCRIPT,
    KC_BLOCKS,
    KC_REGIONAL,
    KC_AUSSIE,
    KC_ZALGO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │`Es│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │Escape│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  ↑Shift  │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │Ctrl│Alt │GUI │         Space          │Ctrl│←Fn1│↓Fn2│→Ctl│
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [0] = LAYOUT_60_ansi(
      TD(TD_GRV_ESC),KC_1,KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
      KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            RSFT_T(KC_UP),
      KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RCTL,LT(1,KC_LEFT),LT(2,KC_DOWN),RCTL_T(KC_RIGHT)
  ),
  /* Layer 1
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │ ` │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │ ↑ │   │   │   │   │   │ ↑ │PSc│Ins│Hom│End│ Del │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │ Caps │ ← │ ↓ │ → │   │   │   │ ← │ ↓ │ → │PgU│PgD│        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │ Mouse↑ │Bt2│Bt1│   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │Ms← │Ms↓ │Ms→ │                        │    │ Fn1│ Fn2│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [1] = LAYOUT_60_ansi(
      KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
      _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_PSCR,  KC_INS,   KC_HOME,  KC_END,   KC_DEL,
      KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGUP,  KC_PGDN,            _______,
      KC_MS_U,            KC_BTN2,  KC_BTN1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
      KC_MS_L,  KC_MS_D,  KC_MS_R,                                _______,                                _______,  _______,  MO(3),    _______
  ),
  /* Layer 2
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │Ply│Stp│Prv│Nxt│Mut│Vo-│Vo+│   │   │   │TOG│MD+│RGB MD-│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │VAI│   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │SPD│VAD│SPI│   │   │   │   │   │ ↑ │   │   │  PgUp  │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │MWheel↓ │Bt3│   │   │   │   │   │   │ ← │ ↓ │ → │    PgDn  │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │MWh→│MWh↑│MWh←│                        │    │HmF1│ Fn2│ End│
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [2] = LAYOUT_60_ansi(
      _______,  KC_MPLY,  KC_MSTP,  KC_MPRV,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  RGB_TOG,  RGB_MOD,  RGB_RMOD,
      _______,  _______,  RGB_VAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
      _______,  RGB_SPD,  RGB_VAD,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  _______,            KC_PGUP,
      KC_WH_D,            KC_BTN3,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,           KC_PGDN,
      KC_WH_R,  KC_WH_U,  KC_WH_L,                                _______,                                _______,  LT(3,KC_HOME),_______,KC_END
  ),
  /* Layer 3
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │MSt│MBr│MGr│MPw│   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │SAI│   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │HUD│SAD│HUI│   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │ Fn3│ Fn1│ Fn2│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [3] = LAYOUT_60_ansi(
      XXXXXXX,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  RGB_SAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  RGB_HUD,  RGB_SAD,  RGB_HUI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                MO(4),    _______,  _______,  XXXXXXX
  ),
  /* Layer 4
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │RST│NOM│WID│SCR│BLK│REG│AUS│   │   │   │   │   │   │EEPMRST│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │F15│   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │F14│DBG│   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │ Fn3│ Fn1│ Fn2│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [4] = LAYOUT_60_ansi(
      TIME_RESET,KC_NOMODE,KC_WIDE, KC_SCRIPT,KC_BLOCKS,KC_REGIONAL,KC_AUSSIE,KC_ZALGO,XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TIME_EEPRST,
      XXXXXXX,  XXXXXXX,  KC_F15,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  KC_F14,   DEBUG,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                _______,  _______,  _______,  XXXXXXX
  ),
  [5] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [6] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [7] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [8] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [9] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [10] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
  [11] = LAYOUT_60_ansi(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
      XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  )
};

#define NAV_R 255
#define NAV_G 217
#define NAV_B 0

#define MEDIA_R 0
#define MEDIA_G 255
#define MEDIA_B 38

#define MEDIA_ALT_R 128
#define MEDIA_ALT_G 255
#define MEDIA_ALT_B 146

#define RGB_R 0
#define RGB_G 38
#define RGB_B 255

#define RGB_ALT_R 128
#define RGB_ALT_G 146
#define RGB_ALT_B 255

#define SPECIAL_R 255
#define SPECIAL_G 0
#define SPECIAL_B 38

#define MOUSE_R 217
#define MOUSE_G 0
#define MOUSE_B 255

#define MOUSE_ALT_R 236
#define MOUSE_ALT_G 128
#define MOUSE_ALT_B 255

#define ACTIVE_R 255
#define ACTIVE_G 255
#define ACTIVE_B 255

void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color(28, ACTIVE_R, ACTIVE_G, ACTIVE_B);
    }
    if (IS_LAYER_ON(4)) {
        rgb_matrix_set_color(16, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(30, MEDIA_R, MEDIA_G, MEDIA_B);
        // Debug 'D'
        if (debug_enable) {
            rgb_matrix_set_color(31, ACTIVE_R, ACTIVE_G, ACTIVE_B);
        }
        else {
            rgb_matrix_set_color(31, SPECIAL_R, SPECIAL_G, SPECIAL_B);
        }
        for (uint16_t kc = KC_NOMODE; kc <= KC_ZALGO; ++kc) {
            if (kc == typing_mode) {
                rgb_matrix_set_color(kc - KC_NOMODE + 1, ACTIVE_R, ACTIVE_G, ACTIVE_B);
            }
            else {
                rgb_matrix_set_color(kc - KC_NOMODE + 1, MOUSE_R, MOUSE_G, MOUSE_B);
            }
        }

        rgb_matrix_set_color(0, SPECIAL_R, SPECIAL_G, SPECIAL_B);
        rgb_matrix_set_color(13, SPECIAL_R, SPECIAL_G, SPECIAL_B);
    }
    else if (IS_LAYER_ON(3)) {
        // RGB Keys
        rgb_matrix_set_color(1, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);
        rgb_matrix_set_color(2, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);
        rgb_matrix_set_color(3, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);
        rgb_matrix_set_color(4, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);

        rgb_matrix_set_color(16, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(29, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(30, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(31, RGB_R, RGB_G, RGB_B);
    }
    else if (IS_LAYER_ON(2)) {
        // Media keys
        rgb_matrix_set_color(1, MEDIA_ALT_R, MEDIA_ALT_G, MEDIA_ALT_B);
        rgb_matrix_set_color(2, MEDIA_ALT_R, MEDIA_ALT_G, MEDIA_ALT_B);
        rgb_matrix_set_color(3, MEDIA_ALT_R, MEDIA_ALT_G, MEDIA_ALT_B);
        rgb_matrix_set_color(4, MEDIA_ALT_R, MEDIA_ALT_G, MEDIA_ALT_B);
        rgb_matrix_set_color(5, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(6, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(7, MEDIA_R, MEDIA_G, MEDIA_B);

        // L,./ Arrow keys
        rgb_matrix_set_color(37, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(49, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(50, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(51, NAV_R, NAV_G, NAV_B);

        // RGB Keys
        rgb_matrix_set_color(11, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);
        rgb_matrix_set_color(12, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);
        rgb_matrix_set_color(13, RGB_ALT_R, RGB_ALT_G, RGB_ALT_B);

        rgb_matrix_set_color(16, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(29, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(30, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(31, RGB_R, RGB_G, RGB_B);

        // Mouse Keys
        rgb_matrix_set_color(41, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(42, MOUSE_ALT_R, MOUSE_ALT_G, MOUSE_ALT_B);
        rgb_matrix_set_color(53, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(54, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(55, MOUSE_R, MOUSE_G, MOUSE_B);
    }
    else if (IS_LAYER_ON(1)) {
        // WASD
        rgb_matrix_set_color(16, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(29, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(30, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(31, NAV_R, NAV_G, NAV_B);

        // IJKL Arrow keys
        rgb_matrix_set_color(22, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(35, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(36, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(37, NAV_R, NAV_G, NAV_B);

        // Mouse Keys
        rgb_matrix_set_color(41, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(42, MOUSE_ALT_R, MOUSE_ALT_G, MOUSE_ALT_B);
        rgb_matrix_set_color(43, MOUSE_ALT_R, MOUSE_ALT_G, MOUSE_ALT_B);
        rgb_matrix_set_color(53, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(54, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(55, MOUSE_R, MOUSE_G, MOUSE_B);
    }
}

void keyboard_post_init_user(void) {
    typing_mode    = KC_NOMODE;
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_MAC);
#endif
}

void tap_code16_nomods(uint8_t kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_code16(kc);
    set_mods(temp_mod);
}

void tap_unicode_glyph(uint32_t glyph) {
#ifdef UNICODE_ENABLE
    unicode_input_start();
    if (glyph < 0x10000) {
        register_hex(glyph);
    }
    else {
        uint32_t t = glyph - 0x10000;
        register_hex(((t<<12)>>22) + 0xD800);
        register_hex(((t<<22)>>22) + 0xDC00);
    }
    unicode_input_finish();
#endif
}

void tap_unicode_glyph_nomods(uint32_t glyph) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    clear_oneshot_mods();
    tap_unicode_glyph(glyph);
    set_mods(temp_mod);
}

typedef uint32_t (*translator_function_t)(bool is_shifted, uint32_t keycode);

#define DEFINE_UNICODE_RANGE_TRANSLATOR(translator_name, lower_alpha, upper_alpha, zero_glyph, number_one, space_glyph) \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) {                                         \
        switch (keycode) {                                                                                              \
            case KC_A ... KC_Z:                                                                                         \
                return (is_shifted ? upper_alpha : lower_alpha) + keycode - KC_A;                                       \
            case KC_0:                                                                                                  \
                return zero_glyph;                                                                                      \
            case KC_1 ... KC_9:                                                                                         \
                return (number_one + keycode - KC_1);                                                                   \
            case KC_SPACE:                                                                                              \
                return space_glyph;                                                                                     \
        }                                                                                                               \
        return keycode;                                                                                                 \
    }

#define DEFINE_UNICODE_LUT_TRANSLATOR(translator_name, ...)                     \
    static inline uint32_t translator_name(bool is_shifted, uint32_t keycode) { \
        static const uint32_t translation[] = {__VA_ARGS__};                    \
        uint32_t              ret           = keycode;                          \
        if ((keycode - KC_A) < (sizeof(translation) / sizeof(uint32_t))) {      \
            ret = translation[keycode - KC_A];                                  \
        }                                                                       \
        return ret;                                                             \
    }

bool process_record_glyph_replacement(uint16_t keycode, keyrecord_t *record, translator_function_t translator) {
    uint8_t temp_mod   = get_mods();
    uint8_t temp_osm   = get_oneshot_mods();
    bool    is_shifted = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    if (((temp_mod | temp_osm) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) == 0) {
        if (KC_A <= keycode && keycode <= KC_Z) {
            if (record->event.pressed) {
                tap_unicode_glyph_nomods(translator(is_shifted, keycode));
            }
            return false;
        } else if (KC_1 <= keycode && keycode <= KC_0) {
            if (is_shifted) {  // skip shifted numbers, so that we can still use symbols etc.
                return true;
            }
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        } else if (keycode == KC_SPACE) {
            if (record->event.pressed) {
                tap_unicode_glyph(translator(is_shifted, keycode));
            }
            return false;
        }
    }
    return true;
}

DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_wide, 0xFF41, 0xFF21, 0xFF10, 0xFF11, 0x2003);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_script, 0x1D4EA, 0x1D4D0, 0x1D7CE, 0x1D7C1, 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_boxes, 0x1F170, 0x1F170, '0', '1', 0x2002);
DEFINE_UNICODE_RANGE_TRANSLATOR(unicode_range_translator_regional, 0x1F1E6, 0x1F1E6, '0', '1', 0x2003);

DEFINE_UNICODE_LUT_TRANSLATOR(unicode_lut_translator_aussie,
                              0x0250,  // a
                              'q',     // b
                              0x0254,  // c
                              'p',     // d
                              0x01DD,  // e
                              0x025F,  // f
                              0x0183,  // g
                              0x0265,  // h
                              0x1D09,  // i
                              0x027E,  // j
                              0x029E,  // k
                              'l',     // l
                              0x026F,  // m
                              'u',     // n
                              'o',     // o
                              'd',     // p
                              'b',     // q
                              0x0279,  // r
                              's',     // s
                              0x0287,  // t
                              'n',     // u
                              0x028C,  // v
                              0x028D,  // w
                              0x2717,  // x
                              0x028E,  // y
                              'z',     // z
                              0x0269,  // 1
                              0x3139,  // 2
                              0x0190,  // 3
                              0x3123,  // 4
                              0x03DB,  // 5
                              '9',     // 6
                              0x3125,  // 7
                              '8',     // 8
                              '6',     // 9
                              '0'      // 0
);

bool process_record_aussie(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            if (!process_record_glyph_replacement(keycode, record, unicode_lut_translator_aussie)) {
                tap_code16_nomods(KC_LEFT);
                return false;
            }
        }
    } else if (record->event.pressed && keycode == KC_SPACE) {
        tap_code16_nomods(KC_SPACE);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_ENTER) {
        tap_code16_nomods(KC_END);
        tap_code16_nomods(KC_ENTER);
        return false;
    } else if (record->event.pressed && keycode == KC_HOME) {
        tap_code16_nomods(KC_END);
        return false;
    } else if (record->event.pressed && keycode == KC_END) {
        tap_code16_nomods(KC_HOME);
        return false;
    } else if (record->event.pressed && keycode == KC_BSPC) {
        tap_code16_nomods(KC_DELT);
        return false;
    } else if (record->event.pressed && keycode == KC_DELT) {
        tap_code16_nomods(KC_BSPC);
        return false;
    } else if (record->event.pressed && keycode == KC_QUOT) {
        tap_unicode_glyph_nomods(is_shifted ? 0x201E : 0x201A);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_COMMA) {
        tap_unicode_glyph_nomods(is_shifted ? '<' : 0x2018);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_DOT) {
        tap_unicode_glyph_nomods(is_shifted ? '>' : 0x02D9);
        tap_code16_nomods(KC_LEFT);
        return false;
    } else if (record->event.pressed && keycode == KC_SLASH) {
        tap_unicode_glyph_nomods(is_shifted ? 0x00BF : '/');
        tap_code16_nomods(KC_LEFT);
        return false;
    }
    return true;
}

bool process_record_zalgo(uint16_t keycode, keyrecord_t *record) {
    if ((KC_A <= keycode) && (keycode <= KC_0)) {
        if (record->event.pressed) {
            tap_code16_nomods(keycode);

            int number = (rand() % (8 + 1 - 2)) + 2;
            for (int index = 0; index < number; index++) {
                uint16_t hex = (rand() % (0x036F + 1 - 0x0300)) + 0x0300;
                tap_unicode_glyph(hex);
            }

            return false;
        }
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t reset_key_timer  = 0;
    static uint32_t eeprst_key_timer = 0;

    switch (keycode) {
        case RESET:
            if (record->event.pressed) {
                // Flash LEDs to indicate bootloader mode is enabled.
                on_all_leds();
            }
            break;

        case TIME_RESET:
            if (record->event.pressed) {
                reset_key_timer = timer_read32();
            } else {
                if (timer_elapsed32(reset_key_timer) >= 500) {
                    // Flash LEDs to indicate bootloader mode is enabled.
                    on_all_leds();
                    reset_keyboard();
                }
            }
            return false;

        case TIME_EEPRST:
            if (record->event.pressed) {
                eeprst_key_timer = timer_read32();
            } else {
                if (timer_elapsed32(eeprst_key_timer) >= 500) {
                    eeconfig_init();
                    // Flash LEDs to indicate eeprom was reset.
                    on_all_leds();
                    wait_ms(250);
                    off_all_leds();
                }
            }
            return false;

        case KC_NOMODE:
        case KC_WIDE:
        case KC_SCRIPT:
        case KC_BLOCKS:
        case KC_REGIONAL:
        case KC_AUSSIE:
        case KC_ZALGO:
            if (record->event.pressed) {
                if (typing_mode != keycode) {
                    typing_mode = keycode;
                    switch (typing_mode) {
                        case KC_NOMODE:
                            dprint("Disabling unicode mode\n");
                            break;
                        case KC_WIDE:
                            dprint("Enabling wide mode\n");
                            break;
                        case KC_SCRIPT:
                            dprint("Enabling calligraphy mode\n");
                            break;
                        case KC_BLOCKS:
                            dprint("Enabling blocks mode\n");
                            break;
                        case KC_REGIONAL:
                            dprint("Enabling regional mode\n");
                            break;
                        case KC_AUSSIE:
                            dprint("Enabling aussie mode\n");
                            break;
                        case KC_ZALGO:
                            dprint("Enabling zalgo mode\n");
                            break;
                    }
                }
            }
            return false;
    }

    if (((KC_A <= keycode) && (keycode <= KC_0)) || keycode == KC_SPACE) {
        switch (typing_mode) {
            case KC_WIDE:
                return process_record_glyph_replacement(keycode, record, unicode_range_translator_wide);
            case KC_SCRIPT:
                return process_record_glyph_replacement(keycode, record, unicode_range_translator_script);
            case KC_BLOCKS:
                return process_record_glyph_replacement(keycode, record, unicode_range_translator_boxes);
            case KC_REGIONAL:
                if (!process_record_glyph_replacement(keycode, record, unicode_range_translator_regional)) {
                    tap_unicode_glyph_nomods(0x200C);
                    return false;
                }
                break;
        }
    }

    switch (typing_mode) {
        case KC_AUSSIE:
            return process_record_aussie(keycode, record);
        case KC_ZALGO:
            return process_record_zalgo(keycode, record);
    }
    return true;
}
