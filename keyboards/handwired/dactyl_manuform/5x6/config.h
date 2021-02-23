#pragma once

#include "config_common.h"

#define PRODUCT_ID      0x3536
#define DEVICE_VER      0x0001
#define PRODUCT         Dactyl-Manuform (5x6)

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { F6, F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN D3
#define RGBLED_NUM 16
#define RGBLED_SPLIT { 8, 8 }

#define TAPPING_TERM 275

