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

#ifdef LED_MATRIX_ENABLE

#include "k3x0.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *    driver
 *    |  LED address
 *    |  | */
    { 0, C1_1  }, // ESC
    { 0, C1_2  }, // F1
    { 0, C1_3  }, // F2
    { 0, C1_4  }, // F3
    { 0, C1_5  }, // F4
    { 0, C1_6  }, // F5
    { 0, C1_7  }, // F6
    { 0, C1_8  }, // F7
    { 0, C1_9  }, // F8
    { 0, C1_10 }, // F9
    { 0, C1_11 }, // F10
    { 0, C1_12 }, // F11
    { 0, C1_13 }, // F12
    { 0, C1_14 }, // PRNT
    { 0, C1_15 }, // SCR
    { 0, C1_16 }, // PAUSE

    { 0, C2_1  }, // GRV
    { 0, C2_2  }, // 1
    { 0, C2_3  }, // 2
    { 0, C2_4  }, // 3
    { 0, C2_5  }, // 4
    { 0, C2_6  }, // 5
    { 0, C2_7  }, // 6
    { 0, C2_8  }, // 7
    { 0, C2_9  }, // 8
    { 0, C2_10 }, // 9
    { 0, C2_11 }, // 0
    { 0, C2_12 }, // -
    { 0, C2_13 }, // =
    { 0, C2_15 }, // BCKSP
    { 0, C3_16 }, // INS
    { 0, C3_1  }, // HOME
    { 0, C3_2  }, // PGUP

    { 0, C3_3  }, // TAB
    { 0, C3_4  }, // Q
    { 0, C3_5  }, // W
    { 0, C3_6  }, // E
    { 0, C3_7  }, // R
    { 0, C3_8  }, // T
    { 0, C3_9  }, // Y
    { 0, C3_10 }, // U
    { 0, C3_11 }, // I
    { 0, C3_12 }, // O
    { 0, C3_13 }, // P
    { 0, C3_14 }, // [
    { 0, C2_16 }, // ]
#ifdef ANSI_LAYOUT
    { 0, C3_15 }, // BCKSLSH
#endif
    { 0, C4_1  }, // DEL
    { 0, C4_2  }, // END
    { 0, C4_3  }, // PGDN

    { 0, C4_4  }, // CAPS
    { 0, C4_5  }, // A
    { 0, C4_6  }, // S
    { 0, C4_7  }, // D
    { 0, C4_8  }, // F
    { 0, C4_9  }, // G
    { 0, C4_10 }, // H
    { 0, C4_11 }, // J
    { 0, C4_12 }, // K
    { 0, C4_15 }, // DEL ==> L
    { 0, C4_16 }, // END ==> ;
    { 0, C5_16 }, // PGDN ==> '
#ifdef ISO_LAYOUT
    { 0, C4_13 }, // NUHS ? (UNTESTED)
#endif
    { 0, C5_1  }, // ENTER

    { 0, C5_3  }, // LSHIFT
#ifdef ISO_LAYOUT
    { 0, C5_2  }, // NUBS ? (UNTESTED)
#endif
    { 0, C5_4  }, // Z
    { 0, C5_5  }, // X
    { 0, C5_6  }, // C
    { 0, C5_7  }, // V
    { 0, C5_8  }, // B
    { 0, C5_9  }, // N
    { 0, C5_10 }, // M
    { 0, C5_11 }, // ,
    { 0, C5_12 }, // .
    { 0, C5_14 }, // ?
    { 0, C4_14 }, // RSHIFT
    { 0, C5_15 }, // UP

    { 0, C6_1  }, // LCTRL
    { 0, C6_2  }, // LGUI
    { 0, C6_3  }, // LALT
    { 0, C6_6  }, // SPC
    { 0, C6_9  }, // RALT
    { 0, C6_10 }, // FN
    { 0, C6_11 }, // APP
    { 0, C6_12 }, // RCTRL
    { 0, C6_13 }, // LEFT
    { 0, C6_14 }, // DOWN
    { 0, C6_15 }  // RGHT
};

#ifdef ANSI_LAYOUT
led_config_t g_led_config = { {
    { 0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15 },
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     NO_LED, 29,     30 },
    { 31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     46 },
    { 47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58,     NO_LED, 59,     60,     61 },
    { 62,     NO_LED, 63,     64,     65,     66,     67,     68,     69,     70,     71,     72,     NO_LED, 73,     74,     75 },
    { 76,     77,     78,     NO_LED, NO_LED, NO_LED, 79,     NO_LED, NO_LED, NO_LED, 80,     81,     82,     83,     84,     85 },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 86 },
}, {
    {0, 0 },           {24, 0 }, {36, 0 }, {48, 0 }, {60, 0 }, {78, 0 }, {90, 0 }, {102, 0 }, {114, 0 }, {132, 0},  {144, 0 }, {156, 0 }, {168, 0 },   {183, 0 }, {195, 0 }, {207, 0 },
    {0, 15}, {12, 15}, {24, 15}, {36, 15}, {48, 15}, {60, 15}, {72, 15}, {84, 15}, {96,  15}, {108, 15}, {120, 15}, {132, 15}, {144, 15}, {162, 15},   {183, 15}, {195, 15}, {207, 15},
    {3, 27}, {18, 27}, {30, 27}, {42, 27}, {54, 27}, {66, 27}, {78, 27}, {90, 27}, {102, 27}, {114, 27}, {126, 27}, {138, 27}, {150, 27}, {165, 27},   {183, 27}, {195, 27}, {207, 27},
    {4, 39}, {21, 39}, {33, 39}, {45, 39}, {57, 39}, {69, 39}, {81, 39}, {93, 39}, {105, 39}, {117, 39}, {129, 39}, {141, 39},            {160, 39},
    {7, 51},           {27, 51}, {39, 51}, {51, 51}, {63, 51}, {75, 51}, {87, 51}, {99,  51}, {111, 51}, {123, 51}, {135, 51},            {157, 51},              {195, 51},
    {1, 63}, {16, 63}, {31, 63},                               {76, 63},                                 {121, 63}, {136, 63}, {151, 63}, {166, 63},   {183, 63}, {195, 63}, {207, 63}
}, {
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,  1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,     1,
    1, 1, 1,          4,          1, 1, 1, 1,  1, 1, 1
} };
#else /* ISO_LAYOUT */
led_config_t g_led_config = { {
    { 0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15 },
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     NO_LED, 29,     30 },
    { 31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     NO_LED, 44,     45 },
    { 46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58,     59,     60,     61 },
    { 62,     63,     64,     65,     66,     67,     68,     69,     70,     71,     72,     73,     NO_LED, 74,     75,     76 },
    { 77,     78,     79,     NO_LED, NO_LED, NO_LED, 80,     NO_LED, NO_LED, NO_LED, 81,     82,     83,     84,     85,     86 },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 87 },
}, {
} };
#endif


#endif /* LED_MATRIX_ENABLE */
