    /* Good on you for modifying your layout! if you don't have
    * time to read the QMK docs, a list of keycodes can be found at
    *
    * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
    *
    * There's also a template for adding new layers at the bottom of this file!
    */

    #include QMK_KEYBOARD_H

    #define BASE 0 // default layer
    #define SYMB 1 // symbols
    #define NUMB 2 // numbers/motion

    // Blank template at the bottom

    enum customKeycodes {
        URL  = 1
    };


    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
    *
    * ,-------------------------------------------.                         ,-------------------------------------------.
    * | TAB    |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  | BKSP   |
    * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
    * | LALT   |   A  |   S  |   D  |   F  |   G  | ESC  |           |      |   H  |   J  |   K  |   L  | ;  : | ENTER  |
    * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
    * | LShift |   Z  |   X  |   C  |   V  |   B  | LCMD |           | RCMD |   N  |   M  | ,  < | . >  | /  ? | RShift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *                    .------.   .-------.                                    .------.   .-----.
    *                    | BKSP |   | Space |                                    | SPC  |   | Del |
    *                    |      |   | SYMB  |                                    | SYMB |   |     |
    *                    '------'   '-------'                                    `------'   '-----'
    *                                        ,-------.                      ,-------.
    *                                        |       |                      |       |
    *                                 ,------|-------|                      |-------|------.
    *                                 | NUMB | CTRL  |                      | CTRL  | NUMB |
    *                                 |      |       |                      |       |      |
    *                                 |      |       |                      |       |      |
    *                                 `--------------'                      `--------------'
    */
    [BASE] = LAYOUT_gergo(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,                                             KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LALT, KC_A, KC_S, KC_D, KC_F,    KC_G,   KC_ESC,                          KC_TRNS, KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V,    KC_B,   KC_LCMD,  KC_TRNS,      KC_TRNS, KC_RCMD, KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                         KC_BSPC, LT(SYMB, KC_SPC), MO(NUMB), KC_LCTL,      KC_RCTL, MO(NUMB), LT(SYMB, KC_SPC), KC_DEL
        ),
    /* Keymap 1: Symbols layer
    *
    * ,-------------------------------------------.                         ,-------------------------------------------.
    * | ` ~    |  !   |  @   |  #   |  $   |  %   |                         |   ^  |  &   |  *   |  (   |  )   |  \ |   |
    * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
    * | LALT   |  #   |  $   |  (   |  )   | ` ~  |      |           |      |      | - _  | = +  | { [  | } ]  |  ' "   |
    * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
    * | LShift |  %   |  ^   | { [  | } ]  |      |      |           |      |      |      | , <  | . >  |  / ? | RShift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *                        .------.   .------.                                 .------.   .-----.
    *                        | BKSP |   | SYMB |                                 | SYMB |   | DEL |
    *                        '------'   '------'                                 `------'   '-----'
    *                                        ,-------.                     ,-------.
    *                                        |       |                     |       |
    *                                 ,------|-------|                     |-------|------.
    *                                 |      |       |                     |       |      |
    *                                 |      |       |                     |       |      |
    *                                 |      |       |                     |       |      |
    *                                 `--------------'                     `--------------'
    */
    [SYMB] = LAYOUT_gergo(
        KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
        KC_TRNS,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,                          KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
        KC_TRNS,  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
     ),
    /* Keymap 2: Number layer
    *
    * ,-------------------------------------------.                         ,-------------------------------------------.
    * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
    * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
    * |        |  F1  | F2   | F3   | F4   | F5   | F6   |           |      | LEFT | DOWN |  UP  | Right|      |        |
    * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
    * |        |  F7  | F8   | F9   | F10  | F11  | F12  |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *                        .------.   .------.                                 .------.   .-----.
    *                        |      |   |      |                                 |      |   |     |
    *                        '------'   '------'                                 `------.   '-----'
    *                                        ,-------.                     ,-------.
    *                                        |       |                     |       |
    *                                 ,------|-------|                     |-------|------.
    *                                 |      |       |                     |       |      |
    *                                 |      |       |                     |       |      |
    *                                 |      |       |                     |       |      |
    *                                 `--------------'                     `--------------'
    */
    [NUMB] = LAYOUT_gergo(
        KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /* Keymap template
    *
    * ,-------------------------------------------.                         ,-------------------------------------------.
    * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *                        .------.   .------.                                 .------.   .-----.
    *                        |      |   |      |                                 |      |   |     |
    *                        '------'   '------'                                 `------.   '-----'
    *                                        ,-------.       ,-------.
    *                                        |       |       |       |
    *                                 ,------|-------|       |-------|------.
    *                                 |      |       |       |       |      |
    *                                 |      |       |       |       |      |
    *                                 |      |       |       |       |      |
    *                                 `--------------'       `--------------'
    * [SYMB] = LAYOUT_gergo(
    *     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    *     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    *     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    *                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    *     )
    */
    };
