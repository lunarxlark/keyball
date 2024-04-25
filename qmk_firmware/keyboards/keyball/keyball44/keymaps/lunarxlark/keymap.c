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
  // keymap for default
  [0] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E    , KC_R     , KC_T     ,                                         KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D    , KC_F     , KC_G     ,                                         KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C    , KC_V     , KC_B     ,                                         KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                  KC_LALT  , KC_LNG2 , KC_LGUI  ,         TO(1)    , KC_SPC   ,                    KC_ENT  , TO(2)    , _______       , _______  , KC_LNG1
  ),

  [1] = LAYOUT_universal(
    KC_ESC   , _______  , _______  , _______ , _______  , _______  ,                                         _______  , _______  , _______  , _______  , _______  , KC_BSPC  ,
    KC_LCTL  , S(KC_1)  , S(KC_2)  , S(KC_3) , S(KC_4)  , S(KC_5)  ,                                         S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  , KC_BSLS  ,
    KC_LSFT  , KC_1     , KC_2     , KC_3    , KC_4     , KC_5     ,                                         KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_RSFT  ,
                  KC_LALT  , _______ , KC_LGUI  ,         _______  , SCRL_MO  ,                   _______  , TO(3)    , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F11   , KC_F12   , KC_F13  , KC_F14   , KC_F15   ,                                         KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_LBRC  , KC_RBRC  ,
    KC_LCTL  , KC_F6    , KC_F7    , KC_F8   , KC_F9    , KC_F10   ,                                         KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_MINS  , KC_EQL   ,
    KC_LSFT  , KC_F1    , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_BTN4  , KC_BTN1  , KC_BTN2  , KC_BTN5  , _______ , KC_GRV    ,
                  KC_LALT  , _______ , KC_LGUI  ,         TO(3)    , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______ , _______  ,                                        _______  , _______  , CPI_D100 , CPI_D1K , AML_D50 , _______  ,
    _______  , _______  , _______  , _______  , _______ , SCRL_DVI ,                                        _______  , SCRL_MO  , CPI_I100 , CPI_I1K , AML_I50 , _______  ,
    _______  , _______  , _______  , _______  , _______ , SCRL_DVD ,                                        KC_BTN4  , KC_BTN1  , KC_BTN2  , KC_BTN5 , AML_TO  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , KC_LGUI  ,        _______  , _______  ,                   _______  , _______ , _______       , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 1);
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
