// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _SYM,
    _EXT,
    _FNC,
    _AERO,
    _SETT
};

// === HOMEROW MOD DEFINITIONS ===
// Left hand homerow mods
#define HM_S  LCTL_T(KC_S)   // S with Ctrl on hold
#define HM_D  LALT_T(KC_D)   // D with Alt on hold
#define HM_F  LGUI_T(KC_F)   // F with GUI on hold

// Right hand homerow mods (mirrored)
#define HM_J  RGUI_T(KC_J)   // J with GUI on hold
#define HM_K  RALT_T(KC_K)   // K with Alt on hold
#define HM_L  RCTL_T(KC_L)   // L with Ctrl on hold

// === THUMB KEY DEFINITIONS ===
#define EXT_TAB  LT(_EXT, KC_TAB)     // Hold=EXT layer, Tap=Tab
#define SYM_ENT  LT(_SYM, KC_ENT)     // Hold=SYM layer, Tap=Enter
#define FNC_ENT  LT(_FNC, KC_ENT)     // Hold=FNC layer, Tap=Enter (for EXT layer)
#define SFT_SPC  LSFT_T(KC_SPC)
#define SFT_BSPC  RSFT_T(KC_BSPC)

// === SHORTCUT DEFINITIONS ===
// GUI shortcuts (Cmd on macOS)
#define G_A     LGUI(KC_A)      // Select all
#define G_S     LGUI(KC_S)      // Save
#define G_Z     LGUI(KC_Z)      // Undo
#define G_X     LGUI(KC_X)      // Cut
#define G_C     LGUI(KC_C)      // Copy
#define G_V     LGUI(KC_V)      // Paste
#define G_T     LGUI(KC_T)      // New tab
#define G_ENT   LGUI(KC_ENT)    // GUI+Enter
#define G_BSP   LGUI(KC_BSPC)   // Delete word backward (macOS)
#define G_DEL   LGUI(KC_DEL)    // Delete word forward

#define AS_L LALT(LSFT(KC_LEFT))  // Alt+Shift+Left
#define AS_R LALT(LSFT(KC_RGHT))  // Alt+Shift+Right
#define GS_L LGUI(LSFT(KC_LEFT))  // Cmd+Shift+Left
#define GS_R LGUI(LSFT(KC_RGHT))  // Cmd+Shift+Right

// Ctrl+Shift combos
#define CS_LBRC LCTL(LSFT(KC_LBRC))  // Ctrl+Shift+[
#define CS_RBRC LCTL(LSFT(KC_RBRC))  // Ctrl+Shift+]

// Alt shortcuts
#define A_BSP   LALT(KC_BSPC)   // Alt+Backspace
#define A_DEL   LALT(KC_DEL)    // Alt+Delete

// AERO layer shortcuts (Alt+number for window management)
#define A_1     LALT(KC_1)
#define A_2     LALT(KC_2)
#define A_3     LALT(KC_3)
#define A_4     LALT(KC_4)
#define A_5     LALT(KC_5)
#define A_6     LALT(KC_6)
#define A_7     LALT(KC_7)
#define A_8     LALT(KC_8)
#define A_9     LALT(KC_9)
#define A_0     LALT(KC_0)
#define A_COMM  LALT(KC_COMM)
#define A_SLSH  LALT(KC_SLSH)
#define A_H     LALT(KC_H)
#define A_J     LALT(KC_J)
#define A_K     LALT(KC_K)
#define A_L     LALT(KC_L)

// Shift+Alt shortcuts
#define SA_1    LSFT(LALT(KC_1))
#define SA_2    LSFT(LALT(KC_2))
#define SA_3    LSFT(LALT(KC_3))
#define SA_4    LSFT(LALT(KC_4))
#define SA_5    LSFT(LALT(KC_5))
#define SA_6    LSFT(LALT(KC_6))
#define SA_7    LSFT(LALT(KC_7))
#define SA_8    LSFT(LALT(KC_8))
#define SA_9    LSFT(LALT(KC_9))
#define SA_0    LSFT(LALT(KC_0))

// One-shot mods for FNC layer
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)

// === CHORDAL HOLD LAYOUT ===
// Defines hand assignment for each matrix position.
// 'L' = left hand, 'R' = right hand, '*' = wildcard (thumb keys)
// Matrix: rows 0-3 = left half, rows 4-7 = right half
// Row 3 and 7 are thumb rows (3 keys + 3 unused)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

// === COMBO DEFINITIONS ===
enum combos {
    COMBO_SQT,        // U+I → Single quote
    COMBO_DQT,        // I+O → Double quote
    COMBO_GRV,        // ,+. → Grave
    COMBO_TILD,       // .+/ → Tilde
    COMBO_BSLS,       // M+, → Backslash
    COMBO_PIPE,       // M+. → Pipe
    COMBO_AERO,       //
    COMBO_SETT,       //
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM sqt_combo[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM dqt_combo[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM grv_combo[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM tild_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM aero_combo[] = {MO(_EXT), KC_ENT, COMBO_END};
const uint16_t PROGMEM sett_combo[] = {KC_TAB, MO(_EXT), COMBO_END};

combo_t key_combos[] = {
    [COMBO_SQT]  = COMBO(sqt_combo, KC_QUOT),
    [COMBO_DQT]  = COMBO(dqt_combo, LSFT(KC_QUOT)),
    [COMBO_GRV]  = COMBO(grv_combo, KC_GRV),
    [COMBO_TILD] = COMBO(tild_combo, LSFT(KC_GRV)),
    [COMBO_BSLS] = COMBO(bsls_combo, KC_BSLS),
    [COMBO_PIPE] = COMBO(pipe_combo, LSFT(KC_BSLS)),
    [COMBO_AERO] = COMBO(aero_combo, MO(_AERO)),
    [COMBO_SETT] = COMBO(sett_combo, MO(_SETT)),
};

// === KEYMAPS ===
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE Layer - QWERTY with Homerow Mods
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │CAPS │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │BSPC │  A  │S/CTL│D/ALT│F/GUI│  G  │   │  H  │J/GUI│K/ALT│L/CTL│  ;  │  '  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │ ENT │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ DEL │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │LSFT │T/EXT│ SPC │   │BSPC │E/SYM│RSFT │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_CAPS,
        KC_BSPC, KC_A,    HM_S,    HM_D,    HM_F,    KC_G,                               KC_H,    HM_J,    HM_K,    HM_L,    KC_SCLN, KC_QUOT,
        KC_ENT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_TAB, MO(_EXT), SFT_SPC,          SFT_BSPC, MO(_SYM), KC_ENT
    ),

    /*
     * SYM Layer - Numbers & Symbols
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │  ~  │  1  │  2  │  3  │  4  │  5  │   │  !  │  @  │  [  │  ]  │  %  │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │  `  │  6  │  7  │  8  │  9  │  0  │   │  ^  │  $  │  (  │  )  │  *  │  \  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  +  │  =  │  -  │  _  │  `  │   │  #  │  &  │  {  │  }  │  |  │     │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │     │     │   │     │█████│     │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PERC, KC_DEL,
        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR, KC_BSLS,
        _______, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, KC_GRV,                             KC_HASH, KC_AMPR, KC_LCBR, KC_RCBR, KC_PIPE, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    /*
     * EXT Layer - Navigation & Shortcuts
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │ ESC │CS-[ │ G-C │G-ENT│ G-T │   │PGUP │HOME │  ↑  │ END │CAPS │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ G-A │ G-S │ ALT │ GUI │ SFT │   │PGDN │  ←  │  ↓  │  →  │ DEL │ INS │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ G-Z │ G-X │ G-C │ G-V │CS-] │   │A-BSP│BSPC │G-BSP│G-DEL│A-DEL│     │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │█████│ CTL │   │ ENT │ FNC │     │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_EXT] = LAYOUT_split_3x6_3(
        _______, KC_ESC,  CS_LBRC, G_C,     G_ENT,   G_T,                                KC_PGUP, AS_L, KC_UP,   AS_R,  GS_L, GS_R,
        _______, G_A,     G_S,     KC_LALT, KC_LGUI, KC_LSFT,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME,  KC_END,
        _______, G_Z,     G_X,     G_C,     G_V,     CS_RBRC,                            A_BSP, G_BSP,   G_DEL,   A_DEL,   KC_INS, _______,
                                            _______, _______, KC_LCTL,          KC_BSPC,  MO(_FNC), MO(_AERO)
    ),

    /*
     * FNC Layer - Function Keys with One-Shot Mods
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │ F1  │ F2  │ F3  │ F4  │ F5  │   │ F6  │ F7  │ F8  │ F9  │ F10 │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │osSFT│osCTL│osALT│osGUI│RALT │   │ F11 │ F12 │     │     │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │   │     │     │     │     │     │     │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │     │     │   │     │█████│     │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_FNC] = LAYOUT_split_3x6_3(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, OS_SFT,  OS_CTL,  OS_ALT,  OS_GUI,  KC_RALT,                            KC_F11,  KC_F12,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    /*
     * AERO Layer - Window Management (Alt+numbers)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │ A-1 │ A-2 │ A-3 │ A-4 │ A-5 │   │SA-1 │SA-2 │SA-3 │SA-4 │SA-5 │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │ A-6 │ A-7 │ A-8 │ A-9 │ A-0 │   │SA-6 │SA-7 │SA-8 │SA-9 │SA-0 │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │ SFT │ A-, │ A-/ │   │ A-H │ A-J │ A-K │ A-L │     │     │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │     │     │   │     │     │     │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_AERO] = LAYOUT_split_3x6_3(
        _______, A_1,     A_2,     A_3,     A_4,     A_5,                                SA_1,    SA_2,    SA_3,    SA_4,    SA_5,    _______,
        _______, A_6,     A_7,     A_8,     A_9,     A_0,                                SA_6,    SA_7,    SA_8,    SA_9,    SA_0,    _______,
        _______, _______, _______, KC_LSFT, A_COMM,  A_SLSH,                             A_H,     A_J,     A_K,     A_L,     _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    ),

    /*
     * SETT Layer - Settings + Mouse
     * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │BOOT │     │     │     │     │   │     │WH_UP│MS_UP│     │BOOT │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │ CTL │ ALT │ GUI │     │   │     │MS_LT│MS_DN│MS_RT│     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │EECLR│     │     │     │     │   │     │WH_DN│WH_LT│WH_RT│EECLR│     │
     * └─────┴─────┴─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┴─────┴─────┘
     *                   │     │     │     │   │BTN1 │BTN2 │     │
     *                   └─────┴─────┴─────┘   └─────┴─────┴─────┘
     */
    [_SETT] = LAYOUT_split_3x6_3(
        _______, QK_BOOT, _______, _______, _______, _______,                            _______, MS_WHLU, MS_UP,   _______, QK_BOOT, _______,
        _______, _______, KC_LCTL, KC_LALT, KC_LGUI, _______,                            _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
        _______, EE_CLR,  _______, _______, _______, _______,                            _______, MS_WHLD, MS_WHLL, MS_WHLR, EE_CLR,  _______,
                                            _______, _______, _______,          MS_BTN1, MS_BTN2, _______
    )
};
