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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xD60D
#define MANUFACTURER    Hoksi Technology

/* key matrix size (rows in specific keyboard variant) */
#define MATRIX_COLS 16

#define MATRIX_COL_PINS { C4, C5, B0, B1, B2, B10, B11, B12, B13, B14, B15, C6, C7, C10, C11, C12 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

// Dynamic EEPROM
// Something sensible or else VIA may crash
// Users may enable more if they wish
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  4095

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
// #define USB_POLLING_INTERVAL_MS 1

/* Bootmagic Lite key configuration */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#define BOOTMAGIC_LITE_ROW                 0
#define BOOTMAGIC_LITE_COLUMN              0

/* LED indicator pins */
#define LED_CAPS_LOCK_PIN   C9
#define LED_SCROLL_LOCK_PIN A8
#define LED_WIN_LOCK_PIN    A9
#define LED_MR_LOCK_PIN     A10
#define LED_PIN_ON_STATE    0

/* Original hardware "reset" button on pin D2 */
#define HARDWARE_RESET_PIN  D2

#ifdef LED_MATRIX_ENABLE

/* I2C Alternate function settings */
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

/* Set I2C speed to 400kHz */
#define I2C1_TIMINGR_PRESC     0U
#define I2C1_TIMINGR_SCLDEL    9U
#define I2C1_TIMINGR_SDADEL    0U
#define I2C1_TIMINGR_SCLH     24U
#define I2C1_TIMINGR_SCLL     78U

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
#define LED_DRIVER_ADDR_1 0b1110111

#define LED_DRIVER_COUNT 1
#ifdef ANSI_LAYOUT
# define LED_DRIVER_1_LED_TOTAL 87
#else /* ISO_LAYOUT */
# define LED_DRIVER_1_LED_TOTAL 88
#endif
#define DRIVER_LED_TOTAL LED_DRIVER_1_LED_TOTAL

#define LED_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended

#endif /* LED_MATRIX_ENABLE */
