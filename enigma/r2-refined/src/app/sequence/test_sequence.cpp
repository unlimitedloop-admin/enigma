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
//      File name       : test_sequence.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include "test_sequence.h"
#include "src/app/components/component.h"
#include "src/app/components/X01/joypad_tester.h"
#include "src/app/input/joystick.h"
#include "src/static/evaluations.h"



namespace app {

    namespace sequence {

        TestSequence::TestSequence() {
            _joyStick = std::make_shared<input::Joystick>();
            _component = new components::X01::JoypadTester(_joyStick);
        }


        TestSequence::~TestSequence() {
            if (_component) {
                delete _component;
                _component = nullptr;
            }
        }


        _static::ResultSet TestSequence::onExecute() {
            if (!_joyStick->updateJoystickState()) return _static::ResultSet::PROC_FAILED;
            return _component ? _component->doExecuteComponents(this) : _static::ResultSet::PROC_QUIT;
        }


        bool TestSequence::changeComponents(components::IComponent* component) {
            if (_component) {
                delete _component;
                _component = component;
            }
            return nullptr != _component;
        }

    }

}
