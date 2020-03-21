#ifndef MINIDOX_H
#define MINIDOX_H


#include "quantum.h"

#define LAYOUT( \
	L00, L01, L02, L03, L04, L05,           	RNL, R05, R04, R03, R02, R01, R00, \
	L10, L11, L12, L13, L14, L15,           	RNU, R15, R14, R13, R12, R11, R10, \
	L20, L21, L22, L23, L24, L25, L26,          RNR, R25, R24, R23, R22, R21, R20, \
				        LT1, LT2, LT3, 			RND, RT3, RT2, RT1, \
                                                RNC \
	) \
	{ \
		{ L00,   L01,   L02,   L03,   L04,   L05,   KC_NO }, \
		{ L10,   L11,   L12,   L13,   L14,   L15,   KC_NO }, \
		{ L20,   L21,   L22,   L23,   L24,   L25,   L26}, \
		{ KC_NO, KC_NO, KC_NO, KC_NO, LT1,   LT2,   LT3 }, \
		{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
													\
		{ R00,   R01,   R02,   R03,   R04,   R05,   RNL }, \
		{ R10,   R11,   R12,   R13,   R14,   R15,   RNU }, \
		{ R20,   R21,   R22,   R23,   R24, 	 R25,   RNR }, \
		{ KC_NO, KC_NO, KC_NO, RT1,   RT2,   RT3,   RND }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RNC }  \
	}
#endif
