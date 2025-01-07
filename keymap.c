#include QMK_KEYBOARD_H

// Define nombres para cada capa
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ###############################################################
// // Define modo de animaciones
// uint32_t base_mode = RGBLIGHT_MODE_STATIC_LIGHT;
// uint32_t lock_mode = RGBLIGHT_MODE_KNIGHT;
//
// void keyboard_post_init_user(void) {
//     rgblight_enable_noeeprom();
//     layer_state_set_user(layer_state);
// }
//
// layer_state_t layer_state_set_user(layer_state_t state) {
//     uint8_t layer = biton32(state);
//
//     switch(layer) {
//     case _LOWER:
//         rgblight_sethsv_noeeprom(HSV_GREEN);
//         break;
//
//     case _RAISE:
//         rgblight_sethsv_noeeprom(HSV_ORANGE);
//         break;
//
//     case _ADJUST:
//         rgblight_sethsv_noeeprom(HSV_MAGENTA);
//         break;
//
//     default:
//         rgblight_sethsv_noeeprom(HSV_CYAN);
//         break;
//     }
//     return state;
// }
//
// bool led_update_user(led_t led_state) {
//    if(led_state.caps_lock) {
//        rgblight_mode_noeeprom(lock_mode);
//    } else {
//        rgblight_mode_noeeprom(base_mode);
//    }
//    return true;
// }
// ###############################################################

// Definición de capas RGB
const rgblight_segment_t PROGMEM QWERTY_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_CYAN}
);

const rgblight_segment_t PROGMEM LOWER_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_GREEN}
);

const rgblight_segment_t PROGMEM RAISE_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM ADJUST_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 54, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM CAPSLOCK_LAYER[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED},
    {6, 1, HSV_RED},
    {13, 1, HSV_RED},
    {14, 1, HSV_RED},
    {24, 3, HSV_RED},

    {27, 6, HSV_RED},
    {33, 1, HSV_RED},
    {40, 1, HSV_RED},
    {41, 1, HSV_RED},
    {51, 3, HSV_RED}
);

// Lista de capas RGB
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    QWERTY_LAYER,
    LOWER_LAYER,
    RAISE_LAYER,
    ADJUST_LAYER,
    CAPSLOCK_LAYER
);

void keyboard_post_init_user(void) {
 // Asignar las capas RGB
 rgblight_layers = my_rgb_layers;
}

// Control de LEDs (Caps Lock)
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock); // Activar capa CAPSLOCK si está activado
    return true;
}

// Control de capas
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
       KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT,  KC_RGUI, MO(_RAISE)
                                        //|--------------------------|  |--------------------------|
    ),

    [_LOWER] = LAYOUT(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT,  KC_RGUI, MO(_ADJUST)
                                        //|--------------------------|  |--------------------------|
    ),

    [_RAISE] = LAYOUT(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
       KC_TAB,  KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(_ADJUST), KC_SPC,   KC_ENT,  KC_RGUI, MO(_RAISE)
                                        //|--------------------------|  |--------------------------|
    ),

    [_ADJUST] = LAYOUT(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                      KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_RCTL, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                      KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(_ADJUST), KC_SPC,   KC_ENT,  KC_RGUI, MO(_RAISE)
                                        //|--------------------------|  |--------------------------|
    )
};
