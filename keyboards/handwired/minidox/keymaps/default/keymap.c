#include QMK_KEYBOARD_H

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
    ENABLE_SELECTOR
};


// Tap Dance Declarations
enum {
    TD_Q_TAB = 0, 
    TD_A_BSPC = 1, 
    TD_SCLN_BSPC = 2, 
    TD_O_ENT = 3
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Q, twice for Tab
    [TD_Q_TAB]      = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
    [TD_A_BSPC]     = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_BSPC),
    [TD_SCLN_BSPC]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_BSPC),
    [TD_O_ENT]      = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_ENT)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST  RESET
#define KC_CAD  LCTL(LALT(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [_COLEMAK] = LAYOUT(
    //     TD(TD_Q_TAB),       KC_W, KC_F,    KC_P,     KC_G,                              KC_1, KC_J,         KC_L,     KC_U,     KC_Y,   TD(TD_SCLN_BSPC),
    //     TD(TD_A_BSPC),      KC_R, KC_S,    KC_T,     KC_D,                              KC_2, KC_H,         KC_N,     KC_E,     KC_I,   TD(TD_O_ENT),
    //     MT(MOD_LSFT, KC_Z), KC_X, KC_C,    KC_V,     KC_B,         ENABLE_SELECTOR,     KC_3, KC_K,         KC_M,     KC_COMM,  KC_DOT, MT(MOD_RSFT, KC_SLSH),
    //                               KC_LGUI, KC_LCTRL, LT(1,KC_SPC),                      KC_5, LT(2,KC_DEL), KC_LCTRL, KC_RALT, 
    //                                                                                     KC_6
    // )
    
    [_COLEMAK] = LAYOUT(
        TD(TD_Q_TAB),       KC_W,  KC_E,    KC_R,     KC_T,                             KC_1, KC_Y,         KC_U,     KC_I,     KC_O,   TD(TD_SCLN_BSPC),
        TD(TD_A_BSPC),      KC_S,  KC_D,    KC_F,     KC_G,                             KC_2, KC_H,         KC_J,     KC_K,     KC_L,   TD(TD_O_ENT),
        MT(MOD_LSFT, KC_Z), KC_X,  KC_C,    KC_V,     KC_B,         ENABLE_SELECTOR,    KC_3, KC_N,         KC_M,     KC_COMM,  KC_DOT, MT(MOD_RSFT, KC_SLSH),
                                   KC_LGUI, KC_LCTRL, LT(1,KC_SPC),                     KC_5, LT(2,KC_DEL), KC_LCTRL, KC_RALT,
                                                                                        KC_6
    ),

    [_LOWER] = LAYOUT(
        KC_GESC, _______, KC_LPRN, KC_RPRN, _______,                _______, KC_CIRC, KC_LABK, KC_UP,   KC_RABK,  MT(KC_EXLM, KC_AMPR),
        _______, _______, KC_LBRC, KC_RBRC, _______,                _______, KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE,
        _______, _______, KC_LCBR, KC_RCBR, _______, _______,       _______, KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST,  MT(KC_UNDS, KC_PSLS),
                          RESET,   _______, _______,                _______, _______, _______, _______, 
                                                                    _______
    ),

    [_RAISE] = LAYOUT(
        KC_F1, KC_MUTE, KC_VOLD, KC_VOLU, KC_F4,                    _______, KC_F7,  KC_7,   KC_8,   KC_9, KC_F9,
        KC_F2, KC_MPRV, KC_MPLY, KC_MFFD, KC_F5,                    _______, KC_F8,  KC_4,   KC_5,   KC_6, KC_F10,
        KC_F3, _______, _______, _______, KC_F6,   _______,         _______, KC_0,   KC_1,   KC_2,   KC_3, KC_F11,
                        _______, _______, _______,                  _______, _______, _______, _______,
                                                                    _______
    ),

    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                          _______, _______, _______,                _______, _______, _______, _______,
                                                                    _______
    )
};

bool selector_enabled = false;

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
                tap_code(KC_1);
            } 
            else 
            {
                tap_code(KC_2);
            }
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch (keycode) 
    {
        case COLEMAK:
            if (record->event.pressed) 
            {
                set_single_persistent_default_layer(_COLEMAK);
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
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } 
            else 
            {
                layer_off(_ADJUST);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ENABLE_SELECTOR:
            if (record->event.pressed) 
            {
                selector_enabled = true;
                register_code16(KC_LGUI);
                tap_code16(KC_TAB);
                tap_code16(LSFT(KC_TAB));
            }
            else 
            {
                selector_enabled = false;
                unregister_code16(KC_LGUI);
            }
            return false;
            break;
    }
    return true;
}
