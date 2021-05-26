// DV_* keycodes are here https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_dvorak.h
#include "keymap_dvorak.h"

// Niceties for my Dvorak I->U L->M :->; switch keymap https://github.com/waynehoover/dvorak-alt-layouts
#undef DV_I
#undef DV_U
#undef DV_L
#undef DV_M
#undef DV_COLN
#undef DV_SCLN
#define DV_I KC_F
#define DV_U KC_G
#define DV_L KC_M
#define DV_M KC_P
#define DV_COLN KC_Z
#define DV_SCLN S(KC_Z)
