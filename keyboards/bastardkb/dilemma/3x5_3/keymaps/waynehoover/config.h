#pragma once

// Configure the global tapping term (default: 200ms)
#undef TAPPING_TERM
#define TAPPING_TERM 100
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// See https://github.com/qmk/qmk_firmware/blob/155cc17359711a6dd7b67119ec994800588ebaaa/docs/tap_hold.md#hold-on-other-key-press
// #define HOLD_ON_OTHER_KEY_PRESS
// Holding a dual function key without hitting another key will send the orginal keycode
// #define RETRO_TAPPING

// #define BILATERAL_COMBINATIONS

#define TAPPING_TERM_PER_KEY

#define FORCE_NKRO
#define QMK_KEYS_PER_SCAN 4
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */

#define COMBO_TERM 30 /* default is 50 */
#define COMBO_TERM_PER_COMBO
// #define COMBO_STRICT_TIMER
// #define COMBO_MUST_TAP_PER_COMBO
