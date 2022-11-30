
#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 100

#define COMBO_COUNT 9

// Set the COMBO_TERM so low that I won't type the keys one after each other during normal typing.
// They would have be held together intentionally to trigger this.
#define COMBO_TERM 50


#ifdef OLED_ENABLE
#    define OLED_FONT_H "keyboards/crkbd/keymaps/daylinmorgan/glcdfont.c"
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    define SPLIT_OLED_ENABLE
#    undef  OLED_TIMEOUT
        //  due to timer_read() for render_prompt(), we have own implementation of oled time out
#    define OLED_KEY_TIMEOUT 30000
#endif


// todo: put this in it's own file ?
#ifdef RGB_MATRIX_ENABLE
#   define RGB_LIGHT_SLEEP
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_CYCLE_ALL
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#   define ENABLE_RGB_BAND_SPIRAL_VAL
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#endif
