// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Split keyboard communication
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN B6
#define SERIAL_USART_RX_PIN B7

// === TIMELESS HOMEROW MODS ===
// Match ZMK tapping-term-ms: 280
#define TAPPING_TERM 280

// Match ZMK quick-tap-ms: 175
#define QUICK_TAP_TERM 175

// Match ZMK require-prior-idle-ms: 150 (native Flow Tap)
#define FLOW_TAP_TERM 150

// Opposite-hand filtering (native Chordal Hold)
#define CHORDAL_HOLD

// === COMBO SETTINGS ===
#define COMBO_TERM 50
#define COMBO_STRICT_TIMER

// === ONE-SHOT SETTINGS ===
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 3000
