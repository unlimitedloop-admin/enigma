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
//      File name       : key_binding.h
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_APP_INPUT_KEYBINDING_H_
#define _R2REFINED_APP_INPUT_KEYBINDING_H_

#include <array>
#include <cstdint>
#include "jpbtn.h"
#include "src/static/configuration.h"



namespace app {

    namespace input {

        using namespace _static;


        class XInputModulation final {
        public:
            std::array<uint16_t, R2R_G_JOYPADKEY> keys;     // Controller input keys.
            bool hatswitchEnabled;                          // The hat switch is a cross button.
            bool xinputEnabled;                             // Enable XInput controller.
        };



        class KeyBinding final {
        public:
            KeyBinding() {}
            KeyBinding(const KeyBinding&) = delete;
            KeyBinding& operator=(const KeyBinding&) = delete;
            ~KeyBinding() {}

            bool setBindingSCon(const std::array<uint16_t, R2R_G_JOYPADKEY>, bool, bool);
            uint16_t getBindingSCon(const JPBTN button) const;
            bool isXInputEnabled() const;
            bool defaultSetBindingSCon();

        private:
            XInputModulation _sCon;     // Controller instance.
            std::array<uint16_t, R2R_G_JOYPADKEY> getDefaultBindKeyArray();
        };

    }

}

#endif // !_R2REFINED_APP_INPUT_KEYBINDING_H_
