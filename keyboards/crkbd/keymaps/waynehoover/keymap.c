// qmk flash -c -kb crkbd -km waynehoover -e CONVERT_TO=rp2040_ce

#include QMK_KEYBOARD_H
#include "../../../users/waynehoover/keymap_defines.h"
#include "../../../users/waynehoover/waynehoover.h"
#include "../../../users/waynehoover/combos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAKIL] = LAYOUT_split_3x6_3(
    _______ , DV_QUOT , DV_COMM , DV_DOT  , DV_P    , DV_Y    ,         DV_F    , DV_G    , DV_C    , DV_R    , DV_M     , _______ ,
    _______ , DV_A    , DV_O    , GUI_E   , IDX_L   , DV_U    ,         DV_D    , IDX_R   , DV_T    , DV_N    , DV_S     , _______ ,
    _______ , DV_COLN , DV_Q    , DV_J    , DV_K    , DV_X    ,         DV_B    , DV_L    , DV_W    , DV_V    , DV_Z     , _______ ,
                                 LOCK_WIS , THB_L2  , THB_L1  ,         THB_R1  , THB_R2  , TOG_MIC
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

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_split_3x6_3(
      'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                     '*', '*', '*',  '*', '*', '*'
  );