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
//      File name       : joystick.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_INPUT_JOYSTICK_H_
#define _R2REFINED_APP_INPUT_JOYSTICK_H_

#include <array>
#include <cstdint>
#include <DxLib.h>
#include <memory>
#include <numeric>
#include "jpbtn.h"
#include "key_binding.h"
#include "src/forms/inputkey/keyboards_in.h"
#include "src/static/configuration.h"



#define XINPUT_BUTTON_LEFT_TRIGGER (10)
#define XINPUT_BUTTON_RIGHT_TRIGGER (11)

namespace app {

    namespace input {

        using namespace _static;


        /// <summary>
        ///  Abstract Joycard object.
        /// </summary>
        class C16Button {
        public:
            std::array<int64_t, R2R_G_JOYPADKEY> button;
        };



        /// <summary>
        ///  A joystick class that corresponds to game controller buttons.
        /// </summary>
        class Joystick final {
        public:
            Joystick();
            Joystick(const Joystick&) = delete;
            ~Joystick() = default;

            bool updateJoystickState();
            int64_t getPressJoyButton(const JPBTN num) const {
                return _joyButton.button[static_cast<int64_t>(num)];
            }
            int64_t getReleaseJoyButton(const JPBTN num) const {
                return _joyButtonReleased.button[static_cast<int64_t>(num)];
            }
            int64_t getHoldKey(size_t keynumber) const {
                return _keyboards->getHoldKeyValue(keynumber);
            }
            int64_t getFreeKey(size_t keynumber) const {
                return _keyboards->getFreeKeyValue(keynumber);
            }
            bool isPressingAnyButton() const {
                return 0 != std::accumulate(_joyButton.button.begin(), _joyButton.button.end(), 0LL);
            }

        private:
            const size_t xinput_btn[R2R_G_JOYPADKEY] = {
                XINPUT_BUTTON_DPAD_UP
                , XINPUT_BUTTON_DPAD_DOWN
                , XINPUT_BUTTON_DPAD_LEFT
                , XINPUT_BUTTON_DPAD_RIGHT
                , XINPUT_BUTTON_START
                , XINPUT_BUTTON_BACK
                , XINPUT_BUTTON_LEFT_THUMB
                , XINPUT_BUTTON_RIGHT_THUMB
                , XINPUT_BUTTON_LEFT_SHOULDER
                , XINPUT_BUTTON_RIGHT_SHOULDER
                , XINPUT_BUTTON_LEFT_TRIGGER
                , XINPUT_BUTTON_RIGHT_TRIGGER
                , XINPUT_BUTTON_A
                , XINPUT_BUTTON_B
                , XINPUT_BUTTON_X
                , XINPUT_BUTTON_Y
            };
            std::unique_ptr<inputkey::KeyboardsIn> _keyboards;
            C16Button _joyButton{};
            C16Button _joyButtonReleased{};
            KeyBinding _keyBinding;
        };

    }

}

#endif // !_R2REFINED_APP_INPUT_JOYSTICK_H_
