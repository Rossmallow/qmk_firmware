#include QMK_KEYBOARD_H

enum custom_keycodes {
    ZOOM_DC = SAFE_RANGE,
    AT_ROSS,
    DTP_GAME,
    MAC_DUF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Media Layer
    ┌─────┬─────┬─────┬─────┐
    │VolUp│VolDn│Mute │Play │
    └─────┴─────┴─────┴─────┘
    */
    [0] = LAYOUT_all(LT(1, KC_VOLU), LT(2, KC_VOLD), LT(3, KC_MUTE), LT(4, KC_MPLY)),

    /* 1: Discord Layer
    ┌─────┬─────┬─────┬─────┐
    │█████│Mute │Deaf │ GIF │
    └─────┴─────┴─────┴─────┘
    */
    [1] = LAYOUT_all(KC_NO, RCS(KC_M), RCS(KC_D), C(KC_G)),

    /* 2: Zoom Layer
    ┌─────┬─────┬─────┬─────┐
    │Mute │█████│Share│Leave│
    └─────┴─────┴─────┴─────┘
    */
    [2] = LAYOUT_all(A(KC_A), KC_NO, A(KC_S), ZOOM_DC),

    /* 3: Browser Layer
    ┌─────┬─────┬─────┬─────┐
    │Back │Forw │█████│Refr │
    └─────┴─────┴─────┴─────┘
    */
    [3] = LAYOUT_all(KC_WBAK, KC_WFWD, KC_NO, KC_WREF),

    /* 4: Meme Layer
    ┌─────┬─────┬─────┬─────┐
    │@DTP │@Ross│:mac:│█████│
    └─────┴─────┴─────┴─────┘
    */
    [4] = LAYOUT_all(DTP_GAME, AT_ROSS, MAC_DUF, KC_NO)

};

// Loop
void matrix_scan_user(void){
    // Empty
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ZOOM_DC:
        if (record->event.pressed) {
            // when keycode ZOOM_DC is pressed
            SEND_STRING(SS_LALT("q")SS_TAP(X_ENT));
        } else {
            // when keycode ZOOM_DC is released
        }
        break;

    case DTP_GAME:
        if (record->event.pressed) {
            // when keycode DTP_GAME is pressed
            SEND_STRING("@DTP"SS_TAP(X_TAB)" Game?"SS_TAP(X_ENT));
        } else {
            // when keycode DTP_GAME is released
        }
        break;

    case AT_ROSS:
        if (record->event.pressed) {
            // when keycode AT_ROSS is pressed
            SEND_STRING("@Rossmallow#4468"SS_TAP(X_ENT));
        } else {
            // when keycode AT_ROSS is released
        }
        break;

    case MAC_DUF:
        if (record->event.pressed) {
            // when keycode MAC_DUF is pressed
            SEND_STRING(":macduf:"SS_TAP(X_ENT));
        } else {
            // when keycode MAC_DUF is released
        }
        break;
    }
    return true;
};
