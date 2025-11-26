#pragma once

#include QMK_KEYBOARD_H
#include "keymap_defines.h"

// Swapper state
extern bool sw_app_active;
extern bool sw_win_active;
extern bool sw_tab_active;

// Oneshot state
extern oneshot_state os_shft_state;
extern oneshot_state os_ctrl_state;
extern oneshot_state os_alt_state;
extern oneshot_state os_cmd_state;

// Function declarations
bool is_oneshot_cancel_key(uint16_t keycode);
bool is_oneshot_ignored_key(uint16_t keycode);
bool process_record_user(uint16_t keycode, keyrecord_t *record);
void toggle_lower_layer(void);
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
uint16_t get_combo_term(uint16_t index, combo_t *combo);
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record);
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record);
bool caps_word_press_user(uint16_t keycode);
