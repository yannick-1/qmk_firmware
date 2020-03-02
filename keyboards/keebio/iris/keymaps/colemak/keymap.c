#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define TAPPING_TOGGLE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_COLEMAK] = LAYOUT(
        KC_GESC,   KC_1, KC_2, KC_3, KC_4, KC_5,        		     	     KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,    KC_Q, KC_W, KC_F, KC_P, KC_G,             	  	         KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSLASH,
        KC_BSPC,   KC_A, KC_R, KC_S, KC_T, KC_D,            	   		     KC_H, KC_N, KC_E,    KC_I,   KC_O,    KC_ENT,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,  _______,          _______, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT,
                               KC_LGUI, KC_LCTRL, LT(1,KC_SPC),     LT(2,KC_DEL), KC_LCTRL, KC_RALT
    ),

    [_LOWER] = LAYOUT(
        KC_GRAVE, _______, _______, _______, _______, _______,                       _______, _______, _______, _______,  _______,  _______,
        _______,  _______, _______, KC_LPRN, KC_RPRN, KC_PERC,   		             KC_CIRC, KC_LABK, KC_UP  , KC_RABK,  KC_AMPR,  KC_EXLM,
        _______,  _______, _______, KC_LBRC, KC_RBRC, _______,       		     	 KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, _______,
        _______,  _______, _______, KC_LCBR, KC_RCBR, _______, _______,     _______, KC_EQL , KC_PPLS, KC_PMNS, KC_PAST,  KC_PSLS,  KC_UNDS,
                                              _______, RESET,  _______,     _______, _______, _______ 
    ),

    [_RAISE] = LAYOUT(
        KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            			    KC_F6  , KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,               		_______, KC_7,  KC_8,  KC_9,  _______, KC_F12,
        _______, _______, KC_MPRV, KC_MPLY, KC_MFFD, _______,               		_______, KC_4,  KC_5,  KC_6,  _______, _______,
        _______, _______, _______, _______, _______, _______, KC_PSCR,     _______, KC_0,    KC_1,  KC_2,  KC_3,  _______, _______,
                                            _______, _______, _______,     _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,					    _______, _______, _______, _______, _______, _______,
        KC_RTOG, KC_RMOD, KC_RHUI, KC_RSAI, KC_RVAI, _______,						_______, _______, _______, _______, _______, _______,
        _______, KC_DBUG, KC_RHUD, KC_RSAD, KC_RVAD, _______,						_______, _______, _______, _______, _______, _______,
        KC_BL_S, KC_RST,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, 
                                           _______, _______, _______,	   _______, _______, _______
    )

};

void persistent_default_layer_set(uint16_t default_layer) 
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) 
    {
        case COLEMAK:
            if (record->event.pressed) 
            {
                persistent_default_layer_set(1UL << _COLEMAK);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) 
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
            else 
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) 
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
            else 
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) 
            {
                layer_on(_ADJUST);
            } 
            else 
            {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}

