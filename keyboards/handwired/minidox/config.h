
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEEF
#define PRODUCT_ID      0xBEEF
#define DEVICE_VER      0x0001
#define MANUFACTURER    pants
#define PRODUCT         Minidox
#define DESCRIPTION     Handwired minidox with encoder, RGB

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// wiring of each half
#define MATRIX_ROW_PINS { F4, F5, F6, F7, B6 }
#define MATRIX_COL_PINS { D0, D4, C6, D7, E6, B4, B5 }

// #define USE_SERIAL
#define UES_I2C

#define MASTER_LEFT
// #define MASTER_RIGHT

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

// /* Encoder definitions */
#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 4

/* Tap dance options */
#define TAPPING_TERM 175

// #define SERIAL_USE_MULTI_TRANSACTION

#endif
