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
 * ,-----------------------------.      ,------------------------------------.
 * |  Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |   P        |
 * |-----+-----+-----+-----+-----|      |------------------------------------|
 * |  A  |  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |   "        | 
 * |-----+-----+-----+-----+-----|      |------------------------------------|
 * |  Z  |  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  | CTRL/ENTER |
 * `-----+-----+-----+-----+-----'      `------------------------------------'
 *      .----------------------.               .-------------------.   
 *      | CMD | SYM | SPC(HYP) |               | SHIFT | NAV | OPT |
 *      '----------------------'               '-------------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I,    KC_O,   KC_P, 
    KC_A, KC_S, KC_D, KC_F, KC_G,  	    KC_H, KC_J, KC_K,    KC_L, 	 KC_QUOT,
    KC_Z, KC_X, KC_C, KC_V, KC_B,  	    KC_N, KC_M, KC_COMM, KC_DOT, CTL_T(KC_ENT),

 		KC_LGUI, LT(SYMB, KC_NO), HYPR_T(KC_SPC), // Left
		MT(MOD_RSFT, KC_NO), LT(NUMB, KC_NO), KC_LALT   // Right
    ),

/* Keymap 1: Symbols layer
 *
 * ,-----------------------------.      ,-----------------------------.
 * |  '  |  "  |  ^  |  ?  |  `  |      |  [  |  <  |  =  |  >  |  ]  |
 * |-----------------------------|      |-----------------------------|
 * |  !  |  @  |  #  |  $  |  %  |      |  {  |  (  |  :  |  )  |  }  | 
 * |-----------------------------|      |-----------------------------|
 * |  \  |  ~  |  |  |  &  |  ;  |      |  /  |  *  |  -  |  +  |  _  |
 * `-----------------------------'      `-----------------------------'
 *  .-------------------------.           .-----------------.   
 *  |ESC/ALT|BSPC/META|SPC(SYM)|           |SPC(NUM)|HYPR|MEH|
 *  '-------------------------'           '-----------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRAVE,     KC_LBRC, KC_LT,   KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_LCBR, KC_LPRN, KC_COLN, KC_RPRN, KC_RCBR,
    KC_BSLS, KC_TILD, KC_PIPE, KC_AMPR, KC_SCLN,      KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_UNDS,  

                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Pad/Function layer
 * ,-----------------------------.      ,------------------------------------.
 * | CTRL | OPT |    | TAB |     |      | PGUP | HOME | END | PGDOWN | VOLUP |
 * |-----+-----+-----+-----+-----|      |------------------------------------|
 * |  1  |  2  |  3  |  4  |  5  |      | LFT  | DWN  | UP  | RGT    | VOLDN | 
 * |-----+-----+-----+-----+-----+      |------------------------------------|
 * |  6  |  7  |  8  |  9  |  0  |      | ESC  |      |     |        | MUTE  |
 * `-----+-----+-----+-----+-----'     	`------------------------------------'
 *          .-----------------.           .-----------------.   
 *          |     |    |      |           |     | PLY | SKP |
 *          '-----------------'           '-----------------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_LCTL, KC_LOPT, KC_TRNS, KC_TAB,  KC_TRNS,        KC_PGUP, KC_HOME, KC_END,  KC_PGDN, KC_VOLU,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD,
    KC_6,  	 KC_7, 	  KC_8,    KC_9,    KC_0,   	   KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,

                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    )
};
