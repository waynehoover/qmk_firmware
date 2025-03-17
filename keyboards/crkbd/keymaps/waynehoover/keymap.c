// qmk flash -c -kb crkbd -km waynehoover -e CONVERT_TO=promicro_rp2040

#include QMK_KEYBOARD_H
#include "../../../users/waynehoover/keymap_defines.h"

enum ferris_layers {
  DVORAKIL,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAKIL] = LAYOUT_split_3x6_3(
    _______ , DV_QUOT , DV_COMM , DV_DOT  , DV_P    , DV_Y    ,         DV_F    , DV_G    , DV_C    , DV_R    , DV_M     , _______ ,
    _______ , DV_A    , DV_O    , GUI_E   , IDX_L   , DV_U    ,         DV_D    , IDX_R   , DV_T    , DV_N    , DV_S     , _______ ,
    _______ , DV_COLN , DV_Q    , DV_J    , DV_K    , DV_X    ,         DV_B    , DV_L    , DV_W    , DV_V    , DV_Z     , _______ ,
                                  _______ , THB_L2  , THB_L1  ,         THB_R1  , THB_R2  , TOG_MIC
  ),

  [LOWER] = LAYOUT_split_3x6_3(
    _______ , SW_APP  , SW_WIN  , DV_LCBR , DV_RCBR , _______ ,         FND_ALL , WD_LFT  , KC_UP   , WD_RHT  , _______  , _______ ,
    _______ , OS_ALT  , OS_CTRL , OS_SHFT , OS_CMD  , _______ ,         CW_TOGG , KC_LEFT , KC_DOWN , KC_RGHT , TOG_COMM , _______ ,
    _______ , _______ , SW_TAB  , DV_LBRC , DV_RBRC , _______ ,         _______ , LN_BEG  , DEL_WD  , LN_END  , DEL_LINE , _______ ,
                                  _______ , _______ , _______ ,         _______ , _______ , _______
  ),

  [RAISE] = LAYOUT_split_3x6_3(
    _______ , KC_EXLM , KC_AT   , DV_QUES , KC_DLR  , KC_PERC ,         _______ , KC_7    , KC_8    , KC_9    , _______  , _______ ,
    _______ , KC_HASH , DV_PLUS , DV_SLSH , DV_EQL  , KC_PIPE ,         _______ , KC_0    , KC_1    , KC_2    , KC_3     , _______ ,
    _______ , KC_CIRC , KC_AMPR , KC_ASTR , DV_UNDS , KC_BSLS ,         _______ , KC_4    , KC_5    , KC_6    , _______  , _______ ,
                                  _______ , _______ , _______ ,         _______ , _______ , _______
  )
};

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

bool sw_app_active = false;
bool sw_win_active = false;
bool sw_tab_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
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

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case THB_L2:
        case THB_L1:
        case THB_R1:
        case THB_R2:
            return true;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    // case MOD_LSFT:
    case MOD_LALT:
    case MOD_LGUI:
    // case MOD_RSFT:
    case MOD_RALT:
    case MOD_RGUI:
      return true;  // Eagerly apply Alt Gui mods.

    default:
      return false;
  }
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 125;  // A longer timeout otherwise. or same...
  }
}

bool achordion_streak_continue(uint16_t keycode) {
  // If mods other than shift or AltGr are held, don't continue the streak.
  if (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) return false;
  // This function doesn't get called for holds, so convert to tap keycodes.
  if (IS_QK_MOD_TAP(keycode)) {
    keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
  }
  if (IS_QK_LAYER_TAP(keycode)) {
    keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
  }
  // Regular letters and punctuation continue the streak. (modified for dvorakiulm layout)
  if (keycode >= KC_A && keycode <= KC_X) return true;
  switch (keycode) {
    case DV_W:
    case DV_V:
    case DV_S:
    case DV_Z:
    case KC_SPACE:
    case THB_L1:
      return true;
  }
  return false;  // All other keys end the streak.
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

// https://docs.qmk.fm/ChangeLog/20240825#key-override-keymap-c-signature-change-24120
// send enter on shift-backspace (not working... didnt investigate)
// const key_override_t sft_bspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_ENT);

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &sft_bspc_key_override,
//     NULL // Null terminate the array of overrides!
// };

// set trystate
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
// }

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
        case ALT_O:
        case GUI_E:
        case SFT_I:
            return TAPPING_TERM; // was - 10
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