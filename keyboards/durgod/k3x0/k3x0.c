/* Copyright 2021 kuenhlee, Don Kjer, Tyler Tidman
 * Copyright 2021 Simon Arlott
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

#include "k3x0.h"
#include <ch.h>
#include <hal.h>

/* Private Functions */
void off_all_leds(void) {
#ifdef LED_NUM_LOCK_PIN
    writePinHigh(LED_NUM_LOCK_PIN);
#endif
    writePinHigh(LED_CAPS_LOCK_PIN);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    writePinHigh(LED_WIN_LOCK_PIN);
    writePinHigh(LED_MR_LOCK_PIN);
}

void on_all_leds(void) {
#ifdef LED_NUM_LOCK_PIN
    writePinLow(LED_NUM_LOCK_PIN);
#endif
    writePinLow(LED_CAPS_LOCK_PIN);
    writePinLow(LED_SCROLL_LOCK_PIN);
    writePinLow(LED_WIN_LOCK_PIN);
    writePinLow(LED_MR_LOCK_PIN);
}

static bool winlock_state = false;
static bool mrlock_state = false;

bool get_winlock_state(void) { return winlock_state; }
bool get_mrlock_state(void) { return mrlock_state; }

void set_winlock_state(bool value) {
    winlock_state = value;
    writePin(LED_WIN_LOCK_PIN, !winlock_state);
}

void set_mrlock_state(bool value) {
    mrlock_state = value;
    writePin(LED_MR_LOCK_PIN, !mrlock_state);
}

bool toggle_winlock_state(void) {
    set_winlock_state(!winlock_state);
    return winlock_state;
}

bool toggle_mrlock_state(void) {
    set_mrlock_state(!mrlock_state);
    return mrlock_state;
}

void blink_all_leds(uint8_t count) {
    if (!count) return;
    led_t orig_state = host_keyboard_led_state();
    on_all_leds();
    wait_ms(100);
    for (uint8_t i = 1; i < count; ++i) {
        off_all_leds();
        wait_ms(100);
        on_all_leds();
        wait_ms(100);
    }
#ifdef LED_NUM_LOCK_PIN
    writePin(LED_NUM_LOCK_PIN, !orig_state.num_lock);
#endif
    writePin(LED_CAPS_LOCK_PIN, !orig_state.caps_lock);
    writePin(LED_SCROLL_LOCK_PIN, !orig_state.scroll_lock);
    writePin(LED_WIN_LOCK_PIN, !winlock_state);
    writePin(LED_MR_LOCK_PIN, !mrlock_state);
}

void matrix_init_kb(void) {
    setPinOutput(LED_WIN_LOCK_PIN);
    setPinOutput(LED_MR_LOCK_PIN);
    set_winlock_state(false);
    set_mrlock_state(false);
#ifndef STARTUP_BLINK_DISABLED
    blink_all_leds(1);
#else
    off_all_leds();
#endif
    matrix_init_user();
}

#ifdef LED_MATRIX_ENABLE
typedef void (*led_func_pointer)(void);

static void __attribute__((noinline)) handleKeycodeLED(const uint8_t is_shifted, const uint8_t* pval, const led_func_pointer inc_func, const led_func_pointer dec_func) {
#ifndef LED_LIMITS_INDICATOR_DISABLED
    uint8_t old_val = (pval ? *pval : 0);
#endif
    if (is_shifted) {
        dec_func();
    } else {
        inc_func();
    }
#ifndef LED_LIMITS_INDICATOR_DISABLED
    /* If the value reached its limit, blink leds */
    if (pval && (*pval == old_val)) {
        blink_all_leds(2);
    }
#endif
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch (keycode) {
        case RESET:
            if (record->event.pressed) {
                // Flash LEDs to indicate bootloader mode is enabled.
                blink_all_leds(2);
            }
            break;
#ifndef WINLOCK_DISABLED
        case KC_TGUI:
            if (record->event.pressed) {
                // Toggle GUI lock on key press
                toggle_winlock_state();
            }
            break;
        case KC_LGUI:
            if (get_winlock_state()) { return false; }
            break;
#endif
    }

#if defined(LED_MATRIX_ENABLE)
    uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
    if (record->event.pressed) {
        switch (keycode) {
            case BL_DEC:
                shifted = !shifted;
            case BL_INC:
                handleKeycodeLED(shifted, &led_matrix_eeconfig.val,
                                 led_matrix_increase_val, led_matrix_decrease_val);
                return false;
            case BL_STEP:
                handleKeycodeLED(shifted, NULL,
                                 led_matrix_step, led_matrix_step_reverse);
                return false;
            case RGB_SPD:
                shifted = !shifted;
            case RGB_SPI:
                handleKeycodeLED(shifted, &led_matrix_eeconfig.speed,
                                 led_matrix_increase_speed, led_matrix_decrease_speed);
                return false;
        }
    }
#endif
    return true;
}

#ifndef HW_RESET_PIN_DISABLED
static void hardware_reset_cb(void *arg) {
    chSysLockFromISR();
    bootloader_jump();
    chSysUnlockFromISR();
}
#endif

void keyboard_pre_init_kb(void) {
    setPinInputHigh(HARDWARE_RESET_PIN);

#ifndef HW_RESET_PIN_DISABLED
    /* Jump to bootloader when the hardware reset button is pressed */
    palEnablePadEvent(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), PAL_EVENT_MODE_FALLING_EDGE);
    palSetPadCallback(PAL_PORT(HARDWARE_RESET_PIN), PAL_PAD(HARDWARE_RESET_PIN), hardware_reset_cb, NULL);

    /* The interrupt is edge-triggered so check that it's not already pressed */
    if (!readPin(HARDWARE_RESET_PIN)) {
        bootloader_jump();
    }
#endif /* HW_RESET_PIN_DISABLED */
}

#ifdef LED_MATRIX_ENABLE
void suspend_power_down_kb(void) {
    led_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    led_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif
