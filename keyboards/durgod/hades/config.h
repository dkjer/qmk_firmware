/* Copyright 2021 Don Kjer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xD60D
#define PRODUCT_ID      0xbde5
#define DEVICE_VER      0x0001
#define MANUFACTURER    Hoksi Technology
#define PRODUCT         DURGOD Hades (QMK)

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4 }
#define MATRIX_COL_PINS { B0, B1, B2, B10, B11, B12, B13, B14, B15, C6, C7, C8, C9, C10, C11 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Bootmagic Lite key configuration */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#define BOOTMAGIC_LITE_ROW                 0
#define BOOTMAGIC_LITE_COLUMN              0

/* LED indicator pins */
#define LED_CAPS_LOCK_PIN   C4
#define LED_WIN_LOCK_PIN    C5
#define LED_MR_LOCK_PIN     A8
#define LED_1_PIN           LED_CAPS_LOCK_PIN
#define LED_2_PIN           LED_WIN_LOCK_PIN
#define LED_3_PIN           LED_MR_LOCK_PIN
#define LED_PIN_ON_STATE    0

/* I2C Alternate function settings */
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 00 <-> GND
// 01 <-> SCL
// 10 <-> SDA
// 11 <-> VCC
// ADDR1 represents A1:A0 of the 7-bit address.
// ADDR2 represents A3:A2 of the 7-bit address.
// The result is: 0b101(ADDR2)(ADDR1)
#ifdef RGB_MATRIX_ENABLE
#define DRIVER_ADDR_1 0b1010000
#define DRIVER_ADDR_2 0b1010011

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 58
#define DRIVER_2_LED_TOTAL 10
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_LED_PROCESS_LIMIT 4
#define RGB_MATRIX_LED_FLUSH_LIMIT 26
//#define DISABLE_RGB_MATRIX_SPLASH
//#define DISABLE_RGB_MATRIX_MULTISPLASH
//#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL
//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
#endif /* RGB_MATRIX_ENABLE */
