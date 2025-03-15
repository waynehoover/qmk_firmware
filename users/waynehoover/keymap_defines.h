#include <stdio.h>

#pragma once

#include "keymap_dvorakiulm.h"
#include "callum/oneshot.h"
#include "callum/swapper.h"
#include "features/achordion.h" // https://getreuer.info/posts/keyboards/achordion/index.html#add-achordion-to-your-keymap
// #include "features/sentence_case.h" // https://getreuer.info/posts/keyboards/sentence-case/index.html#add-it-to-your-keymap

#define MASTER_RIGHT

#define WD_LFT   A(KC_LEFT)     // Word left
#define WD_RHT   A(KC_RIGHT)    // Word right
#define DEL_WD   A(KC_BSPC)     // Delete Word
#define HS_DELLI A(DV_Z)        // Delete Line binding hammerspoon
#define LN_BEG   G(KC_LEFT)     // Line beginning
#define LN_END   G(KC_RIGHT)    // Line end
#define DEL_SLIN G(KC_BSPC)     // Delete from cursor to start of line
#define LAUNCH   G(KC_SPC)      // Launcher
#define ZOOM_IN  G(KC_QUOT)     // Zoom in
#define ZOOM_OUT G(KC_RBRC)     // Zoom out
#define DEL_LINE G(S(DV_K))     // Delete Line vscode/obsidian
#define EMOJI    G(C(KC_SPC))   // MacOS Emoji
#define TOG_MIC  G(S(KC_SPC))   // Toggle mic (slack)
#define FND_ALL  G(S(DV_F))     // Find all
#define TOG_COMM G(DV_SLSH)     // Toggle comment
#define ALT_SPC  LALT_T(KC_SPC)
#define ALT_BSP  LALT_T(KC_BSPC)
#define ALT_O    LALT_T(DV_O)
#define ALT_ENT  LALT_T(KC_ENT)
#define GUI_ESC  LGUI_T(KC_ESC)
#define GUI_SPC  LGUI_T(KC_SPC)
#define GUI_ENT  LGUI_T(KC_ENT)
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
#define SFT_I    MT(MOD_LSFT, DV_I) // LSFT_T(DV_I)
#define SFT_H    MT(MOD_LSFT, DV_H) // LSFT_T(DV_H)
#define SFT_E    LSFT_T(DV_E)
#define SFT_Te   LSFT_T(DV_T)
#define SFT_BSP  LSFT_T(KC_BSPC)
#define SFT_LBRC LSFT_T(DV_LBRC)
#define SFT_PRN  LSFT_T(KC_F22)
#define SFT_ENT  LSFT_T(KC_ENT)
#define MO_LOW   MO(LOWER)
#define MO_RAI   MO(RAISE)
#define OSS_RAI  LT(RAISE, KC_F22)  // One-shot-shift / raise
#define F19_RAI  LT(RAISE, KC_F19)
#define RAI_ENT  LT(RAISE, KC_ENT)
#define RAI_BSP  LT(RAISE, KC_BSPC)
#define NUM_O    LT(NUM, DV_O)
#define NUM_E    LT(NUM, DV_E)
#define NUM_SPC  LT(NUM, KC_SPC)
#define NUM_HSH  LT(NUM, KC_HASH)
#define LOW_TAB  LT(LOWER, KC_TAB)
#define LOW_SPC  LT(LOWER, KC_SPC)
#define HYP_ENT  HYPR_T(KC_ENT)
#define HYP_BSPC HYPR_T(KC_BSPC)
#define HYP_SPC  HYPR_T(KC_SPC)
#define HYP_W    HYPR_T(DV_W)
#define HYP_E    HYPR_T(DV_E)
#define OS_SFT   OSM(MOD_LSFT)

#define THB_L2 OS_SFT  // MO_LOW  is Original
#define THB_L1 LOW_SPC // ALT_SPC is Original

#define THB_R1 ALT_BSP // next try RAI_BSP // KC_BSPC is Original
#define THB_R2 RAI_ENT // next try ALT_ENT // RAI_ENT is Original

// If I moved thmb_l2 to os_sft, then I could remove the shift keys on the home row.
// and if I made thmb_r2 a gui_ent then I could remove gui, but that wouldn't work because most gui keys I press are on the right.

enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,

  SW_WIN,   // Switch to next window  (cmd-`)
  SW_APP,   // Switch to next app     (cmd-tab)
  SW_TAB,   // Switch to next tab     (ctl-tab)o

  UDELLIN,
  TOGGLE_LOWER,
  SEND_TH,
  SEND_THE,
};

void toggle_lower_layer(void);

#include "combos.c"
