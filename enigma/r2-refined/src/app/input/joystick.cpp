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
//      File name       : joystick.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include "joystick.h"
#include <DxLib.h>



namespace app {

    namespace input {

        Joystick::Joystick() {
            _keyboards = std::make_unique<inputkey::KeyboardsIn>();
            _keyBinding.defaultSetBindingSCon();
        }


        bool Joystick::updateJoystickState() {
            // Stores the latest information on keyboard input to the KeyboardsIn array.
            if (!_keyboards.get()->updateAllStateKey()) return false;

            DxLib::XINPUT_STATE xinput{};
            if (_keyBinding.isXInputEnabled()) {
                if (0 != GetJoypadXInputState(DX_INPUT_KEY_PAD1, &xinput)) return false;
                for (size_t i = 0; i < _joyButton.button.size(); ++i) {
                    if (xinput.Buttons[xinput_btn[i]]) {
                        ++_joyButton.button[i];
                        _joyButtonReleased.button[i] = 0;
                    }
                    else if (XINPUT_BUTTON_LEFT_TRIGGER == i && xinput.LeftTrigger) {
                        ++_joyButton.button[i];
                        _joyButtonReleased.button[i] = 0;
                    }
                    else if (XINPUT_BUTTON_RIGHT_TRIGGER == i && xinput.RightTrigger) {
                        ++_joyButton.button[i];
                        _joyButtonReleased.button[i] = 0;
                    }
                    else {
                        _joyButton.button[i] = 0;
                        ++_joyButtonReleased.button[i];
                    }
                }
            }
            else {
                for (size_t i = 0; i < _joyButton.button.size(); ++i) {
                    _joyButton.button[i] = _keyboards.get()->getHoldKeyValue(_keyBinding.getBindingSCon(static_cast<JPBTN>(i)));
                    if (-1 == _joyButton.button[i]) return false;
                    else if (0 != _joyButton.button[i]) {
                        _joyButtonReleased.button[i] = 0;
                    }
                    else {
                        ++_joyButtonReleased.button[i];
                    }
                }
            }
            return true;
        }

    }

}
