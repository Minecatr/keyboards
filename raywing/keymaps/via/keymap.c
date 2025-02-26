#include QMK_KEYBOARD_H


// #define BASE 0
// #define LFT 1
// #define RGT 2
// #define BTH 3
// #define MACROS 4

#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
   return OLED_ROTATION_90;
}

// Draw to OLED
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("FUNNY\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("FUNNY\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [4] = { ENCODER_CCW_CW(KC_MS_RIGHT, KC_MS_LEFT),    ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_SPC,  MO(2),            MO(3),   KC_BSPC, KC_ENT,  KC_RALT
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_T,    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_QUOT,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_P,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_SPC,  MO(2),            MO(3),   KC_BSPC, KC_ENT,  KC_RALT
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,                                     S(KC_7), S(KC_8), KC_LBRC,S(KC_LBRC),KC_GRV, KC_INS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, S(KC_8), KC_4,    KC_5,    KC_6,    KC_EQL,                                      S(KC_6), S(KC_0), KC_RBRC,S(KC_RBRC),S(KC_1),_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_TAB,                                      S(KC_5), S(KC_2), S(KC_3), S(KC_4), KC_BSLS, KC_RCTL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,          MO(4),   _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_TOG, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                                     KC_VOLU, KC_PGDN, KC_UP,   KC_PGUP, KC_HOME, RGB_HUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                                     RGB_MOD, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  RGB_SAI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,                                     KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______, RGB_VAI,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, MO(4),            _______, _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [4] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                   ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NUM,  KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,                                     _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                   ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT,                                     _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────────┐        ┌────────┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______, _______,          _______, _______, _______, _______
  //                               └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  )

};
