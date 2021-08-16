/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |     |      |    LES   COLN  GRT    |        | 
 * |-----+-----+-----+--RMB+-LMB--+		   |--------------------------------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'		   `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |    Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |CTRL/A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; | 
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+-----+-----'      `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |ESC/ALT|BSPC/META|SPC(SYM)|           |SPC(NUM)|HYPR|MEH|
 *  '-------------------------'           '-----------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,               KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I,    KC_O,   KC_P, 
    MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K,    KC_L,   MT(MOD_RCTL, KC_SCLN),
    MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

      MT(MOD_LALT, KC_NO), MT(MOD_LGUI, KC_NO), LT(SYMB, KC_SPC),       LT(NUMB, KC_ENT), KC_HYPR, KC_MEH
    ),

/* Keymap 1: Symbols layer
 *
 * ,-----------------------------.      ,-----------------------------.
 * |  !  |  @  |  [  |  ]  |  ^  |      |  &  |  *  |  `  |  ~  |     |
 * |-----------------------------|      |-----------------------------|
 * |  +  |  -  |  (  |  )  |  =  |      |   ⃪  |  ↓  |  ⬆  |  →  |  \  | 
 * |-----------------------------|      |-----------------------------|
 * |  #  |  $  |  {  |  }  |  %  |      |     |     |     |     |  |  |
 * `-----------------------------'      `-----------------------------'
 *  .-------------------------.           .-----------------.   
 *  |ESC/ALT|BSPC/META|SPC(SYM)|           |SPC(NUM)|HYPR|MEH|
 *  '-------------------------'           '-----------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC,      KC_AMPR, KC_ASTR, KC_GRV,  KC_TILD, KC_BSLS,
    KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, KC_EQL,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE,
    KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PERC,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  

                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Pad/Function layer
 * ,------------------------------.      ,------------------------.
 * |     |     |     |     | VOLU |      | 7 | 8 | 9 |      |
 * |-----+-----+-----+-----+------|      |------------------------|
 * |     | ⏪ |  ⏯  | ⏭  | VOLD |      | 4 | 5 | 6 |      | 
 * |-----+-----+-----+-----+------+      |------------------------|
 * |     |     |     |     | MUTE |      | 1 | 2 | 3 |      |
 * `-----+-----+-----+-----+------'      `------------------------'
 *          .-----------------.           .----------.   
 *          |     |    |      |           |  | 0 |   |  
 *          '-----------------'           '----------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_VOLU, KC_7, KC_8, KC_9, KC_MPRV,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_VOLD, KC_4, KC_5, KC_6, KC_MPLY,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MUTE, KC_1, KC_2, KC_3, KC_MNXT,

                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_0
    )
};
