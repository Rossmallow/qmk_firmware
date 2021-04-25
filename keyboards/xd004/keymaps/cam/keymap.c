#include QMK_KEYBOARD_H

enum custom_keycodes {
    ZOOM_DC = SAFE_RANGE,
    DTP_GAME,
    AT_ROSS,
    RASS,
    VC_IMG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Media Layer
    ┌─────┬─────┬─────┬─────┐
    │VolUp│VolDn│Mute │Play │
    └─────┴─────┴─────┴─────┘
    */
    [0] = LAYOUT_all(LT(1, KC_VOLU), LT(2, KC_VOLD), LT(3, KC_MUTE), LT(4, KC_MPLY)),

    /* 1: Browser Layer
    ┌─────┬─────┬─────┬─────┐
    │█████│Back │Forw │Refr │
    └─────┴─────┴─────┴─────┘
    */
    [1] = LAYOUT_all(KC_NO, KC_WBAK, KC_WFWD, KC_WREF),

    /* 2: Zoom Layer
    ┌─────┬─────┬─────┬─────┐
    │Mute │█████│Share│Leave│
    └─────┴─────┴─────┴─────┘
    */
    [2] = LAYOUT_all(A(KC_A), KC_NO, A(KC_S), ZOOM_DC),

    /* 3: Discord Layer 1
    ┌─────┬─────┬─────┬─────┐
    │Mute │Deaf │█████│@DTP │
    └─────┴─────┴─────┴─────┘
    */
    [3] = LAYOUT_all(RCS(KC_M), RCS(KC_D), KC_NO, DTP_GAME),

    /* 4: Discord Layer 2
    ┌─────┬─────┬─────┬─────┐
    │@Ross│rass │VcImg│█████│
    └─────┴─────┴─────┴─────┘
    */
    [4] = LAYOUT_all(AT_ROSS, RASS, VC_IMG, KC_NO)

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

    case RASS:
        if (record->event.pressed) {
            // when keycode RASS is pressed
            SEND_STRING(":rass:"SS_TAP(X_ENT));
        } else {
            // when keycode RASS is released
        }
        break;

    case VC_IMG:
        if (record->event.pressed) {
            // when keycode VC_IMG is pressed
            SEND_STRING("https://media.discordapp.net/attachments/772254514266636309/833510271137349652/784cbb4cac219173e21d2418a1d914e66bc739dedb1ec3cb758744944bfa32c4_1.png"SS_TAP(X_ENT));
        } else {
            // when keycode VC_IMG is released
        }
        break;
    }

    return true;
};
