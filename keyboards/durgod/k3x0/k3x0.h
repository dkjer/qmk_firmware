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

#include "quantum.h"

#ifndef WINLOCK_DISABLED
// Define the TGUI key here so it is available in QMK configurator
enum K3x0_keycodes {
#ifdef VIA_ENABLE
    KC_TGUI = USER00,   // Toggle between GUI Lock or Unlock
    NEW_SAFE_RANGE = SAFE_RANGE
#else
    KC_TGUI = SAFE_RANGE,   // Toggle between GUI Lock or Unlock
    NEW_SAFE_RANGE
#endif
};

#undef SAFE_RANGE
#define SAFE_RANGE NEW_SAFE_RANGE
#endif /* WINLOCK_DISABLED */

/* Function Prototype */
void off_all_leds(void);
void on_all_leds(void);
void blink_all_leds(uint8_t count);

// These wrap interacting with the WIN and MR LED indicators
// It is preferable to use these getters/setters instead of 
// directly setting WIN/MR pin states so that we can correctly
// blink LEDs and reset them back to their current state.
bool get_winlock_state(void);
bool get_mrlock_state(void);
void set_winlock_state(bool value);
void set_mrlock_state(bool value);
bool toggle_winlock_state(void);
bool toggle_mrlock_state(void);

#define XXX KC_NO

/* Omit row 8 if it's not physically present */
#if MATRIX_ROWS < 8
# define K3x0_ROW_8(X70,  X71,  X72,  X73,  X74,  X75,  X76,  X77,  X78,  X79,  X7A,  X7B,  X7C,  X7D,  X7E,  X7F)
#else
# define K3x0_ROW_8(X70,  X71,  X72,  X73,  X74,  X75,  X76,  X77,  X78,  X79,  X7A,  X7B,  X7C,  X7D,  X7E,  X7F) \
    { X70,  X71,  X72,  X73,  X74,  X75,  X76,  X77,  X78,  X79,  X7A,  X7B,  X7C,  X7D,  X7E,  X7F }
#endif

// This a shortcut to help you visually see your layout.
#define LAYOUT_fullsize_ansi( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,                          \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,      K6A, K69, K68, K67, \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,      K3D,  K3E,  K3F,      K7A, K79, K78, K6B, \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,        K4E,                            K7E, K7D, K7C,      \
      K40,        K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,            K6E, K6D, K6C, K7B, \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F,      K7F,      K77       \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  XXX,  K3D,  K3E,  K3F },  \
    { K40,  XXX,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K67,  K68,  K69,  K6A,  K6B,  K6C,  K6D,  K6E,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K77,  K78,  K79,  K7A,  K7B,  K7C,  K7D,  K7E,  K7F)    \
}

// This a shortcut to help you visually see your layout.
#define LAYOUT_fullsize_iso( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,                          \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,      K6A, K69, K68, K67, \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,            K3D,  K3E,  K3F,      K7A, K79, K78, K6B, \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K4E,                            K7E, K7D, K7C,      \
      K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,            K6E, K6D, K6C, K7B, \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F,      K7F,      K77       \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  XXX,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F },  \
    { K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K67,  K68,  K69,  K6A,  K6B,  K6C,  K6D,  K6E,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K77,  K78,  K79,  K7A,  K7B,  K7C,  K7D,  K7E,  K7F)    \
}

// This a shortcut to help you visually see your layout.
#define LAYOUT_tkl_ansi( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,  \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,  \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,      K3D,  K3E,  K3F,  \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,        K4E,                        \
      K40,        K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,        \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F   \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  XXX,  K3D,  K3E,  K3F },  \
    { K40,  XXX,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX)    \
}

// This a shortcut to help you visually see your layout.
#define LAYOUT_tkl_iso( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,  \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,  \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,            K3D,  K3E,  K3F,  \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K4E,                        \
      K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,        \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F   \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  XXX,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F },  \
    { K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX)    \
}

// This a shortcut to help you visually see your layout.
#define LAYOUT_tkl( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,  \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,  \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,      K3D,  K3E,  K3F,  \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K4E,                        \
      K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,        \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F   \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F },  \
    { K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX)    \
}

// This a shortcut to help you visually see your layout.
#define LAYOUT_all( \
      K00,        K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,      K0D,  K0E,  K0F,                          \
      K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  K1E,      K2E,  K2F,  K1F,      K6A, K69, K68, K67, \
      K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,      K3D,  K3E,  K3F,      K7A, K79, K78, K6B, \
      K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K4E,                            K7E, K7D, K7C,      \
      K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,        K4D,            K4F,            K6E, K6D, K6C, K7B, \
      K50,  K51,  K52,                    K56,                    K5A,  K5B,  K5C,  K5D,      K5E,  K5F,  K6F,      K7F,      K77       \
) { \
    { K00,  K01,  K02,  K03,  K04,  K05,  K06,  K07,  K08,  K09,  K0A,  K0B,  K0C,  K0D,  K0E,  K0F },  \
    { K10,  K11,  K12,  K13,  K14,  K15,  K16,  K17,  K18,  K19,  K1A,  K1B,  K1C,  XXX,  K1E,  K1F },  \
    { K20,  K21,  K22,  K23,  K24,  K25,  K26,  K27,  K28,  K29,  K2A,  K2B,  K2C,  K2D,  K2E,  K2F },  \
    { K30,  K31,  K32,  K33,  K34,  K35,  K36,  K37,  K38,  K39,  K3A,  K3B,  K3C,  K3D,  K3E,  K3F },  \
    { K40,  K41,  K42,  K43,  K44,  K45,  K46,  K47,  K48,  K49,  K4A,  K4B,  XXX,  K4D,  K4E,  K4F },  \
    { K50,  K51,  K52,  XXX,  XXX,  XXX,  K56,  XXX,  XXX,  XXX,  K5A,  K5B,  K5C,  K5D,  K5E,  K5F },  \
    { XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K67,  K68,  K69,  K6A,  K6B,  K6C,  K6D,  K6E,  K6F },  \
    K3x0_ROW_8(                                                                                         \
      XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  XXX,  K77,  K78,  K79,  K7A,  K7B,  K7C,  K7D,  K7E,  K7F)    \
}
