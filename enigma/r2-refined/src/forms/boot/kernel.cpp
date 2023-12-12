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
//      File name       : kernel.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/12
//
//
// *************************************************************

#include <Windows.h>
#include "src/forms/terminal/app_engine.h"



namespace boot {

    bool systems(LPTSTR cmdline) {
        if (!lstrcmp(cmdline, L"debug")) {
            MessageBox(NULL, L"デバッグモード", L"Message", MB_ICONINFORMATION | MB_OK);
        }
        terminal::AppEngine engine;
        if (engine.initialize()) {
            engine.eventLoop();
        }
        engine.finalize();
        return true;
    }

}
