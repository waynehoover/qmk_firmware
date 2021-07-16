#include QMK_KEYBOARD_H

#include "keymap.h"
#include "caps_word.c"

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: DvorakIULM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  '   |   ,  |  .   |  p   |  y   |                              |   f  |  g   |  c   |   r  |   m  | ply/p  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  a   |   o  |  e   |  i   |  u   |                              |   d  |  h   |  t   |   n  |   s  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  :   |   q  |  j   |  k   |  x   |      |      |  |      |      |   b  |  l   |  w   |   v  |   z  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | lower| spc  | gui  |  |hy/ent| bsp  | raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
 *                                         low   spc                  gui/bsp? rai/ent?
 */
  [DVORAK] = LAYOUT(
    _______ , DV_QUOT  , DV_COMM , DV_DOT  , DV_P    , DV_Y   ,                                              DV_F   , DV_G    , DV_C    , DV_R , DV_M  , KC_MPLY ,
    _______ , DV_A     , DV_O    , DV_E    , DV_I    , DV_U   ,                                              DV_D   , DV_H    , DV_T    , DV_N , DV_S  , _______ ,
    _______ , SFT_COLN , DV_Q    , DV_J    , DV_K    , DV_X   , _______ , _______ ,      _______ , _______ , DV_B   , DV_L    , DV_W    , DV_V , SFT_Z , _______ ,
                                   _______ , _______ , MO_LOW , KC_SPC  , KC_LGUI ,      HYP_ENT , KC_BSPC , MO_RAI , _______ , _______
  ),
/*
 * Lower Layer: Parens and Nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |sw_app|sw_win|   {  |  }   |      |                              |wdcaps| WdLt | Up   | WdRt |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |os_alt|os_ctr|sh/(  |  )   |      |                              | caps | Left | Down | Right|launch|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |sw_tab|   [  |  ]   |      |      |      |  |      |      |      | LnBeg| DelWd| LnEnd| DelLi|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [LOWER] = LAYOUT(
    _______ , SW_APP  , SW_WIN  , DV_LCBR , DV_RCBR , _______ ,                                              WORDCAPS , WD_LFT  , KC_UP   , WD_RHT  , _______  , _______ ,
    _______ , OS_ALT  , OS_CTRL , SFT_PRN , DV_RPRN , _______ ,                                              KC_CAPS  , KC_LEFT , KC_DOWN , KC_RGHT , LAUNCH   , _______ ,
    _______ , _______ , SW_TAB  , DV_LBRC , DV_RBRC , _______ , _______ , _______ ,      _______ , _______ , _______  , LN_BEG  , DEL_WD  , LN_END  , HS_DELLI , _______ ,
                                  _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______  , _______ , _______
  ),
/*
 * Raise Layer: Number keys, punctuation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   !  |  @   |  ?   |  $   |  %   |                              |   ,  | 7    | 8    | 9    | -    |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   #  | +    | /    | =    | |    |                              |   .  | 0    | 1    | 2    | 3    |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ^  | &    | *    | _    |  \   |      |      |  |      |      |      | 4    | 5    | 6    | +    |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [RAISE] = LAYOUT(
    _______ , KC_EXLM , KC_AT   , DV_QUES , KC_DLR  , KC_PERC ,                                              DV_COMM , KC_7    , KC_8    , KC_9 , DV_MINS , _______ ,
    _______ , KC_HASH , DV_PLUS , DV_SLSH , DV_EQL  , KC_PIPE ,                                              DV_DOT  , KC_0    , KC_1    , KC_2 , KC_3    , _______ ,
    _______ , KC_CIRC , KC_AMPR , KC_ASTR , DV_UNDS , KC_BSLS , _______ , _______ ,      _______ , _______ , _______ , KC_4    , KC_5    , KC_6 , DV_PLUS , _______ ,
                                  _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______
  ),
/*
 * Adjust Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |  )   |   ]  |   }  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
  [ADJUST] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                                              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                              _______ , DV_RPRN , DV_RBRC , DV_RCBR , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                  _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______
  ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};


// left hand
// ,. -> ~
// .p -> `
// ,p -> copy * (dup)
// io -> copy
// jq -> esc
// jk -> tab
// kq -> cut *
// :q -> quit

// right hand
// gc -> -
// cr -> [blank]
// gr -> [blank] *
// hn -> paste
// lw -> tab left
// wv -> tab right
// vl -> paste * (dup)
// vz -> close window

enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5, CM_6, CM_7, CM_8, CM_9, CM_10, CM_11, CM_12, CM_13, CM_14, CM_15, CM_16 };

const uint16_t PROGMEM combo_0[] = {DV_Q, DV_J, COMBO_END};     // esc
const uint16_t PROGMEM combo_1[] = {DV_J, DV_K, COMBO_END};     // tab
const uint16_t PROGMEM combo_2[] = {DV_COMM, DV_DOT, COMBO_END};// ~
const uint16_t PROGMEM combo_3[] = {DV_DOT, DV_P, COMBO_END};   // `
const uint16_t PROGMEM combo_4[] = {DV_G, DV_C, COMBO_END};     // -
const uint16_t PROGMEM combo_5[] = {DV_L, DV_W, COMBO_END};     // move left tab
const uint16_t PROGMEM combo_6[] = {DV_W, DV_V, COMBO_END};     // move right tab
const uint16_t PROGMEM combo_7[] = {DV_I, DV_O, COMBO_END};     // copy
const uint16_t PROGMEM combo_8[] = {DV_H, DV_N, COMBO_END};     // paste
const uint16_t PROGMEM combo_9[] = {DV_COMM, DV_P, COMBO_END};  // copy
const uint16_t PROGMEM combo_10[] = {DV_L, DV_V, COMBO_END};    // paste
const uint16_t PROGMEM combo_11[] = {DV_Q, DV_K, COMBO_END};    // cut
const uint16_t PROGMEM combo_12[] = {SFT_COLN, DV_Q, COMBO_END};// quit
const uint16_t PROGMEM combo_13[] = {DV_V, DV_Z, COMBO_END};    // close window

const uint16_t PROGMEM combo_14[] = {KC_SPC, DV_A, COMBO_END};  // select all, cmd-a
const uint16_t PROGMEM combo_15[] = {DV_DOT, DV_E, COMBO_END};  // (
const uint16_t PROGMEM combo_16[] = {DV_P, DV_I, COMBO_END};  // )

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, KC_ESC),
  [CM_1] = COMBO(combo_1, KC_TAB),
  [CM_2] = COMBO(combo_2, KC_TILD),
  [CM_3] = COMBO(combo_3, KC_GRV),
  [CM_4] = COMBO(combo_4, DV_MINS),
  [CM_5] = COMBO(combo_5, G(A(KC_LEFT))),
  [CM_6] = COMBO(combo_6, G(A(KC_RIGHT))),
  [CM_7] = COMBO(combo_7, G(DV_C)),
  [CM_8] = COMBO(combo_8, G(DV_V)),
  [CM_9] = COMBO(combo_9, G(DV_C)),
 [CM_10] = COMBO(combo_10, G(DV_V)),
 [CM_11] = COMBO(combo_11, G(DV_X)),
 [CM_12] = COMBO(combo_12, G(DV_Q)),
 [CM_13] = COMBO(combo_13, G(DV_W)),
 [CM_14] = COMBO(combo_14, G(DV_A)),
 [CM_15] = COMBO(combo_15, DV_LPRN),
 [CM_16] = COMBO(combo_16, DV_RPRN),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case MO_LOW:
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
  case OSS_RAI:
  case SFT_ENT:
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
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
        }
    #endif

  const bool pressed = record->event.pressed;

  update_swapper(
    &sw_app_active, KC_LGUI, KC_TAB, SW_APP,
    keycode, record
  );
  update_swapper(
    &sw_win_active, KC_LGUI, KC_GRAVE, SW_WIN,
    keycode, record
  );
  update_swapper(
    &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB,
    keycode, record
  );

  update_oneshot(
    &os_shft_state, KC_LSFT, OS_SHFT,
    keycode, record
  );
  update_oneshot(
    &os_ctrl_state, KC_LCTL, OS_CTRL,
    keycode, record
  );
  update_oneshot(
    &os_alt_state, KC_LALT, OS_ALT,
    keycode, record
  );
  update_oneshot(
    &os_cmd_state, KC_LCMD, OS_CMD,
    keycode, record
  );

  // note: SEND_STRING and X_ codes use non dvorak-iu mapppings
  switch (keycode) {
    case UDELLIN:
        if (pressed){
            // ctrl-e, ctrl-shft-a, shft-left-arrow, gui-delete
            // which sends cursor to end of line, selects all from end of line to start of line,
            // selects the line break, then hits delete. This deletes the full line, with undo.
            SEND_STRING(SS_LCTRL("d")SS_LSFT(SS_LCTRL("a")SS_TAP(X_LEFT))SS_TAP(X_BSPC));
        }
        break;
    case WORDCAPS:
      if (pressed) return false;
      caps_word_toggle();
      return false;
    case OSS_RAI:
        if (record->tap.count > 0) {
            if (pressed) {
                set_oneshot_mods(MOD_LSFT);
            }
            return false;
        }
        break;
    case SFT_PRN:
        if (record->tap.count > 0) {
            if (pressed) {
                tap_code16(DV_LPRN);
            }
            return false;
        }
        break;
  }

  process_caps_word(keycode, record);
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

// send colon (z in qwerty) space, when shift held plus space is typed
// this simulates a colon rollover space on the colon/shift key
// bool colon_space(bool key_down, void *context) {
//     if (key_down) {
//         SEND_STRING("z ");
//     }
//     return false;
// }

// const key_override_t lsft_override = {.trigger_mods        = MOD_BIT(KC_LSFT),
//                                    .layers                 = ~0,
//                                    .suppressed_mods        = MOD_BIT(KC_LSFT),
//                                    .options                = ko_options_default,
//                                    .negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LSFT)),
//                                    .custom_action          = colon_space,
//                                    .context                = NULL,
//                                    .trigger                = KC_SPC,
//                                    .replacement            = KC_NO,
//                                    .enabled                = NULL};


// // send z (/ in qwerty) space, when shift held plus space is typed
// // this simulates a z rollover space on the colon/shift key
// bool z_space(bool key_down, void *context) {
//     if (key_down) {
//         SEND_STRING("/ ");
//     }
//     return false;
// }

// const key_override_t rsft_override = {.trigger_mods        = MOD_BIT(KC_RSFT),
//                                    .layers                 = ~0,
//                                    .suppressed_mods        = MOD_BIT(KC_RSFT),
//                                    .options                = ko_options_default,
//                                    .negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_RSFT)),
//                                    .custom_action          = z_space,
//                                    .context                = NULL,
//                                    .trigger                = KC_SPC,
//                                    .replacement            = KC_NO,
//                                    .enabled                = NULL};

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);

// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
// 	&delete_key_override,
//     &lsft_override,
//     // &rsft_override,
// 	NULL // Null terminate the array of overrides!
// };

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_RAI:
            // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 65;
        case SFT_Z:
            return TAPPING_TERM - 65;
        case SFT_COLN:
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
};

#ifdef ENCODER_ENABLE
// The F-keys are set software side for small increments of the volume and brigtness keys
void encoder_update_user(uint8_t index, bool clockwise) {
  switch (biton32(layer_state)) {
    case DVORAK:
    // volume
    if (clockwise) {
        if (get_mods() & MOD_MASK_GUI){
            tap_code(KC_F10);
        }else{
            tap_code(KC_VOLU);
        }
    } else {
        if (get_mods() & MOD_MASK_GUI){
            tap_code(KC_F9);
        }else{
            tap_code(KC_VOLD);
        }
    }
    break;
    case LOWER:
    // brightness
    if (clockwise) {
        if (get_mods() & MOD_MASK_GUI){
            tap_code(KC_F12);
        }else{
            tap_code(KC_BRIU);
        }
    } else {
        if (get_mods() & MOD_MASK_GUI){
            tap_code(KC_F11);
        }else{
            tap_code(KC_BRID);
        }
    }
    break;
    default: // RAISE
    // zoom
    if (clockwise) {
      register_code(KC_LGUI);
      tap_code(DV_MINS);
      unregister_code(KC_LGUI);
    } else {
      register_code(KC_LGUI);
      tap_code(DV_EQL);
      unregister_code(KC_LGUI);
    }
    break;
  }
}
#endif
