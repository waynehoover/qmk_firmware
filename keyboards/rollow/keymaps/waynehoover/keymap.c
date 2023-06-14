#include QMK_KEYBOARD_H
#include "keymap_defines.h"

enum rollow_layers {
    DVORAKIL,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DVORAKIL] = LAYOUT_split_3x5_3( \
    DV_QUOT , DV_COMM , DV_DOT  , DV_P    , DV_Y    ,         DV_F    , DV_G    , DV_C    , DV_R    , DV_M     ,
    DV_A    , DV_O    , GUI_E   , SFT_I   , DV_U    ,         DV_D    , SFT_H   , DV_T    , DV_N    , DV_S     ,
    DV_COLN , DV_Q    , DV_J    , DV_K    , DV_X    ,         DV_B    , DV_L    , DV_W    , DV_V    , DV_Z     ,
                        KC_SLEP , MO_LOW  , HYP_SPC ,         KC_BSPC , RAI_ENT , KC_MPLY \
),

[LOWER] = LAYOUT_split_3x5_3( \
    SW_APP  , SW_WIN  , DV_LCBR , DV_RCBR , _______ ,         KC_CAPS , WD_LFT  , KC_UP   , WD_RHT  , _______  ,
    OS_ALT  , OS_CTRL , OS_SHFT , OS_CMD  , _______ ,         CW_TOGG , KC_LEFT , KC_DOWN , KC_RGHT , LAUNCH   ,
    _______ , SW_TAB  , DV_LBRC , DV_RBRC , _______ ,         _______ , LN_BEG  , DEL_WD  , LN_END  , HS_DELLI ,
                        _______ , _______ , _______ ,         _______ , _______ , _______
),

[RAISE] = LAYOUT_split_3x5_3( \
    KC_EXLM , KC_AT   , DV_QUES , KC_DLR  , KC_PERC ,         _______ , KC_7    , KC_8    , KC_9    , _______  ,
    KC_HASH , DV_PLUS , DV_SLSH , DV_EQL  , KC_PIPE ,         _______ , KC_0    , KC_1    , KC_2    , KC_3     ,
    KC_CIRC , KC_AMPR , KC_ASTR , DV_UNDS , KC_BSLS ,         _______ , KC_4    , KC_5    , KC_6    , _______  ,
                        _______ , _______ , _______ ,         _______ , _______ , _______
)
};


// ** combos left hand **
// ', -> f16 (hs opt click)
// ,p -> select all
// ,. -> esc
// .p -> tab

// ao -> f15 (hs cmd click)
// io -> copy
// oe -> )
// ei -> (

// :q -> quit*
// qk -> cut
// qj -> ~
// jk -> `
// kx -> play/pause

// ** combos right hand **
// gr -> [blank]
// gc -> -
// cr -> [blank]

// hn -> paste
// tn -> [blank]
// th -> [blank]

// lw -> tab left
// wv -> tab right
// vz -> close window*

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6, CM_7, CM_8, CM_8a, CM_9, CM_11, CM_10, CM_12, CM_13, CM_14, CM_15, CM_16, CM_17, CM_18, CM_19 };

const uint16_t PROGMEM c_esc[]    = {DV_COMM, DV_DOT, COMBO_END};   // esc
const uint16_t PROGMEM c_tab[]    = {DV_DOT, DV_P, COMBO_END};      // tab
const uint16_t PROGMEM c_tild[]   = {DV_J, DV_Q, COMBO_END};        // z
const uint16_t PROGMEM c_grv[]    = {DV_J, DV_K, COMBO_END};        // `
const uint16_t PROGMEM c_mins[]   = {DV_G, DV_C, COMBO_END};        // -
const uint16_t PROGMEM combo_5[]  = {DV_L, DV_W, COMBO_END};        // move left tab
const uint16_t PROGMEM combo_6[]  = {DV_W, DV_V, COMBO_END};        // move right tab
const uint16_t PROGMEM combo_7[]  = {SFT_I, DV_O, COMBO_END};       // copy
const uint16_t PROGMEM f_16[]     = {DV_COMM, DV_QUOT, COMBO_END};  // f16
const uint16_t PROGMEM f_15[]     = {DV_A, DV_O, COMBO_END};        // f15
const uint16_t PROGMEM c_play[]   = {DV_K, DV_X, COMBO_END};        // play/pause
const uint16_t PROGMEM combo_9[]  = {DV_COMM, DV_P, COMBO_END};     // select all
const uint16_t PROGMEM hs_hypr[]  = {SFT_H, DV_T, DV_N, COMBO_END}; // hammerspon hyper TO layer
const uint16_t PROGMEM combo_11[] = {DV_Q, DV_K, COMBO_END};        // cut
const uint16_t PROGMEM combo_12[] = {DV_COLN, DV_Q, COMBO_END};     // quit
const uint16_t PROGMEM combo_13[] = {DV_V, SFT_Z, COMBO_END};       // close window
const uint16_t PROGMEM c_paste[]  = {SFT_H, DV_N, COMBO_END};       // paste

const uint16_t PROGMEM c_tolow[]  = {DV_O, GUI_E, SFT_I, COMBO_END}; // TO(lower)
const uint16_t PROGMEM combo_15[] = {DV_O, GUI_E, COMBO_END};        // (
const uint16_t PROGMEM combo_16[] = {GUI_E, SFT_I, COMBO_END};       // )

const uint16_t PROGMEM c_ent[]    = {DV_G, DV_C, COMBO_END};               // duplicate of -
const uint16_t PROGMEM c_tolow2[] = {OS_CTRL, OS_SHFT, OS_CMD, COMBO_END}; // TO(lower)

combo_t key_combos[] = {
    [CM_0] = COMBO(c_esc, KC_ESC),
    [CM_1] = COMBO(c_tab, KC_TAB),
    [CM_2] = COMBO(c_tild, KC_TILD),
    [CM_3] = COMBO(c_grv, KC_GRV),
    [CM_4] = COMBO(c_mins, DV_MINS),
    [CM_5] = COMBO(combo_5, G(A((KC_LEFT)))),
    [CM_6] = COMBO(combo_6, G(A(KC_RIGHT))),
    //[CM_6] = COMBO(combo_6, KC_ENT),
    [CM_7]  = COMBO(combo_7, G(DV_C)),
    [CM_8]  = COMBO(f_16, KC_F16),
    [CM_8a] = COMBO(f_15, KC_F15),
    [CM_9]  = COMBO(combo_9, G(DV_A)),
    [CM_10] = COMBO(hs_hypr, HS_HYP),
    [CM_11] = COMBO(combo_11, G(DV_X)),
    [CM_12] = COMBO(combo_12, G(DV_Q)),
    [CM_13] = COMBO(combo_13, G(DV_W)),
    [CM_14] = COMBO(c_play, KC_MPLY),
    [CM_15] = COMBO(combo_15, DV_LPRN),
    [CM_16] = COMBO(combo_16, DV_RPRN),
    [CM_17] = COMBO(c_paste, G(DV_V)),
    [CM_18] = COMBO(c_tolow, TOGGLE_LOWER),
    [CM_19] = COMBO(c_tolow2, TOGGLE_LOWER),
    //[CM_19] = COMBO(c_ent, KC_ENT),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case MO_LOW:
        case F19_RAI:
        case KC_SPC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case MO_LOW:
        case MO_RAI:
        // case RAI_ENT:
        case LOW_TAB:
        case F19_RAI:
        case OSS_RAI:
        case SFT_ENT:
        case OS_SFT:
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

// send shift then enter on shift-backspace
const key_override_t sft_ent_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, LSFT(KC_ENT));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &sft_ent_key_override,
    NULL // Null terminate the array of overrides!
};

// set trystate
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
// }

// Per key tapping term settings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // low tapping term to make sure I don't activate the tap version accidentally.
    // high tapping term to make sure I don't active the hold version accidentally.
    switch (keycode) {
        case SFT_Te:
            return TAPPING_TERM + 35;
        case RAI_ENT:
            return TAPPING_TERM - 35;
        case LOW_TAB:
            return TAPPING_TERM - 10;
        case SFT_Z:
            return TAPPING_TERM - 10;
        case SFT_COLN:
            return TAPPING_TERM - 15;
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



#ifdef OLED_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
//     };

//     oled_write_P(qmk_logo, false);
// }

// static void print_status_narrow(void) {
//     // Print current mode
//     oled_write_P(PSTR("\n\n"), false);
//     oled_write_ln_P(PSTR("MODE"), false);
//     oled_write_ln_P(PSTR(""), false);
//     if (keymap_config.swap_lctl_lgui) {
//         oled_write_ln_P(PSTR("MAC"), false);
//     } else {
//         oled_write_ln_P(PSTR("WIN"), false);
//     }

//     switch (get_highest_layer(default_layer_state)) {
//         case DVORAKIL:
//             oled_write_ln_P(PSTR("Base"), false);
//             break;
//         default:
//             oled_write_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     // Print current layer
//     oled_write_ln_P(PSTR("LAYER"), false);
//     switch (get_highest_layer(layer_state)) {
//         case DVORAKIL:
//             oled_write_P(PSTR("Base\n"), false);
//             break;
//         case RAISE:
//             oled_write_P(PSTR("Raise"), false);
//             break;
//         case LOWER:
//             oled_write_P(PSTR("Lower"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n"), false);
//     led_t led_usb_state = host_keyboard_led_state();
//     oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;
//     }
//     return rotation;
// }

bool oled_task_user(void) {
    oled_off();
    // if (is_keyboard_master()) {
    //     print_status_narrow();
    // } else {
    //     render_logo();
    // }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_BRID);
        } else {
            tap_code(KC_BRIU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}

#endif
