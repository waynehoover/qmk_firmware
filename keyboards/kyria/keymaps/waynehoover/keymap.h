#pragma once

#include "keymap_dvorakiulm.h"
#include "../../../users/callum/oneshot.h"
#include "../../../users/callum/swapper.h"

#define WD_LFT   A(KC_LEFT)     // Word left
#define WD_RHT   A(KC_RIGHT)    // Word right
#define LN_BEG   G(KC_LEFT)     // Line beginning
#define LN_END   G(KC_RIGHT)    // Line end
#define VS_DELLI C(S(DV_K))     // Delete Line vscode
#define HS_DELLI A(DV_S)        // Delete Line binding hammerspoon
#define DEL_SLIN G(KC_BSPC)     // Delete from cursor to start of line
#define DEL_WD   A(KC_BSPC)     // Delete Word
#define LAUNCH   G(KC_SPC)      // Launcher
#define EMOJI    C(G(KC_SPC))   // MacOS Emoji
#define ZOOM_IN  G(KC_QUOT)     // Zoom in
#define ZOOM_OUT G(KC_RBRC)     // Zoom out
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_SPC  LGUI_T(KC_SPC)
#define CTL_TAB  CTL_T(KC_TAB)
#define SFT_ENT  RSFT_T(KC_ENT)
#define SFT_SPC  RSFT_T(KC_SPC)
#define SFT_COLN LSFT_T(DV_COLN)
#define SFT_Z    RSFT_T(DV_Z)
#define SFT_BSP  LSFT_T(KC_BSPC)
#define SFT_LBRC LSFT_T(DV_LBRC)
#define MO_LOW   MO(LOWER)
#define MO_RAI   MO(RAISE)
#define OSS_RAI  LT(RAISE, KC_F22) // One-shot-shift / raise
#define SFT_PRN  LSFT_T(KC_F22)
#define HS_HYP   KC_F19
#define HYP_ENT  HYPR_T(KC_ENT)
#define OS_SFT   OSM(MOD_LSFT)

#define TD_DOT TD(DOT_TD)
#define CACCCV TD(CA_CC_CV)
#define TD_Q TD(TD_Q_QUI)

enum layers {
  DVORAK = 0,
  LOWER,
  RAISE,
  ADJUST
};

enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,

  SW_WIN,   // Switch to next window  (cmd-`)
  SW_APP,   // Switch to next app     (cmd-tab)
  SW_TAB,   // Switch to next tab     (ctl-tab)

  WORDCAPS, // Caps Word
  UDELLIN,
};

// Tap dance keys
enum {
    DOT_TD = 0,
    CA_CC_CV,
    TD_Q_QUI
};
