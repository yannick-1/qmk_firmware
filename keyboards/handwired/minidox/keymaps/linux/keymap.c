#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    ENABLE_SELECTOR
};


// Tap Dance Declarations
enum {
    TD_Q_TAB = 0, 
    TD_A_BSPC = 1, 
    TD_P_BSPC = 2, 
    TD_SCLN_ENT = 3
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Q, twice for Tab
    [TD_Q_TAB]      = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
    [TD_A_BSPC]     = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_BSPC),
    [TD_P_BSPC]     = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),
    [TD_SCLN_ENT]   = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT)
};

// Fillers to make layering more cle
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST  RESET
#define KC_CAD  LCTL(LALT(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q, KC_W,  KC_E,               KC_R,               KC_T,                                /* left */   KC_LEFT,    KC_Y,               KC_U,               KC_I,               KC_O,   KC_P,    KC_BSPC, 
        KC_BSPC, KC_A, KC_S,  MT(MOD_LALT, KC_D), MT(MOD_LCTL, KC_F), MT(MOD_LGUI, KC_G),                  /* up */     KC_UP,      MT(MOD_LGUI, KC_H), MT(MOD_RCTL, KC_J), MT(MOD_RALT, KC_K), KC_L,   KC_SCLN, KC_ENT, 
        KC_LSFT, KC_Z, KC_X,  KC_C,               KC_V,               KC_B,               ENABLE_SELECTOR, /* right */  KC_RIGHT,   KC_N,               KC_M,               KC_COMM,            KC_DOT, KC_SLSH, KC_RSFT, 
                              KC_LGUI,            KC_LCTL,            LT(1, KC_SPC),                       /* down */   KC_DOWN,    LT(2, KC_DEL),      KC_RCTL,            KC_LALT,
                                                                                                           /* center */ KC_ENT
    ),

    [_LOWER] = LAYOUT(
        KC_GESC, KC_GESC, _______, KC_LPRN, KC_RPRN, _______,                _______, KC_CIRC, KC_LABK, KC_UP,   KC_RABK,  KC_AMPR,  KC_BSLS, 
        _______, _______, _______, KC_LBRC, KC_RBRC, _______,                _______, KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, KC_EXLM, 
        _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______,       _______, KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST,  KC_PSLS,  KC_UNDS, 
                          RESET,   _______, _______,                _______, _______, _______, _______, 
                                                                    _______
    ),

    [_RAISE] = LAYOUT(
         _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,               KC_MPRV, KC_MPLY,  KC_7,    KC_8,    KC_9,  _______, _______,
         _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                 KC_VOLU, KC_MUTE,  KC_4,    KC_5,    KC_6,  _______, _______, 
         _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,   _______,     KC_MFFD, KC_0,     KC_1,    KC_2,    KC_3,  _______, _______, 
                           KC_F11, KC_F12,  _______,                        KC_VOLD, _______,  _______, _______,
                                                                            _______
    ),

    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______,                        _______, _______, _______, _______,
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
                tap_code(KC_DOWN);
        } 
            else 
            {
                tap_code(KC_UP);
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
                set_single_persistent_default_layer(_QWERTY);
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

