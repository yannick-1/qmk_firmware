#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

bool selector_enabled = false;

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    ENABLE_SELECTOR
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


// Tap dance declarations
enum {
    TD_TAB_GESC = 0, 
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_GESC]      = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_QWERTY] = LAYOUT(
        KC_GESC,   KC_1, KC_2, KC_3,    KC_4,     KC_5,        		     	                  KC_6,     KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_TAB,    KC_Q, KC_W, KC_E,    KC_R,     KC_T,             	  	                  KC_Y,     KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLASH,
        KC_BSPC,   KC_A, KC_S, KC_D,    KC_F,     KC_G,           	   		                  KC_H,     KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSHIFT, KC_Z, KC_X, KC_C,    KC_V,     KC_B,     ENABLE_SELECTOR,    _______,      KC_N,     KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT,
                                        KC_LGUI,  KC_LCTRL, LT(1,KC_SPC),       LT(2,KC_DEL), KC_LCTRL, KC_LALT
    ),

    [_LOWER] = LAYOUT(
        KC_GRAVE, _______, _______, _______, _______, _______,                       _______, _______, _______, _______,  _______,  _______,
        KC_GRAVE, _______, _______, KC_LPRN, KC_RPRN, _______,   		             KC_CIRC, KC_LABK, KC_UP  , KC_RABK,  KC_AMPR,  KC_EXLM,
        _______,  _______, _______, KC_LBRC, KC_RBRC, _______,       		     	 KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, _______,
        _______,  _______, _______, KC_LCBR, KC_RCBR, _______, _______,     _______, KC_EQL , KC_PPLS, KC_PMNS, KC_PAST,  KC_PSLS,  KC_UNDS,
                                             RESET,   _______, _______,     _______, _______, _______ 
    ),

    [_RAISE] = LAYOUT(
        KC_GESC, _______, _______, _______, _______, _______,            		   _______, _______, _______, _______, _______, _______,
        KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,               	   _______, KC_7,    KC_8,    KC_9,    KC_VOLU, KC_MNXT,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               	       _______, KC_4,    KC_5,    KC_6,    KC_VOLD, KC_MPLY,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_MUTE, KC_MPRV,
                                            KC_F11,  KC_F12, _______,     _______, _______, _______
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


void encoder_update_user(uint8_t index, bool clockwise) 
{
    if (index == 0) /* First encoder */
    {
        if (selector_enabled) 
        {
            if (clockwise) 
            {
                tap_code16(KC_TAB);
            } 
            else 
            {
                tap_code16(LSFT(KC_TAB));
            }
        }
        else
        {
            if (clockwise) 
            {
                tap_code(KC_UP);
            } 
            else 
            {
                tap_code(KC_DOWN);
            }
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) 
    {
        case QWERTY:
            if (record->event.pressed) 
            {
                persistent_default_layer_set(1UL << _QWERTY);
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
        case ENABLE_SELECTOR:
            if (record->event.pressed) 
            {
                selector_enabled = true;
                register_code16(KC_LALT);
                tap_code16(KC_TAB);
                tap_code16(LSFT(KC_TAB));
            }
            else 
            {
                selector_enabled = false;
                unregister_code16(KC_LALT);
            }
            return false;
            break;
    }
    return true;
}

