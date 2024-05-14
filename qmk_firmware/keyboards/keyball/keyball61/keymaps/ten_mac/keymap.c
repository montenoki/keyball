/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,    KC_1,    KC_2,     KC_3,      KC_4,      KC_5,                        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
    KC_TAB,    KC_Q,    KC_W,     KC_E,      KC_R,      KC_T,                        KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
    MO(1),     KC_A,    KC_S,     KC_D,      KC_F,      KC_G,                        KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,     KC_C,      KC_V,      KC_B,    KC_LBRC,  KC_RBRC,  KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
    KC_LCTL,   KC_LALT, MO(3),    KC_LGUI,   KC_BTN2,   KC_SPC,  KC_BTN1,  MO(2),    KC_ENT,                                     KC_MINS,   KC_EQL
  ),

  [1] = LAYOUT(
    KC_GRV,    KC_F1,   KC_F2,    KC_F3,     KC_F4,     KC_F5,                       KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_DEL,
    _______,   _______, KC_BSPC,  KC_UP,     KC_DEL,    KC_HOME,                     KC_PGUP,   _______,   _______,   _______,   _______,   _______,
    _______,   _______, KC_LEFT,  KC_DOWN,   KC_RGHT,   _______,                     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______,   _______,
    _______,   _______, _______,  SGUI(KC_C),SGUI(KC_V),KC_END,  _______,  _______,  KC_PGDN,   _______,   _______,   _______,   _______,   _______,
    _______,   _______, _______,  _______,   _______,   KC_ENT,  KC_BTN3,  _______,  _______,                                    KC_F11,    KC_F12
  ),
  [2] = LAYOUT(
    KC_GRV,    KC_F1,   KC_F2,    KC_F3,     KC_F4,     KC_F5,                       KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_DEL,
    _______,   _______, _______,  _______,   _______,   _______,                     _______,   _______,   KC_UP,     _______,   _______,   _______,
    KC_CAPS,   _______, _______,  _______,   _______,   _______,                     _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,   _______,
    _______,   _______, _______,  _______,   _______,   _______, _______,  _______,  _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______, _______,  _______,   _______,   _______, _______,  _______,  _______,                                    KC_F11 ,   KC_F12
  ),
  [3] = LAYOUT(
    _______,   _______, _______,  _______,   _______,   _______,                     _______,   _______,   _______,   _______,   _______,   KC_DEL,
    _______,   _______, _______,  _______,   KBC_RST,   _______,                     _______,   _______,   _______,   _______,   _______,   _______,
    KC_CAPS,   _______, KBC_SAVE, _______,   _______,   _______,                     _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______, _______,  _______,   _______,   _______, CPI_D100, CPI_I100, _______,   RGB_MOD,   KC_VOLD,   KC_VOLU,   _______,   _______,
    _______,   _______, _______,  _______,   _______,   _______, _______,  _______,  _______,                                    SCRL_DVD,  SCRL_DVI
  ),
};
// CLANG-FORMAT ON

layer_state_t layer_state_set_user(layer_state_t state) {
    // Scroll mode when the highest layer is 2
    keyball_set_scroll_mode(get_highest_layer(state) == 2);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
