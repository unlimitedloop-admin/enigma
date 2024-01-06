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
//      File name       : resource_filecheck.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include <Windows.h>
#include "resource_filecheck.h"
#include "src/app/components/phase_context.h"
#include "src/forms/terminal/app_engine.h"



namespace app {

    namespace components {

        namespace A01 {

            namespace state {

                bool ResourceFilecheckPhase::execute(IPhaseContext* object) {
                    MessageBox(terminal::AppEngine::HWnd, L"The \"execute\" method of \"ResourceFilecheckPhase\" was executed.", L"information", MB_OK);
                    object->setPhase(nullptr);
                    return true;
                }

            }

        }

    }

}
