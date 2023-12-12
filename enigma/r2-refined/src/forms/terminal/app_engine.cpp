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
//      File name       : AppEngine.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/12
//
//
// *************************************************************

#include "app_engine.h"
#include <DxLib.h>



namespace terminal {

    bool AppEngine::initialize() {
        if (DX_CHANGESCREEN_OK != DxLib::ChangeWindowMode(TRUE)) {
            return false;
        }
        DxLib::DxLib_Init();
        if (DxLib::DxLib_IsInit()) {
            return true;
        }
        return false;
    }

    void AppEngine::eventLoop() {
        while (!DxLib::ProcessMessage() && !DxLib::CheckHitKeyAll()) {
        }
    }

    void AppEngine::finalize() {
        DxLib::DxLib_End();
    }

}
