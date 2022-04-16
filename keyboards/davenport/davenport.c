/* Copyright 2019 Evy Dekkers
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
#include "davenport.h"
#include "drivers/led/issi/is31fl3731-simple.h"


// this might need to be LED_DRIVER_COUNT? i changed it to match doc example
const is31_led __flash g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  LED address
 *   |  | */
    {0, C5_8},              {0, C1_4},  {0, C3_1},  {0, C5_3},  {0, C7_5},  {0, C9_7},  {0, C9_8},  {0, C8_6},  {0, C6_4},  {0, C4_2},  {0, C2_1},  {0, C1_2},  {0, C3_4},       {0, C5_6},  {0, C7_8},  {0, C8_8},       {0, C6_7},  {0, C4_5},  {0, C2_3},  {0, C1_1}, \
    {0, C3_6},  {0, C5_1},  {0, C2_2},  {0, C5_2},  {0, C7_1},  {0, C9_3},  {0, C8_5},  {0, C7_6},  {0, C9_4},  {0, C8_2},  {0, C6_1},  {0, C4_3},  {0, C2_4},  {0, C1_6},       {0, C3_8},  {0, C5_7},  {0, C6_6},       {0, C4_8},  {0, C2_7},  {0, C1_5},  {0, C3_3}, \
    {0, C1_3},  {0, C3_2},  {0, C6_8},  {0, C7_4},  {0, C9_2},  {0, C8_1},  {0, C6_3},  {0, C5_4},  {0, C7_2},  {0, C9_1},  {0, C8_3},  {0, C6_5},  {0, C4_6},  {0, C2_8},       {0, C1_7},  {0, C3_5},  {0, C4_4},       {0, C2_6},  {0, C1_8},  {0, C3_7},  {0, C5_5}, \
    {0, C5_16}, {0, C1_12}, {0, C3_9},  {0, C5_11}, {0, C7_13}, {0, C9_15}, {0, C9_16}, {0, C8_14}, {0, C6_12}, {0, C4_10}, {0, C2_9},  {0, C1_10},             {0, C3_12},                                               {0, C6_15}, {0, C4_13}, {0, C2_11}, \
    {0, C5_9},              {0, C5_10}, {0, C7_9},  {0, C9_11}, {0, C8_13}, {0, C7_14}, {0, C9_12}, {0, C8_10}, {0, C6_9},  {0, C4_11}, {0, C2_12},             {0, C1_14},                  {0, C5_15},                  {0, C4_16}, {0, C2_15}, {0, C1_13}, {0, C3_11}, \
    {0, C1_11}, {0, C3_10}, {0, C6_16},                                     {0, C6_11},                                     {0, C8_11}, {0, C6_13}, {0, C4_14}, {0, C2_16},      {0, C1_15}, {0, C3_13}, {0, C4_12},      {0, C2_14},             {0, C3_15}\
};
#define NO NO_LED
#define LED LED_FLAG_KEYLIGHT

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
      { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9  },\
      { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },\
      { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 },\
      { 62, 63, 64, 65, 66, 67, 68, 69, 70, 71 },\
      { 78, 79, 80, 81, 82, 83, 84, 85, 86, 87 },\
      { 95, 96, 97, NO, NO, 98, NO, NO, NO, 99 },\
      { 19, 18, 17, 16, 15, 14, 13, 12, 11, 10 },\
      { 40, 39, 38, 37, 36, 35, 34, 32, 31, 30 },\
      { 61, 60, 59, 58, 57, 56, 55, 53, 52, 51 },\
      { NO, 77, 76, 75, NO, NO, 33, 74, 73, 72 },\
      { 94, 93, 92, 91, NO, 90, 54, 89, NO, 88 },\
      { NO,107, NO, 106,105,104,103,102,101,100}\
  },
  {
    // LED Index to Physical Position
    {   0,  0 },                {   0, 23 },  {   0, 35 },  {   0, 47 },  {   0, 58 },  {   0, 70 },  {   0, 81 },  {   0, 93 },  {   0, 104 },  {   0, 116 },  {   0, 127 },  {   0, 139 },  {   0, 150},       {   0, 174},  {   0, 185 },  {   0, 197 },       {   0, 220 },  {   0, 231 },  {   0, 243 },  {   0, 255 }, \
    {  53,  0 },  {  53, 12 },  {  53, 23 },  {  53, 35 },  {  53, 47 },  {  53, 58 },  {  53, 70 },  {  53, 81 },  {  53, 93 },  {  53, 104 },  {  53, 116 },  {  53, 127 },  {  53, 139 },  {  53, 150},       {  53, 174},  {  53, 185 },  {  53, 197 },       {  53, 220 },  {  53, 231 },  {  53, 243 },  {  53, 255 }, \
    { 106,  0 },  { 106, 12 },  { 106, 23 },  { 106, 35 },  { 106, 47 },  { 106, 58 },  { 106, 70 },  { 106, 81 },  { 106, 93 },  { 106, 104 },  { 106, 116 },  { 106, 127 },  { 106, 139 },  { 106, 150},       { 106, 174},  { 106, 185 },  { 106, 197 },       { 106, 220 },  { 106, 231 },  { 106, 243 },  { 106, 255 }, \
    { 159,  0 },  { 159, 12 },  { 159, 23 },  { 159, 35 },  { 159, 47 },  { 159, 58 },  { 106, 70 },  { 159, 81 },  { 159, 93 },  { 159, 104 },  { 159, 116 },  { 159, 127 },                 { 159, 150},                                                        { 159, 220 },  { 159, 231 },  { 159, 243 }, \
    { 212,  0 },                { 212, 23 },  { 212, 35 },  { 212, 47 },  { 212, 58 },  { 212, 70 },  { 212, 81 },  { 212, 93 },  { 212, 104 },  { 212, 116 },  { 212, 127 },                 { 212, 150},                     { 212, 185 },                      { 212, 220 },  { 212, 231 },  { 212, 243 },  { 212, 255}, \
    { 255,  0 },  { 255, 12 },  { 255, 23 },                                            { 255, 70 },                                             { 255, 116 },  { 255, 127 },  { 255, 139 },  { 255, 150},       { 255, 174},  { 255, 185 },  { 255, 197 },       { 255, 220 },                 { 255, 243 }\
  },
  {
    // LED Index to Flag
    LED,      LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED,     LED, LED, LED,     LED, LED, LED, LED, \
    LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED,     LED, LED, LED,     LED, LED, LED, LED, \
    LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED,     LED, LED, LED,     LED, LED, LED, LED, \
    LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED,      LED,                        LED, LED, LED,      \
    LED, LED, LED, LED, LED, LED, LED, LED, LED, LED, LED,           LED,          LED,          LED, LED, LED, LED, \
    LED, LED, LED,                LED,                LED, LED, LED, LED,     LED, LED, LED,     LED,      LED      \

  }
};


void matrix_init_kb(void) {

    // // green led on
    // DDRD |= (1<<5);
    // PORTD &= ~(1<<5);

    // // orange led on
    // DDRB |= (1<<0);
    // PORTB &= ~(1<<0);
	matrix_init_user();
    led_matrix_mode(2); // breathing
    led_matrix_enable();
    //backlight_level(3);
};


