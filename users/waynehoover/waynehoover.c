#include "waynehoover.h"

// Swapper state
bool sw_app_active = false;
bool sw_win_active = false;
bool sw_tab_active = false;

// Oneshot state
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case THB_L2:
        // case THB_R2:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case THB_L2:
        case THB_L1:
        case THB_R1:
        case THB_R2:
        //case OS_SFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_sentence_case(keycode, record)) { return false; }
    const bool pressed = record->event.pressed;

    update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
    update_swapper(&sw_win_active, KC_LGUI, KC_GRAVE, SW_WIN, keycode, record);
    update_swapper(&sw_tab_active, KC_LCTL, KC_TAB, SW_TAB, keycode, record);

    update_oneshot(&os_shft_state, KC_RSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_RCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_RALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_RCMD, OS_CMD, keycode, record);

    // note: SEND_STRING and X_ codes use non dvorak-iu mapppings
    switch (keycode) {
        case SFT_PRN:
            if (record->tap.count > 0) {
                if (pressed) {
                    tap_code16(DV_LPRN);
                }
                return false;
            }
            break;
        case TOGGLE_LOWER:
            if (record->event.pressed) toggle_lower_layer();
            return false;
        case SEND_TH:
            if (record->event.pressed) SEND_STRING("kj"); // th in dvorak-iu
            return false;
        case SEND_THE:
            if (record->event.pressed) SEND_STRING("kjd"); // the in dvorak-iu
            return false;
    }
    return true;
}

// this instead of TO(LOWER) so that I can have a visual indicator in hammerspoon by sending the F18 and F17 keys
void toggle_lower_layer() {
    if (IS_LAYER_ON(LOWER)) {
        layer_off(LOWER);
        tap_code16(KC_F18);
    } else {
        layer_on(LOWER);
        tap_code16(KC_F17);
    }
}

// Per key tapping term settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // low tapping term to make sure I don't activate the tap version accidentally.
    // high tapping term to make sure I don't active the hold version accidentally.
    switch (keycode) {
        case THB_L1:
        case THB_R1:
            return TAPPING_TERM + 25;
        case THB_L2:
        case THB_R2:
            return TAPPING_TERM - 5;
        case SFT_I:
        case SFT_H:
            return TAPPING_TERM - 25; // Faster shift activation
        case ALT_O:
        case GUI_E:
            return TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
};

// Per comobo combo term settings
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case CM_14: // KC_ENT
            return COMBO_TERM - 15;
    }

    return COMBO_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case DV_Z:
    case THB_R1:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

// Does not seem to be working/on right now?
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning true means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    // Repeating Z is useful for spamming undo.
    case DV_Z:
      return false;  // Enable key repeating.
    default:
      return true;  // Otherwise, force hold and disable key repeating.
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // include keys where dvorak is symbols and not keys where qwerty is letters
        case DV_W:
        case DV_V:
        case DV_Z:
        case DV_S:
        case KC_A ... KC_D: // not eqwz in qwerty
        case KC_F ... KC_P:
        case KC_R ... KC_V:
        case KC_X ... KC_Y:
        case DV_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DV_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) { // These keys may be speculatively held.
        case GUI_E:
        case IDX_L:
        case IDX_R:
            return true;
    }
    return false; // Disable otherwise.
}
