#pragma once

#include "keymap_dvorakiulm.h"
#include "../../../users/callum/oneshot.h"
#include "../../../users/callum/swapper.h"

#define HS_HYP   KC_F19             // Not currently defined in hammerspoon
#define WD_LFT   A(KC_LEFT)     // Word left
#define WD_RHT   A(KC_RIGHT)    // Word right
#define DEL_WD   A(KC_BSPC)     // Delete Word
#define HS_DELLI A(DV_S)        // Delete Line binding hammerspoon (hyper-s)
#define LN_BEG   G(KC_LEFT)     // Line beginning
#define LN_END   G(KC_RIGHT)    // Line end
#define DEL_SLIN G(KC_BSPC)     // Delete from cursor to start of line
#define LAUNCH   G(KC_SPC)      // Launcher
#define ZOOM_IN  G(KC_QUOT)     // Zoom in
#define ZOOM_OUT G(KC_RBRC)     // Zoom out
#define VS_DELLI C(S(DV_K))     // Delete Line vscode
#define EMOJI    C(G(KC_SPC))   // MacOS Emoji
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_SPC  LGUI_T(KC_SPC)
#define GUI_J    LGUI_T(DV_J)
#define GUI_E    LGUI_T(DV_E)
#define GUI_I    LGUI_T(DV_I)
#define GUI_BSP  LGUI_T(KC_BSPC)
#define SFT_ENT  LSFT_T(KC_ENT)
#define SFT_SPC  LSFT_T(KC_SPC)
#define SFT_COLN LSFT_T(DV_COLN)
#define SFT_Z    LSFT_T(DV_Z)
#define SFT_A    LSFT_T(DV_A)
#define SFT_S    LSFT_T(DV_S)
#define SFT_I    LSFT_T(DV_I)
#define SFT_H    LSFT_T(DV_H)
#define SFT_E    LSFT_T(DV_E)
#define SFT_Te   LSFT_T(DV_T)
#define SFT_BSP  LSFT_T(KC_BSPC)
#define SFT_LBRC LSFT_T(DV_LBRC)
#define SFT_PRN  LSFT_T(KC_F22)
#define MO_LOW   MO(LOWER)
#define MO_RAI   MO(RAISE)
#define OSS_RAI  LT(RAISE, KC_F22)  // One-shot-shift / raise
#define F19_RAI  LT(RAISE, KC_F19)
#define RAI_ENT  LT(RAISE, KC_ENT)
#define NUM_O    LT(NUM, DV_O)
#define NUM_E    LT(NUM, DV_E)
#define NUM_SPC  LT(NUM, KC_SPC)
#define NUM_HSH  LT(NUM, KC_HASH)
#define LOW_TAB  LT(LOWER, KC_TAB)
#define HYP_ENT  HYPR_T(KC_ENT)
#define HYP_BSPC HYPR_T(KC_BSPC)
#define HYP_SPC  HYPR_T(KC_SPC)
#define HYP_W    HYPR_T(DV_W)
#define HYP_E    HYPR_T(DV_E)
#define OS_SFT   OSM(MOD_LSFT)

enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,

  SW_WIN,   // Switch to next window  (cmd-`)
  SW_APP,   // Switch to next app     (cmd-tab)
  SW_TAB,   // Switch to next tab     (ctl-tab)

  UDELLIN,
  TOGGLE_LOWER,
};

void toggle_lower_layer(void);
