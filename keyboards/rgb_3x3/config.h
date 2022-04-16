/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3061
#define DEVICE_VER      0x0001
#define MANUFACTURER    FlyBirdman
#define PRODUCT         TwoByTwo
#define DESCRIPTION     A tiny macro pad

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

// wiring of each half
#define MATRIX_ROW_PINS { B5, B4, E6 }
#define MATRIX_COL_PINS { B1, B3, B2 }
// #define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6 } //uncomment this line and comment line above if you need to reverse left-to-right key order

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

//#undef RGBLED_NUM
#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES
#define DRIVER_LED_TOTAL 9
#endif


#define RGB_DI_PIN B6

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 9
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
#endif

// #define RGBLIGHT_HUE_STEP 5    // How much each press of rgb_hue changes hue
// #define RGBLIGHT_SAT_STEP 10   // How much each press of rgb_sat changes sat
// #define RGBLIGHT_VAL_STEP 10   // How much each press of rgb_val changes val
// #define RGBSTRIP_CURRENT_LIMIT 20        // Strip current limit in mA.
// #define RGBSTRIP_MAX_CURRENT_PER_LIGHT 5 // mA per light when at max brightness.

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
#endif
