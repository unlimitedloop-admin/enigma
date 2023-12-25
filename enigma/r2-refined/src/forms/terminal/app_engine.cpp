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
//      File name       : app_engine.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/25
//
//
// *************************************************************

#include "app_engine.h"
#include <string>
#include <DxLib.h>
#include "src/exceptions/error_handler.h"
#include "src/forms/config/env_manager.h"
#include "src/forms/inputkey/keyboards_in.h"
#include "src/static/evaluations.h"
#include "src/static/log_file_manager.h"
#include "src/util/time/time.h"



namespace terminal {

    using namespace exceptions;

    bool AppEngine::initialize() {
        if (
            0 != DxLib::SetDoubleStartValidFlag(FALSE) ||
            0 != DxLib::SetOutApplicationLogValidFlag(FALSE) ||
            0 != DxLib::SetAlwaysRunFlag(FALSE) ||
            DX_CHANGESCREEN_OK != DxLib::ChangeWindowMode(TRUE) ||
            0 != DxLib::SetWindowPosition(32, 32) ||
            DX_CHANGESCREEN_OK != DxLib::SetGraphMode(512, 480, 16)
        ) {
            return false;
        }
        std::wstring str = L"";
        config::EnvManager::getParameter(L"$WINDOW_TEXT", &str);
        if (!str.empty() && 0 != DxLib::SetWindowText(str.c_str())) {
            DxLib::SetWindowText(L"r2-refined");
        }

        DxLib::DxLib_Init();
        if (DxLib::DxLib_IsInit()) {
            DxLib::SetDrawScreen(DX_SCREEN_BACK);
            return true;
        }
        return false;
    }


    bool AppEngine::eventLoop() {
        return ErrorHandler::tryCatchWithLogging([=]() {
            while (!DxLib::ProcessMessage() && !DxLib::ScreenFlip() && !DxLib::ClearDrawScreen() && _keyboards.updateAllStateKey()) {
                if (0 != _keyboards.getHoldKeyValue(KEY_INPUT_ESCAPE)) {
                    break;
                }
                if (100 == _keyboards.getHoldKeyValue(KEY_INPUT_1)) {
                    _test++;
                }
                DxLib::DrawString(0, 0, (L"1 key pressed:" + std::to_wstring(_test)).c_str(), DxLib::GetColor(255, 255, 255));
            }
        });
    }


    void AppEngine::finalize() {
        DxLib::DxLib_End();
    }

}
