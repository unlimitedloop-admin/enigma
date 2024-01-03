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
//      File name       : main_sequence.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include "main_sequence.h"
#include "src/app/input/joystick.h"
#include "src/app/input/jpbtn.h"



namespace app {

    namespace sequence {

        _static::ResultSet MainSequence::onExecute() {
            if (!_joyStick->updateJoystickState()) return _static::ResultSet::PROC_FAILED;
            if (_joyStick->getPressJoyButton(input::JPBTN::START)) {
                return _static::ResultSet::PROC_QUIT;
            }
            return _static::ResultSet::PROC_SUCCEED;
        }

    }

}
