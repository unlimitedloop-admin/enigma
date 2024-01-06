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
//      File name       : joypad_tester.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include "joypad_tester.h"
#include <DxLib.h>
#include <memory>
#include <string>
#include <Windows.h>
#include "src/app/components/component_context.h"
#include "src/app/input/joystick.h"
#include "src/app/input/jpbtn.h"
#include "src/forms/terminal/app_engine.h"
#include "src/static/configuration.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace X01 {

            JoypadTester::JoypadTester(std::shared_ptr<input::Joystick> joycard) {
                _joyStick = joycard;
            }


            JoypadTester::~JoypadTester() {
            }


            _static::ResultSet JoypadTester::doExecuteComponents(IComponentContext* object) {
                for (size_t i = 0ULL; i < _static::R2R_G_JOYPADKEY; i++) {
                    auto inputkey = _joyStick->getPressJoyButton(static_cast<input::JPBTN>(i));
                    DxLib::DrawString(0, static_cast<int>(i * 16), (L"Keys[" + std::to_wstring(i) + L"] : " + std::to_wstring(inputkey)).c_str(), DxLib::GetColor(0, 0, 0));
                }
                if (1 == _joyStick->getHoldKey(KEY_INPUT_ESCAPE)) {
                    if (IDYES == MessageBox(terminal::AppEngine::HWnd, L"Ends the joypad key confirmation simulation. Do you agree ?", L"information", MB_YESNO)) {
                        object->changeComponents(nullptr);
                    }
                }
                return _static::ResultSet::PROC_SUCCEED;
            }
        }

    }

}
