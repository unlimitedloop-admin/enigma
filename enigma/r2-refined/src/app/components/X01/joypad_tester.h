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
//      File name       : joypad_tester.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_X01_JOYPADTESTER_H_
#define _R2REFINED_APP_COMPONENTS_X01_JOYPADTESTER_H_

#include <memory>
#include "src/app/components/component.h"
#include "src/app/components/component_context.h"
#include "src/app/input/joystick.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace X01 {

            class JoypadTester : public IComponent {
            public:
                JoypadTester(std::shared_ptr<input::Joystick>);
                ~JoypadTester();

                _static::ResultSet doExecuteComponents(IComponentContext* object) override;

            private:
                std::shared_ptr<input::Joystick> _joyStick;
            };

        }

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_X01_JOYPADTESTER_H_
