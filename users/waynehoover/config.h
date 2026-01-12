#pragma once

#define MASTER_LEFT

#undef TAPPING_TERM
#define TAPPING_TERM 111
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
// #define FLOW_TAP_TERM 100
// #define SPECULATIVE_HOLD

#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

#define FORCE_NKRO
#define QMK_KEYS_PER_SCAN 4
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */

#define COMBO_TERM 30 /* default is 50 */
#define COMBO_TERM_PER_COMBO
// #define COMBO_STRICT_TIMER
// #define COMBO_MUST_TAP_PER_COMBO

// #define SELECT_WORD_TIMEOUT 2000