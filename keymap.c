#include QMK_KEYBOARD_H

// #define QWERTY 0 // Base qwerty


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_NO, QK_BOOT,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,

           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    )
};
*/


enum custom_keycodes {
  SHIFT_CTRL_PRTSC = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SHIFT_CTRL_PRTSC:
      if (record->event.pressed) {
        // when the key is pressed
        register_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_PSCR);
        unregister_code(KC_PSCR);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
      }
      break;
  }
  return true;
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
          KC_ESC,        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,
           KC_QUES,       KC_EXLM,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_UNDS,  
           KC_DQUO,       KC_Z,     KC_M,     KC_L,     KC_D,     KC_F, 
           KC_X,          KC_R,     KC_N,     KC_T,     KC_S,     KC_G, 
           KC_ESC,        MO(1),    KC_B,     KC_W,     KC_C,     KC_V, 
                          KC_CIRC,  KC_GRV,   KC_PEQL,  KC_DLR,  
                                  
                                             KC_BSPC, KC_PGUP, 
                                                      KC_LALT, 
                                     KC_LSFT, KC_ENT, KC_LCTL, 

           
          KC_F9,         KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUS,   KC_NO,    QK_BOOT, 
           KC_PMNS,       KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_ASTR,  KC_PLUS,
           KC_COMM,       KC_U,     KC_O,     KC_Y,     KC_SCLN,  KC_QUOT, 
           KC_P,          KC_A,     KC_E,     KC_I,     KC_H,     KC_TAB, 
           KC_BSPC,       KC_K,     KC_J,     KC_DOT,   KC_Q,     KC_COLN,  
                          KC_PERC,  KC_HASH,  KC_SLSH,  KC_BSLS, 
                 
                     KC_PGUP, KC_PGDN, 
                     KC_TAB, 
                     KC_LGUI, KC_LCTL, KC_SPC),

          

        [1] = LAYOUT(
          KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
           KC_NO,         KC_NO,    KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_PERC,
           KC_NO,         KC_NO,    KC_CIRC,  KC_UP,    KC_DLR,   KC_NO, 
           KC_BSPC,       KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO, 
           KC_LSFT,       KC_TRNS,  KC_B,     KC_W,     KC_NO,    KC_NO, 
                          KC_NO,    KC_NO,    KC_NO,    SHIFT_CTRL_PRTSC,

                                               KC_NO, KC_NO,
                                                      KC_NO, 
                                       MO(2), KC_ENT, KC_NO,
	
          KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
           KC_PEQL,       KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_ASTR,  KC_PLUS, 
           KC_COMM,       KC_7,     KC_8,     KC_9,     KC_SCLN,  KC_QUOT, 
           KC_AMPR,       KC_4,     KC_5,     KC_6,     KC_AT,    KC_TAB, 
           KC_BSPC,       KC_1,     KC_2,     KC_3,     KC_NO,    KC_COLN,
                          KC_DOT,   KC_0,     KC_SLSH,  KC_BSLS, 

                      KC_NO, KC_NO, 
                      KC_NO, 
                      KC_NO, KC_LCTL, KC_SPC),



        [2] = LAYOUT(
          KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO, 
           KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    
           KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     
           KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
           KC_TRNS,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    
                                         
                                               KC_NO, KC_NO, 
                                                      KC_NO, 
                                      KC_ESC, KC_ENT, KC_NO, 


          KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,     KC_NO, 
           KC_NO,         KC_F10,   KC_F11,   KC_F12,   KC_NO,    KC_NO, 
           KC_NO,         KC_F7,    KC_F8,    KC_F9,    KC_NO,    KC_NO,   
           KC_NO,         KC_F4,    KC_F5,    KC_F6,    KC_NO,    KC_NO, 
           KC_NO,         KC_F1,    KC_F2,    KC_F3,    KC_NO,    KC_NO, 
                          KC_NO,    KC_NO,    KC_NO,    KC_NO,    
                       
                      KC_NO, KC_NO, 
                      KC_NO, 
                      KC_NO, KC_NO, KC_NO)

};
