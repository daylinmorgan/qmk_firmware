#include QMK_KEYBOARD_H
#include "keycodes.h"
#include <stdio.h>

#ifdef OLED_ENABLE
#    include "oled.c"
#endif


enum combos {
  JK_ESC,

  RM_BSLASH,
  VU_SLSH,

  RT_LPRN,
  YU_RPRN,

  FG_LPRN,
  HJ_RPRN,

  VB_LCBR,
  NM_RCBR
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM rm_combo[] = {KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM vu_combo[] = {KC_V, KC_U, COMBO_END};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};

const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {

  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),

  // a line between the R & M positions draws a back slash
  [RM_BSLASH] = COMBO(rm_combo, KC_BSLASH),

  // a line between the V & U positions draws a forward slash
  [VU_SLSH]   = COMBO(vu_combo, KC_SLSH),

  // Brackets combos are pressed with a single finger in between two keys
  [RT_LPRN]   = COMBO(rt_combo, KC_LBRC),
  [YU_RPRN]   = COMBO(yu_combo, KC_RBRC),

  // Parens are pressed with a single finger between F&J or H&J
  [FG_LPRN]   = COMBO(fg_combo, KC_LPRN),
  [HJ_RPRN]   = COMBO(hj_combo, KC_RPRN),

  // Curly Braces are pressed with a single figure between two keys
  [VB_LCBR]   = COMBO(vb_combo, KC_LCBR),
  [NM_RCBR]   = COMBO(nm_combo, KC_RCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                   ,-----------------------------------------------------.
        KC_GRV, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                     XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS, KC_EQL,
   //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
       KC_LCTL, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,                     KC_BSLS,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------|
       KC_LSFT, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                    KC_PIPE,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_RALT,
   //|--------+--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI,   MO(3),  KC_SPC,    KC_ENT, _______, KC_0
                                       //`--------------------------' `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                        KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                        KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
        is_key_processed = true;
        add_keylog(keycode);
    }
#endif
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
   }
    return true;
}
