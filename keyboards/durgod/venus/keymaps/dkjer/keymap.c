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
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │`Es│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │Escape│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  ↑Shift  │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │Ctrl│Alt │GUI │       Space/Fn1        │Ctrl│←Fn1│↓Fn2│→Ctl│
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [0] = LAYOUT_60_ansi(
      TD(TD_GRV_ESC),KC_1,KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
      KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
      KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            RSFT_T(KC_UP),
      KC_LCTL,  KC_LALT,  KC_LGUI,                                LT(1, KC_SPC),                          KC_RCTL,LT(1,KC_LEFT),LT(2,KC_DOWN),RCTL_T(KC_RIGHT)
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
   * │RST│   │   │   │   │   │   │   │   │   │   │   │   │ DEBUG │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
   * │        │   │   │   │   │   │   │   │   │   │   │          │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
   * │    │    │    │                        │ Fn3│ Fn1│ Fn2│    │
   * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
   */
  [4] = LAYOUT_60_ansi(
      RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DEBUG,
      XXXXXXX,  XXXXXXX,  KC_F15,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      XXXXXXX,  XXXXXXX,  KC_F14,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
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
  )
};

#define NAV_R 255
#define NAV_G 217
#define NAV_B 0

#define MEDIA_R 0
#define MEDIA_G 255
#define MEDIA_B 38

#define RGB_R 0
#define RGB_G 38
#define RGB_B 255

#define SPECIAL_R 255
#define SPECIAL_G 0
#define SPECIAL_B 38

#define MOUSE_R 217
#define MOUSE_G 0
#define MOUSE_B 255

void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color(28, 0xFF, 0xFF, 0xFF);
    }
    if (IS_LAYER_ON(4)) {
        rgb_matrix_set_color(16, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(30, MEDIA_R, MEDIA_G, MEDIA_B);

        rgb_matrix_set_color(0, SPECIAL_R, SPECIAL_G, SPECIAL_B);
        rgb_matrix_set_color(13, SPECIAL_R, SPECIAL_G, SPECIAL_B);
    }
    else if (IS_LAYER_ON(3)) {
        // RGB Keys
        rgb_matrix_set_color(1, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(2, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(3, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(4, RGB_R, RGB_G, RGB_B);

        rgb_matrix_set_color(16, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(29, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(30, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(31, RGB_R, RGB_G, RGB_B);
    }
    else if (IS_LAYER_ON(2)) {
        // Media keys
        rgb_matrix_set_color(1, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(2, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(3, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(4, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(5, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(6, MEDIA_R, MEDIA_G, MEDIA_B);
        rgb_matrix_set_color(7, MEDIA_R, MEDIA_G, MEDIA_B);

        // L,./ Arrow keys
        rgb_matrix_set_color(37, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(49, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(50, NAV_R, NAV_G, NAV_B);
        rgb_matrix_set_color(51, NAV_R, NAV_G, NAV_B);

        // RGB Keys
        rgb_matrix_set_color(11, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(12, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(13, RGB_R, RGB_G, RGB_B);

        rgb_matrix_set_color(16, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(29, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(30, RGB_R, RGB_G, RGB_B);
        rgb_matrix_set_color(31, RGB_R, RGB_G, RGB_B);

        // Mouse Keys
        rgb_matrix_set_color(41, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(42, MOUSE_R, MOUSE_G, MOUSE_B);
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
        rgb_matrix_set_color(42, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(43, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(53, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(54, MOUSE_R, MOUSE_G, MOUSE_B);
        rgb_matrix_set_color(55, MOUSE_R, MOUSE_G, MOUSE_B);
    }

}

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
