
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _GAME_1 3
#define _GAME_2 4
#define _QWERTY 5
#define _Q_LOWER 6
#define _Q_RAISE 7

#define QWERTY  TG(_QWERTY)
#define GAME    TG(_GAME_1)

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_5x6(
        KC_GESC, KC_1,  KC_2,    KC_3,     KC_4,     KC_5,
        KC_TAB,  KC_Q,  KC_W,    KC_F,     KC_P,     KC_G,
        KC_BSPC, KC_A,  KC_R,    KC_S,     KC_T,     KC_D,
        KC_LSFT, KC_Z,  KC_X,    KC_C,     KC_V,     KC_B,
                        KC_LBRC, KC_RBRC,
                                           KC_LCTRL,    LT(_LOWER, KC_SPC),
                                           KC_LGUI,     KC_PGUP,
                                           DF(_QWERTY), KC_PGDN,

        KC_6,               KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_J,               KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_BSLASH,
        KC_H,               KC_N,     KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_K,               KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                      KC_PLUS, KC_PMNS,
        LT(_RAISE, KC_DEL), KC_LCTRL,
        KC_HOME,            KC_LALT, 
        KC_END,             GAME
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_GRAVE, _______, _______, _______, _______, _______,
        KC_GRAVE, _______, _______, KC_LPRN, KC_RPRN, KC_PERC,
        _______,  _______, _______, KC_LBRC, KC_RBRC, _______,
        _______,  _______, _______, KC_LCBR, KC_RCBR, _______,
                           _______, _______,
                                             _______, _______,
                                             _______, _______,
                                             _______, RESET,

        _______, _______, _______, _______,  _______,  _______,
        KC_CIRC, KC_LABK, KC_UP,   KC_RABK,  KC_AMPR,  KC_BSLS,
        KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, KC_EXLM,
        KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST,  KC_PSLS,  KC_UNDS,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),

    [_RAISE] = LAYOUT_5x6(
        KC_GESC, _______, _______, _______, _______, _______,
        KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                          KC_F11,  KC_F12,
                                            _______, _______,
                                            _______, _______,
                                            _______, _______,

        _______, _______, _______, _______, _______, _______,
        _______, KC_7,    KC_8,    KC_9,    KC_VOLU, KC_MNXT,
        _______, KC_4,    KC_5,    KC_6,    KC_VOLD, KC_MPLY,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_MUTE, KC_MPRV,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),

    [_GAME_1] = LAYOUT_5x6(
        KC_ESC,  KC_TAB, KC_1,    KC_2,     KC_3,    KC_4,
        KC_BSLS, KC_Q,   KC_W,    KC_F,     KC_P,    KC_G,
        KC_BSPC, KC_A,   KC_R,    KC_S,     KC_T,    KC_D,
        KC_LSFT, KC_Z,   KC_X,    KC_C,     KC_V,    KC_B,
                         KC_LBRC, KC_RBRC,
                                            KC_0,    KC_SPC,
                                            KC_COMM, LT(_GAME_2, KC_ENT),
                                            KC_INS,  KC_END,

        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),  

    [_GAME_2] = LAYOUT_5x6(
        KC_GRAVE, KC_5,   KC_6,    KC_7,     KC_8,    KC_9,
        KC_T,     KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,
        KC_G,     KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN,
        KC_B,     KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
                          KC_LEFT, KC_RIGHT,
                                             _______, _______,
                                             _______, _______,
                                             _______, _______,

        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),        

    [_QWERTY] = LAYOUT_5x6(
        KC_GESC, KC_1, KC_2,    KC_3,     KC_4,         KC_5,
        KC_TAB,  KC_Q, KC_W,    KC_E,     KC_R,         KC_T,
        KC_BSPC, KC_A, KC_S,    KC_D,     KC_F,         KC_G,
        KC_LSFT, KC_Z, KC_X,    KC_C,     KC_V,         KC_B,
                       KC_LBRC, KC_RBRC,
                                          KC_LCTRL,     LT(_Q_LOWER, KC_SPC),
                                          KC_LGUI,      KC_PGUP,
                                          DF(_COLEMAK), KC_PGDN,

        KC_6,                 KC_7,     KC_8,    KC_9,   KC_0,    KC_BSPC,
        KC_Y,                 KC_U,     KC_I,    KC_O,   KC_P,    KC_BSLASH,
        KC_H,                 KC_J,     KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_N,                 KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                        KC_PLUS, KC_PMNS, 
        LT(_Q_RAISE, KC_DEL), KC_LCTRL,
        KC_HOME,              KC_LALT, 
        KC_END,               _______
    ),

    [_Q_LOWER] = LAYOUT_5x6(
        KC_GRAVE, _______, _______, _______, _______,  _______,
        KC_GRAVE, _______, _______, KC_LPRN, KC_RPRN,  KC_PERC,
        _______,  _______, _______, KC_LBRC, KC_RBRC,  _______,
        _______,  _______, _______, KC_LCBR, KC_RCBR,  _______,
                           _______, _______,
                                             _______,  _______,
                                             _______,  _______,
                                             _______,  RESET,

        _______, _______, _______, _______,  _______,  _______,
        KC_CIRC, KC_LABK, KC_UP,   KC_RABK,  KC_AMPR,  KC_BSLS,
        KC_PERC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOTE, KC_EXLM,
        KC_EQL,  KC_PPLS, KC_PMNS, KC_PAST,  KC_PSLS,  KC_UNDS,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),

    [_Q_RAISE] = LAYOUT_5x6(
        KC_GESC, _______, _______, _______, _______, _______,
        KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                          KC_F11,  KC_F12,
                                            _______, _______,
                                            _______, _______,
                                            _______, _______,

        _______, _______, _______, _______, _______, _______,
        _______, KC_7,    KC_8,    KC_9,    KC_VOLU, KC_MNXT,
        _______, KC_4,    KC_5,    KC_6,    KC_VOLD, KC_MPLY,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_MUTE, KC_MPRV,
                          _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),

};


