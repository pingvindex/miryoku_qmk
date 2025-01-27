#include QMK_KEYBOARD_H

enum custom_keycodes {
    LNG_SW = SAFE_RANGE,
    RUBLE,
    CPRGHT,
    DEGREE,
    GRTSGN,
    PLSMNS,
    SCRCUT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LNG_SW:
        if (record->event.pressed) {
            // when keycode LNG_SW is pressed
            SEND_STRING(SS_LGUI(SS_TAP(X_SPC)));
        } else {
            // when keycode LNG_SW is released
        }
        break;

    case RUBLE:
        if (record->event.pressed) {
            // when keycode RUBLE is pressed
            SEND_STRING(SS_RALT(SS_TAP(X_8)));
        } else {
            // when keycode RUBLE is released
        }
        break;

    case CPRGHT:
        if (record->event.pressed) {
            // when keycode CPRGHT is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_9)));
        } else {
            // when keycode CPRGHT is released
        }
        break;

    case DEGREE:
        if (record->event.pressed) {
            // when keycode DEGREE is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
        } else {
            // when keycode DEGREE is released
        }
        break;

    case GRTSGN:
        if (record->event.pressed) {
            // when keycode GRTSGN is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_6) SS_TAP(X_KP_2)));
        } else {
            // when keycode GRTSGN is released
        }
        break;

    case PLSMNS:
        if (record->event.pressed) {
            // when keycode PLSMNS is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_7)));
        } else {
            // when keycode PLSMNS is released
        }
        break;

    case SCRCUT:
        if (record->event.pressed) {
            // when keycode SCRCUT is pressed
            SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
        } else {
            // when keycode SCRCUT is released
        }
        break;

        }
    return true;
};

#define KC_LG_RBR LGUI_T(KC_RBRC)
#define KC_LC_GRV LCTL_T(KC_GRV)
#define KC_LA_BCL LALT_T(KC_BSLS)

#define KC_RG_LBR RGUI_T(KC_LBRC)
#define KC_RC_QUO RCTL_T(KC_QUOT)
#define KC_RA_MIN RALT_T(KC_MINUS)

#define KC_LS_TAB LSFT_T(KC_TAB)
#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L2_ENT LT(2,KC_ENT)

#define KC_L1_ESC LT(1,KC_ESC)
#define KC_RS_BSP RSFT_T(KC_BSPC)
#define KC_RS_DEL RSFT_T(KC_DEL)

#define KC_LA_EQL LALT_T(KC_EQL)

#define KC_L3_TAB LT(3, KC_TAB)
#define KC_L3_DEL LT(3, KC_DEL)

#define KC_L3_ENT LT(3,KC_ENT)
#define KC_L3_ESC LT(3,KC_ESC)

#define KC_F_LBRC LSFT(KC_LBRC)
#define KC_F_RBRC LSFT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
   KC_LG_RBR ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,                                       KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,KC_RG_LBR ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LC_GRV ,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,                                       KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,  KC_SCLN ,KC_RC_QUO ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_BCL ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,                                       KC_N   ,   KC_M   ,  KC_COMM ,   KC_DOT,   KC_SLSH ,KC_RA_MIN ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                               KC_LS_TAB ,   KC_SPC , KC_L2_ENT,              KC_L1_ESC ,  KC_BSPC ,  KC_RS_DEL
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[1] = LAYOUT_split_3x6_3(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
    KC_LGUI  ,    KC_1  ,   KC_2   ,   KC_3   ,   KC_4   ,     KC_5 ,                                     KC_EXLM  ,  KC_AT   , KC_HASH  ,  KC_DLR  , KC_PERC  , KC_RGUI  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    KC_LCTL  ,    KC_6  ,   KC_7   ,   KC_8   ,   KC_9   ,    KC_0  ,                                     KC_CIRC  ,  KC_AMPR ,  KC_LPRN , KC_RPRN  , KC_ASTR  , KC_RCTL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LA_EQL , KC_PSLS  , KC_PAST  , KC_PMNS  , KC_PPLS  , KC_PDOT  ,                                     KC_LBRC  , KC_RBRC  ,KC_F_LBRC ,KC_F_RBRC , KC_BSLS  , KC_RALT  ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                                _______  , _______  , KC_L3_ENT,               _______  , _______  , _______
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[2] = LAYOUT_split_3x6_3(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
    KC_LGUI  ,  KC_F1   ,  KC_F2   ,  KC_F3   ,  KC_F4   ,  KC_CAPS ,                                     KC_WH_U  , KC_HOME  ,  KC_UP ,  KC_PGUP , KC_VOLU  , KC_RGUI  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    KC_LCTL  ,  KC_F5   ,  KC_F6   ,  KC_F7   ,  KC_F8   ,  KC_APP ,                                     _______  , KC_LEFT  ,  KC_DOWN   ,  KC_RGHT , KC_VOLD  , KC_RCTL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
   KC_LALT  ,  KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  ,  LNG_SW ,                                     KC_WH_D  , KC_END   ,  SCRCUT  ,  KC_PGDN , KC_MUTE  , KC_RALT  ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                                _______  , _______  ,  _______ ,              KC_L3_ESC , _______  , _______
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[3] = LAYOUT_split_3x6_3(
//┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
    KC_LGUI  ,   RESET  ,   KC_P7  ,   KC_P8  ,   KC_P9  , KC_NUM_LOCK,                            KC_SCROLL_LOCK  ,  KC_BTN1 ,  KC_MS_U ,  KC_BTN2 ,  RESET   , KC_RGUI  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    KC_LCTL  ,  KC_PENT ,   KC_P4  ,   KC_P5  ,   KC_P6  ,  TO(1)   ,                                     KC_PAUS  ,  KC_MS_L ,  KC_MS_D ,  KC_MS_R ,  KC_INS  , KC_RCTL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
    KC_LALT  ,   KC_P0  ,   KC_P1  ,   KC_P2  ,   KC_P3  ,  TO(2)   ,                                       KC_NO  ,  KC_WH_D ,  KC_WH_U ,  KC_BTN3 ,  KC_PSCR , KC_RALT  ,
//└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘
                                                _______  , KC_LSFT  , _______  ,               _______  , KC_RSFT  , _______
                                           // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
)
};
