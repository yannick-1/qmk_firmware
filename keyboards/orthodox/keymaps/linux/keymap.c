#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _LAYER_1 1
#define _LAYER_2 2
#define _LAYER_3 3
#define _ADJUST 16

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    ADJUST,
};

// Tap dance declarations
enum {
    TD_TAB_GESC = 0, 
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_GESC]      = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LS__SPC MT(MOD_LSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(\
        TD(TD_TAB_GESC), KC_Q, KC_W, KC_E, KC_R, KC_T,                                                                                                   KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_BSPC,  \
        KC_BSPC,         KC_A, KC_S, KC_D, KC_F, KC_G,          KC_LGUI,      KC_PGUP,                   KC_PGDOWN,                 KC_LALT,               KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_ENT,   \
        KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LGUI, LT(1,KC_SPC), MT(MOD_LCTL, KC_PGUP),     MT(MOD_RCTL, KC_PGDOWN),   LT(2,KC_DEL), KC_LALT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_RSFT   \
    ),

    [_LAYER_1] = LAYOUT(\
        KC_GESC, _______, _______, KC_LPRN, KC_RPRN, _______,                                                             KC_CIRC, KC_LABK, KC_UP,   KC_RABK,  KC_AMPR,  KC_BSLS,  \
        _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP,            _______, _______,     _______, _______,          KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT,  KC_EXLM,  \
        _______, _______, _______, KC_LCBR, KC_RCBR, KC_PGDOWN, _______, _______, RESET,       KC_END,  _______, _______, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR,  KC_SLASH, KC_UNDS   \
    ),

    [_LAYER_2] = LAYOUT(\
        KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                           _______,  KC_7, KC_8, KC_9, KC_VOLU, KC_MNXT,  \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F11,  KC_F12,      _______, _______,          _______,  KC_4, KC_5, KC_6, KC_VOLD, KC_MPLY,  \
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, KC_HOME,     _______, _______, _______, KC_0,     KC_1, KC_2, KC_3, KC_MUTE, KC_MPRV   \
    ),

    [_ADJUST] =  LAYOUT(\
        RGB_TOG, _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL,                                                       _______, _______, _______, _______, _______, KC_DEL,   \
        RGB_MODE_FORWARD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MODE_SNAKE, RGB_MODE_KNIGHT,           _______, _______,     _______, _______,          AG_SWAP, COLEMAK, _______, _______, _______, _______,  \
        RGB_MODE_REVERSE, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MODE_XMAS, RGB_MODE_GRADIENT, _______, _______, RESET,       _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY   \
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
                persistent_default_layer_set(1UL<<_COLEMAK);
            }
            return false;
            break;
        case LAYER_1:
            if (record->event.pressed)
            {
                persistent_default_layer_set(1UL<<_LAYER_1);
            }
            return false;
            break;
        case LAYER_2:
            if (record->event.pressed)
            {
                layer_on(_LAYER_2);
                update_tri_layer(_LAYER_1, _LAYER_2, _ADJUST);
            } 
            else
            {
                layer_off(_LAYER_2);
                update_tri_layer(_LAYER_1, _LAYER_2, _ADJUST);
            }
            return false;
            break;
        case LAYER_3: 
            if (record->event.pressed)
            {
                layer_on(_LAYER_3);
                update_tri_layer(_LAYER_1, _LAYER_2, _ADJUST);
            } 
            else
            {
                layer_off(_LAYER_3);
                update_tri_layer(_LAYER_1, _LAYER_2, _ADJUST);
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

