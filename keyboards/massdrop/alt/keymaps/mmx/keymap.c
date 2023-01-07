#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AGCR = SAFE_RANGE, //USB Toggle Automatic GCR control
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode


#define HUE_BLUE_MMX 120
#define HUE_PURPLE_MMX 230
#define HUE_ORANGE_MMX 10
#define HUE_GREEN_MMX 80
#define HUE_WHITE_MMX 0

uint8_t default_hue = HUE_ORANGE_MMX; // Set default hue to orange

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_ALGR, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        RGB_MOD, KC_BTN1, KC_MS_U, KC_BTN2, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, U_T_AGCR, \
        RGB_TOG, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_VAI, \
        _______, KC_NUBS, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,          KC_VOLU, RGB_VAD, \
        _______, _______, _______,                            KC_MPLY,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT  \
    ),

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_matrix_sethsv(HUE_ORANGE_MMX, 255, 255); // Set color
    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER); // Disable light strip
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};


// This runs every matrix scan (every 'frame')
void rgb_matrix_indicators_user(void) {

    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(30, 0, 255, 0); // Sets Caps lock to green
    }

    if (layer_state_is(1)) {

        // Special characters
        rgb_matrix_set_color(0, 255, 100, 0); // Esc (missing ISO button §)
        rgb_matrix_set_color(45, 255, 100, 0); // Z (missing ISO button <>)
        rgb_matrix_set_color(19, 255, 0, 0); // R (reset/flash)

        // Media buttons to green
        rgb_matrix_set_color(14, 0, 255, 0); // Del
        rgb_matrix_set_color(56, 0, 255, 0); // Up
        rgb_matrix_set_color(66, 0, 255, 0); // Right
        rgb_matrix_set_color(65, 0, 255, 0); // Down
        rgb_matrix_set_color(64, 0, 255, 0); // Left
        rgb_matrix_set_color(61, 0, 255, 0); // Space

        // Mouse to blue
        rgb_matrix_set_color(17, 0, 200, 255); // W
        rgb_matrix_set_color(33, 0, 200, 255); // D
        rgb_matrix_set_color(32, 0, 200, 255); // S
        rgb_matrix_set_color(31, 0, 200, 255); // A
        rgb_matrix_set_color(16, 0, 0, 255); // Q
        rgb_matrix_set_color(18, 0, 0, 255); // E

        // LED modifiers to purple
        rgb_matrix_set_color(15, 255, 0, 255); // Tab
        rgb_matrix_set_color(30, 255, 0, 255); // Caps Lock
        rgb_matrix_set_color(29, 255, 0, 255); // Home
        rgb_matrix_set_color(43, 255, 0, 255); // Pg up
        rgb_matrix_set_color(57, 255, 0, 255); // Pg down

        // Function keys to white
        rgb_matrix_set_color(1, 255, 255, 255); // 1
        rgb_matrix_set_color(2, 255, 255, 255); // 2
        rgb_matrix_set_color(3, 255, 255, 255); // 3
        rgb_matrix_set_color(4, 255, 255, 255); // 4
        rgb_matrix_set_color(5, 255, 255, 255); // 5
        rgb_matrix_set_color(6, 255, 255, 255); // 6
        rgb_matrix_set_color(7, 255, 255, 255); // 7
        rgb_matrix_set_color(8, 255, 255, 255); // 8
        rgb_matrix_set_color(9, 255, 255, 255); // 9
        rgb_matrix_set_color(10, 255, 255, 255); // 10
        rgb_matrix_set_color(11, 255, 255, 255); // 11
        rgb_matrix_set_color(12, 255, 255, 255); // 12
    }
}


#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: { // Only keys
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: { // only light strip
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        case RGB_MOD:
            if (record->event.pressed) {
                switch (rgblight_get_mode()) {
                    case 2: {
                        rgb_matrix_set_val(255);
                    }
                    break;
                    default: {
                        rgb_matrix_set_val(128);
                    }
                }
            }
            return true;
        case U_T_AGCR:
            if (record->event.pressed) {
                switch (rgb_matrix_get_hue()) {
                    case HUE_BLUE_MMX: {
                        rgb_matrix_set_hue(HUE_PURPLE_MMX);
                        rgb_matrix_set_sat(255);
                    }
                    break;
                    case HUE_PURPLE_MMX: {
                        rgb_matrix_set_hue(HUE_GREEN_MMX);
                        rgb_matrix_set_sat(255);
                    }
                    break;
                    case HUE_GREEN_MMX: {
                        rgb_matrix_set_hue(HUE_ORANGE_MMX);
                        rgb_matrix_set_sat(255);
                    }
                    break;
                    case HUE_ORANGE_MMX: {
                        rgb_matrix_set_hue(HUE_WHITE_MMX);
                        rgb_matrix_set_sat(0);
                    }
                    break;
                    default: {
                        rgb_matrix_set_hue(HUE_BLUE_MMX);
                        rgb_matrix_set_sat(255);
                    }
                }
            }
        default:
            return true; //Process all other keycodes normally
    }
}
