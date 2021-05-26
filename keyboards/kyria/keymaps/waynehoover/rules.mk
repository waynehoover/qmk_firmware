OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = yes      # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

SRC += ../../../users/callum/oneshot.c
SRC += ../../../users/callum/swapper.c
SRC += tapdance.c
