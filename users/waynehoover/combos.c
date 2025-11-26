// ** combos left hand **
// ', -> ___
// ,p -> select all
// ,. -> esc
// .p -> tab

// ao -> ___
// io -> copy
// oe -> )
// ei -> (

// :q -> quit*
// qk -> cut
// qj -> ~
// jk -> `
// kx -> ___

// ** combos right hand **
// gr -> ___
// gc -> - (change to ` but need to make - redudant somewhere)
// cr -> ___

// hn -> paste
// tn -> f19 (hammerspoon leader)
// ht -> th
// ns -> LOCK_WIS

// lw -> tab left
// wv -> tab right
// vz -> close window*

const uint16_t PROGMEM c_esc[]    = {DV_COMM, DV_DOT, COMBO_END};   // esc
const uint16_t PROGMEM c_tab[]    = {DV_DOT, DV_P, COMBO_END};      // tab
const uint16_t PROGMEM c_tild[]   = {DV_J, DV_Q, COMBO_END};        // ~
const uint16_t PROGMEM c_grv[]    = {DV_J, DV_K, COMBO_END};        // `
const uint16_t PROGMEM c_mins[]   = {DV_G, DV_C, COMBO_END};        // -
const uint16_t PROGMEM combo_5[]  = {DV_L, DV_W, COMBO_END};        // move left tab
const uint16_t PROGMEM combo_6[]  = {DV_W, DV_V, COMBO_END};        // move right tab
const uint16_t PROGMEM combo_7[]  = {IDX_L, DV_O, COMBO_END};       // copy
const uint16_t PROGMEM f_16[]     = {DV_COMM, DV_QUOT, COMBO_END};  // f16
const uint16_t PROGMEM f_15[]     = {DV_A, DV_O, COMBO_END};        // f15
const uint16_t PROGMEM c_play[]   = {DV_K, DV_X, COMBO_END};        // play/pause
const uint16_t PROGMEM combo_9[]  = {DV_COMM, DV_P, COMBO_END};     // select all
const uint16_t PROGMEM combo_10[] = {DV_S, DV_N, COMBO_END};        // LOCK_WIS
const uint16_t PROGMEM f_19b[]    = {DV_T, DV_N, COMBO_END};        // f19
const uint16_t PROGMEM lock_wis[] = {DV_A, DV_O, COMBO_END};        // LOCK_WIS
const uint16_t PROGMEM combo_11[] = {DV_Q, DV_K, COMBO_END};        // cut
const uint16_t PROGMEM combo_12[] = {DV_COLN, DV_Q, COMBO_END};     // quit
const uint16_t PROGMEM combo_13[] = {DV_V, SFT_Z, COMBO_END};       // close window
const uint16_t PROGMEM c_paste[]  = {IDX_R, DV_N, COMBO_END};       // paste
const uint16_t PROGMEM c_th[]     = {IDX_R, DV_T, COMBO_END};       // "th"
const uint16_t PROGMEM c_the[]    = {IDX_R, DV_T, GUI_E, COMBO_END};// "the"

const uint16_t PROGMEM combo_15[] = {DV_O, GUI_E, COMBO_END};       // (
const uint16_t PROGMEM combo_16[] = {GUI_E, IDX_L, COMBO_END};      // )

const uint16_t PROGMEM c_reset[]  = {DV_QUOT, DV_COMM, DV_DOT, COMBO_END}; // reset

combo_t key_combos[] = {
    [CM_0]  = COMBO(c_esc, KC_ESC),
    [CM_1]  = COMBO(c_tab, KC_TAB),
    [CM_2]  = COMBO(c_tild, KC_TILD),
    [CM_3]  = COMBO(c_grv, KC_GRV),
    [CM_4]  = COMBO(c_mins, DV_MINS),
    [CM_5]  = COMBO(combo_5, G(A((KC_LEFT)))),
    [CM_6]  = COMBO(combo_6, G(A(KC_RIGHT))),
    [CM_7]  = COMBO(combo_7, G(DV_C)),
    // [CM_8]  = COMBO(lock_wis, LOCK_WIS),
    [CM_9]  = COMBO(combo_9, G(DV_A)),
    // [CM_10] = COMBO(combo_10, LOCK_WIS),
    [CM_11] = COMBO(combo_11, G(DV_X)),
    [CM_12] = COMBO(combo_12, G(DV_Q)),
    // [CM_13] = COMBO(combo_13, G(DV_W)),
    [CM_14] = COMBO(f_19b, KC_F19),
    [CM_15] = COMBO(combo_15, DV_LPRN),
    [CM_16] = COMBO(combo_16, DV_RPRN),
    [CM_17] = COMBO(c_paste, G(DV_V)),
    [CM_18] = COMBO(c_reset, QK_BOOT),
    [CM_19] = COMBO(c_the, SEND_THE),
    [CM_20] = COMBO(c_th, SEND_TH),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);