/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 160

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"QlVyg/Wj4Yl"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 2

#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60

#define ACHORDION_STREAK
#define VOYAGER_USER_LEDS
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
