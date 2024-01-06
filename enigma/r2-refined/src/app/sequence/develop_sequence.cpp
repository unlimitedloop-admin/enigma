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
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include <DxLib.h>
#include <string>
#include "develop_sequence.h"
#include "src/app/input/joystick.h"
#include "src/app/input/jpbtn.h"
#include "src/static/configuration.h"



namespace app {

    namespace sequence {

        DevelopSequence::DevelopSequence() {
            _joyStick = std::make_shared<input::Joystick>();
            _component = nullptr;
        }


        DevelopSequence::~DevelopSequence() {
            if (_component) {
                delete _component;
                _component = nullptr;
            }
        }


        _static::ResultSet DevelopSequence::onExecute() {
            if (!_joyStick->updateJoystickState()) return _static::ResultSet::PROC_FAILED;
            return _static::ResultSet::PROC_SUCCEED;
        }


        bool DevelopSequence::changeComponents(components::IComponent* component) {
            if (_component) {
                delete _component;
                _component = component;
            }
            return nullptr != _component;
        }

    }

}
