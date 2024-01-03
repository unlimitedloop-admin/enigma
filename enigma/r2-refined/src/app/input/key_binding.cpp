// *************************************************************
//
//
//      Copyright (c) 2024 UNLIMITED LOOP ROOT-ONE
//
//
//      This software(and source code) is completely Unlicense.
//      see "LICENSE".
//
//
// *************************************************************
//
//
//      [enigma] r2-refined project
//
//      File name       : key_binding.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include "key_binding.h"
#include <array>
#include <cstdint>
#include <DxLib.h>
#include "jpbtn.h"
#include "src/static/configuration.h"



namespace app {

    namespace input {

        bool KeyBinding::setBindingSCon(const std::array<uint16_t, R2R_G_JOYPADKEY> keys, const bool hatsw, const bool joypad) {
            _sCon.xinputEnabled = joypad;
            if (!_sCon.xinputEnabled) {
                for (size_t i = 0; i < R2R_G_JOYPADKEY; ++i) {
                    if (0xFF < keys[i]) { return false; }
                    _sCon.keys[i] = keys[i];
                }
            }
            _sCon.hatswitchEnabled = hatsw;
            return true;
        }


        uint16_t KeyBinding::getBindingSCon(const JPBTN button) const {
            return _sCon.keys[static_cast<uint16_t>(button)];
        }


        bool KeyBinding::isXInputEnabled() const {
            return _sCon.xinputEnabled;
        }


        bool KeyBinding::defaultSetBindingSCon() {
            // Only do keyboard key bindings when no gamepad is connected.
            if (GetJoypadNum()) {
                if (!setBindingSCon({}, true, true)) {
                    return false;
                }
            }
            else {
                if (!setBindingSCon(getDefaultBindKeyArray(), true, false)) {
                    return false;
                }
            }
            return true;
        }


        std::array<uint16_t, R2R_G_JOYPADKEY> KeyBinding::getDefaultBindKeyArray() {
            std::array<uint16_t, R2R_G_JOYPADKEY> key = {
                KEY_INPUT_W             // xi_up
                , KEY_INPUT_S           // xi_down
                , KEY_INPUT_A           // xi_left
                , KEY_INPUT_D           // xi_right
                , KEY_INPUT_RETURN      // xi_start_button
                , KEY_INPUT_SPACE       // xi_back_button
                , KEY_INPUT_F           // xi_ls_stick
                , KEY_INPUT_H           // xi_rs_stick
                , KEY_INPUT_1           // xi_l_button
                , KEY_INPUT_0           // xi_r_button
                , KEY_INPUT_5           // xi_lz_button
                , KEY_INPUT_7           // xi_rz_button
                , KEY_INPUT_M           // xi_a_button
                , KEY_INPUT_N           // xi_b_button
                , KEY_INPUT_L           // xi_x_button
                , KEY_INPUT_K           // xi_y_button
            };
            return key;
        }

    }

}
