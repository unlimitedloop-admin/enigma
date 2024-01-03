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
//      File name       : develop_sequence.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include "develop_sequence.h"
#include <DxLib.h>
#include <string>
#include "src/app/input/joystick.h"
#include "src/app/input/jpbtn.h"
#include "src/static/configuration.h"



namespace app {

    namespace sequence {

        _static::ResultSet DevelopSequence::onExecute() {
            if (!_joyStick->updateJoystickState()) {
                return _static::ResultSet::PROC_FAILED;
            }
            for (size_t i = 0ULL; i < _static::R2R_G_JOYPADKEY; i++) {
                auto inputkey = _joyStick->getPressJoyButton(static_cast<input::JPBTN>(i));
                DxLib::DrawString(0, static_cast<int>(i * 16), (L"Keys[" + std::to_wstring(i) + L"] : " + std::to_wstring(inputkey)).c_str(), DxLib::GetColor(0, 0, 0));
            }
            return _static::ResultSet::PROC_SUCCEED;
        }

    }

}
