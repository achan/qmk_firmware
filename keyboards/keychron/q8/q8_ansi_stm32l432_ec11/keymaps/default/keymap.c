/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    BASE,
    SYMB,
    NUMB,
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_69(
        KC_ESC,   HYPR(KC_A),  HYPR(KC_G),    HYPR(KC_S),    HYPR(KC_X),  HYPR(KC_F),  HYPR(KC_W),  HYPR(KC_C),  HYPR(KC_D),  _______,          _______,     _______,          _______,            RGB_TOG,      KC_MUTE,
        KC_TAB,   KC_Q,        KC_W,          KC_E,          KC_R,        KC_T,                     KC_Y,        KC_U,        KC_I,             KC_O,        KC_P,             _______,  _______,  _______,      KC_PGUP,
        _______,  KC_A,        KC_S,          KC_D,          KC_F,        KC_G,                     KC_H,        KC_J,        KC_K,             KC_L,        KC_QUOT,          _______,            _______,      KC_PGDN,
        _______,  KC_Z,        LOPT_T(KC_X),  LGUI_T(KC_C),  KC_V,        KC_B,        _______,     KC_N,        KC_M,        LGUI_T(KC_COMM),  KC_DOT,       CTL_T(KC_ENT),   _______,  KC_UP,
        _______,  _______,                    _______,       MO(SYMB),    KC_SPC,                   KC_LSFT,     MO(NUMB),    _______,                                     KC_LEFT,  KC_DOWN,  KC_RGHT),

    [SYMB] = LAYOUT_ansi_69(
        KC_ESC,   _______,  _______,       _______,       _______,   _______,               _______,  _______,   _______,          _______, _______,          _______,  _______,  _______,      KC_MUTE,
        KC_TAB,   KC_QUOT,  KC_DQUO,       KC_CIRC,       KC_QUES,   KC_GRAVE,              KC_LBRC,  KC_LT,     KC_EQL,           KC_GT,   KC_RBRC,          _______,  _______,  _______,      KC_PGUP,
        _______,  KC_EXLM,  KC_AT,         KC_HASH,       KC_DLR,    KC_PERC,               KC_LCBR,  KC_LPRN,   KC_COLN,          KC_RPRN, KC_RCBR,          _______,            _______,      KC_PGDN,
        _______,  KC_BSLS,  KC_TILD,       KC_PIPE,       KC_AMPR,   KC_SCLN,     _______,  KC_SLSH,  KC_ASTR,   KC_MINS,          KC_PLUS, KC_UNDS,          _______,  KC_UP,
        _______,  _______,                 _______,       MO(SYMB),  KC_SPC,                KC_LSFT,  MO(NUMB),  _______,                                     KC_LEFT,  KC_DOWN,  KC_RGHT),

    [NUMB] = LAYOUT_ansi_69(
        KC_ESC,   _______,  _______,       _______,       _______,   _______,               _______,  _______,   _______,          _______, _______,          _______,  _______,  _______,      KC_MUTE,
        KC_TAB,   KC_LCTL,  KC_LOPT,       KC_TRNS,       KC_TAB,    KC_TRNS,               KC_PGUP,  KC_HOME,   KC_END,           KC_PGDN, KC_VOLU,          _______,  _______,  _______,      KC_PGUP,
        _______,  KC_1,     KC_2,          KC_3,          KC_4,      KC_5,                  KC_LEFT,  KC_DOWN,   KC_UP,            KC_RGHT, KC_VOLD,          _______,            _______,      KC_PGDN,
        _______,  KC_6,     KC_7,          KC_8,          KC_9,      KC_0,        _______,  KC_ESC,   KC_TRNS,   KC_TRNS,          KC_TRNS, KC_MUTE,          _______,  KC_UP,
        _______,  _______,                 _______,       MO(SYMB),  KC_SPC,                KC_LSFT,  MO(NUMB),  _______,                                     KC_LEFT,  KC_DOWN,  KC_RGHT),

};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MCTL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;   // Process all other keycodes normally
    }
}

const uint16_t PROGMEM combo_lt[] = { KC_H, KC_J, COMBO_END };
const uint16_t PROGMEM combo_gt[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM combo_col[] = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM combo_esc[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM combo_tab[] = { KC_F, KC_G, COMBO_END };
const uint16_t PROGMEM combo_backspace[] = { KC_F, KC_D, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_lt, KC_LT),
  COMBO(combo_gt, KC_GT),
  COMBO(combo_col, KC_COLN),
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_backspace, KC_BSPC),
};
