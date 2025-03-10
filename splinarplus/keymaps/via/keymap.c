#include QMK_KEYBOARD_H


#define BASE 0
#define GAME 1
#define META 2
#define SYMB 3


// #if defined(OLED_ENABLE)

// // Rotate OLED
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//    return OLED_ROTATION_90;
// }

// // Draw to OLED
// bool oled_task_user() {
//    oled_set_cursor(0, 1);

//    switch (get_highest_layer(layer_state)) {
//    case BASE :
//       oled_write("Default", false);
//       break;
//    case GAME :
//       oled_write("Game mode", false);
//       break;
//    case META :
//       oled_write("Function", false);
//       break;
//    case SYMB :
//       oled_write("System", false);
//       break;
//    }
//    return false;
// }

// #endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_SPC,  MO(2),            MO(3),   KC_BSPC, KC_RALT, KC_ENT
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,          _______, _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [META] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,          _______, _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,          _______, _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  )

};
