/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    CTL_SFT,
    SFT_CTL,
    GUI_LYR1
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [CTL_SFT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LSFT),
    [SFT_CTL] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_LCTL),
    [GUI_LYR1] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RGUI, 1)
};

/*
 * Ross' Corne Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: Default layer
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  '  │ Ent │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│Ctrl │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │Lyr 1│
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ Del │Bksp │ Esc │   │ Tab │Space│ Ent │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[0] = LAYOUT_split_3x6_3(
        KC_ESC,       KC_Q, KC_W,        KC_E,            KC_R,            KC_T,           KC_Y,           KC_U,           KC_I,          KC_O,        KC_P,    KC_DEL,
        KC_TAB,       KC_A, LT(5, KC_S), LT(4, KC_D),     LT(3, KC_F),     KC_G,           KC_H,           LT(3, KC_J),    LT(4, KC_K),   LT(5, KC_L), KC_QUOT, KC_ENT,
        TD(CTL_SFT), KC_Z, KC_X,        KC_C,            KC_V,            KC_B,           KC_N,           KC_M,           KC_COMM,       KC_DOT,      KC_SLSH, TD(GUI_LYR1),
                                         LALT_T(KC_DEL),  LSFT_T(KC_BSPC), LCTL_T(KC_ESC), RALT_T(KC_TAB), RCTL_T(KC_SPC), RGUI_T(KC_ENT)
),

/* 1: Game
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │  A  │  S  │  D  │  F  │  G  │   │  H  │  J  │  K  │  L  │  '  │ Ent │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │Lyr 0│
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │Space│Bksp │Lyr 2│   │ Tab │Space│ Ent │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[1] = LAYOUT_split_3x6_3(
        KC_TAB,       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT,      KC_TRNS, KC_S,    KC_D,     KC_F,    KC_TRNS,       KC_TRNS, KC_J,    KC_K,    KC_L,    KC_TRNS, KC_TRNS,
        TD(SFT_CTL), KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_SPC,   KC_TRNS, LT(2,KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS
),

/* 2: Game Numbers/Navigation
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Tab │  1  │ Up  │  2  │  3  │  T  │   │  Y  │  U  │  I  │  O  │  P  │ Del │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│Shift│Left │Down │Right│  4  │  G  │   │  H  │  J  │  K  │  L  │  '  │ Ent │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│Ctrl │  5  │  6  │  7  │  8  │  9  │   │  N  │  M  │  ,  │  .  │  /  │ Gui │
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │Space│Bksp │Lyr 1│   │ Tab │Space│ Ent │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[2] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_1,    KC_UP,   KC_2,    KC_3,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_4,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RGUI,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* 3: Numbers/Navigation
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│RESET│  [  │  9  │  8  │  7  │  ]  │   │PgUp │Home │ Up  │ End │ Ins │Bksp │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│NLock│  ;  │  6  │  5  │  4  │  =  │   │PgDn │Left │Down │Right│ Del │█████│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│█████│  `  │  3  │  2  │  1  │  \  │   │█████│█████│█████│█████│█████│█████│
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │  .  │  0  │  -  │   │ Tab │Space│ Ent │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[3] = LAYOUT_split_3x6_3(
        RESET,   KC_LBRC, KC_P9, KC_P8,   KC_P7, KC_RBRC, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS, KC_BSPC,
        KC_NLCK, KC_SCLN, KC_P6, KC_P5,   KC_P4, KC_EQL,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_NO,
        KC_NO,   KC_GRV,  KC_P3, KC_P2,   KC_P1, KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                                 KC_PDOT, KC_P0, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* 4: Symbols/Mouse
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│█████│  {  │  (  │  *  │  &  │  }  │   │MsWhU│Ms 1 │Ms Up│Ms 2 │Ms 4 │█████│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│Caps │  :  │  ^  │  %  │  $  │  +  │   │MsWhD│MsLft│MsDwn│MsRgh│Ms 5 │Ms 3 │
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│█████│  ~  │  #  │  @  │  !  │  |  │   │MsWhL│MsAc0│MsAc1│MsAc2│MsWhR│█████│
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │  (  │  )  │  _  │   │ Tab │Space│ Ent │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[4] = LAYOUT_split_3x6_3(
        KC_NO,   KC_LCBR, KC_LPRN, KC_ASTR, KC_AMPR, KC_RCBR, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN4, KC_BSPC,
        KC_CAPS, KC_COLN, KC_CIRC, KC_PERC, KC_DLR,  KC_PLUS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_BTN3,
        KC_NO,   KC_TILD, KC_HASH, KC_AT,   KC_EXLM, KC_PIPE, KC_WH_L, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_R, KC_NO,
                                   KC_LPRN, KC_RPRN, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* 5: Function/Media
┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
│█████│ F10 │ F9  │ F8  │ F7  │PrScn│   │RgbUp│RgbPv│VolUp│RgbNx│█████│█████│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│█████│ F11 │ F6  │ F5  │ F4  │ScLck│   │RgbDn│Prev │VolDn│Next │█████│█████│
├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
│█████│ F12 │ F3  │ F2  │ F1  │Pause│   │█████│█████│█████│█████│█████│RgbTg│
└─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │█████│█████│█████│   │Mute │Play │Stop │
                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
*/
[5] = LAYOUT_split_3x6_3(
        KC_NO, KC_F10, KC_F9, KC_F8, KC_F7, KC_PSCR, RGB_VAI, RGB_RMOD, KC_VOLU, RGB_MOD, KC_NO, KC_NO,
        KC_NO, KC_F11, KC_F6, KC_F5, KC_F4, KC_SLCK, RGB_VAD, KC_MPRV,  KC_VOLD, KC_MNXT, KC_NO, KC_NO,
        KC_NO, KC_F12, KC_F3, KC_F2, KC_F1, KC_PAUS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, RGB_TOG,
                              KC_NO, KC_NO, KC_NO,   KC_MUTE, KC_MPLY,  KC_MSTP
)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
