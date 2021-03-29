/* Copyright 2021 kuenhlee and Don Kjer
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

#include "k320.h"
#include "eeprom_stm32.h"
#include "eeprom.h"

/* Private Functions */
void off_all_leds(void) {
    writePinHigh(LED_CAPS_LOCK_PIN);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    writePinHigh(LED_WIN_LOCK_PIN);
    writePinHigh(LED_MR_LOCK_PIN);
}

void on_all_leds(void) {
    writePinLow(LED_CAPS_LOCK_PIN);
    writePinLow(LED_SCROLL_LOCK_PIN);
    writePinLow(LED_WIN_LOCK_PIN);
    writePinLow(LED_MR_LOCK_PIN);
}

/* WinLock and MR LEDs are non-standard. Need to override led init */
void led_init_ports(void) {
    setPinOutput(LED_CAPS_LOCK_PIN);
    setPinOutput(LED_SCROLL_LOCK_PIN);
    setPinOutput(LED_WIN_LOCK_PIN);
    setPinOutput(LED_MR_LOCK_PIN);
    off_all_leds();
}


//#ifndef WINLOCK_DISABLED
//static bool win_key_locked = false;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case KC_TGUI:
        //    if (record->event.pressed) {
        //        // Toggle GUI lock on key press
        //        win_key_locked = !win_key_locked;
        //        writePin(LED_WIN_LOCK_PIN, !win_key_locked);
        //    }
        //    break;
        //case KC_LGUI:
        //    if (win_key_locked) { return false; }
        //    break;
        case KC_HOME:
            dprintf("calling EEPROM_Init\n");
            EEPROM_Init();
            dprintf("done calling EEPROM_Init\n");
            break;
    }
    return process_record_user(keycode, record);
}
//#endif /* WINLOCK_DISABLED */

void keyboard_post_init_kb(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
}
