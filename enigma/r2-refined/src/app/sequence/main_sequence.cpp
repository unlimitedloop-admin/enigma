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
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include "main_sequence.h"
#include "src/app/components/component.h"
#include "src/app/components/A01/launch_component.h"
#include "src/app/input/joystick.h"
#include "src/static/evaluations.h"



namespace app {

    namespace sequence {

        MainSequence::MainSequence() {
            _joyStick = std::make_shared<input::Joystick>();
            _component = new components::A01::LaunchComponent();
        }


        MainSequence::~MainSequence() {
            if (_component) {
                delete _component;
                _component = nullptr;
            }
        }


        _static::ResultSet MainSequence::onExecute() {
            if (!_joyStick->updateJoystickState()) return _static::ResultSet::PROC_FAILED;
            return _component ? _component->doExecuteComponents(this) : _static::ResultSet::PROC_QUIT;
        }


        bool MainSequence::changeComponents(components::IComponent* component) {
            if (_component) {
                delete _component;
                _component = component;
            }
            return nullptr != _component;
        }

    }

}
