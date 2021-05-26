// from https://github.com/precondition/dactyl-manuform-keymap/blob/main/tapdance.c thanks!

#include QMK_KEYBOARD_H

#include "keymap.h"

// Tap dance states
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// function to track the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// track the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
    } else {
        return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
      return DOUBLE_SINGLE_TAP;
  }
  else {
      return 3; // any number higher than the maximum state value you return above
  }
};

// `finished` function for each tapdance keycode
void CA_CC_CV_finished (qk_tap_dance_state_t *state, void *user_data);

// handle the possible states for each tapdance keycode you define:

void CA_CC_CV_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      tap_code16(G(DV_C));
      break;
    case SINGLE_HOLD:
      tap_code16(G(DV_A));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(G(DV_V));
  }
};

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(DV_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap.
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(DV_DOT);
            // tap the third dot
            tap_code(DV_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(DV_DOT);
    }
};

void cmd_q(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      tap_code16(DV_Q);
  }
  if (state->count == 2) {
      tap_code16(G(DV_Q));
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CA_CC_CV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CA_CC_CV_finished, NULL),
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
    [TD_Q_QUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cmd_q, NULL)
};
