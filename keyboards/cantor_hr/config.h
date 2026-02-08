// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Split keyboard communication
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN B6
#define SERIAL_USART_RX_PIN B7

// VIA support
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// === TIMELESS HOMEROW MODS SETTINGS ===
// Match ZMK's tapping-term-ms: 280
#define TAPPING_TERM 280

// Match ZMK's quick-tap-ms: 175
// Also helps with require-prior-idle-ms behavior
#define QUICK_TAP_TERM 175

// ZMK hold-trigger-on-release equivalent
#define HOLD_ON_OTHER_KEY_PRESS

// Prevent accidental mods during fast typing (like require-prior-idle)
#define PERMISSIVE_HOLD

// Per-key tapping term for fine-tuning
#define TAPPING_TERM_PER_KEY

// === COMBO SETTINGS ===
#define COMBO_TERM 50
#define COMBO_STRICT_TIMER

// === ONE-SHOT SETTINGS (for FNC layer) ===
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 3000
