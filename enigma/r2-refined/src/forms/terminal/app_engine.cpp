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
//      Last update     : 2023/12/16
//
//
// *************************************************************

#include "app_engine.h"
#include <ctime>
#include <DxLib.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "src/exceptions/error_handler.h"
#include "src/static/log_file_manager.h"
#include "src/util/time/time.h"



namespace terminal {

    using namespace exceptions;

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

    bool AppEngine::eventLoop() {
        return ErrorHandler::tryCatchWithLogging([]() {
            while (!DxLib::ProcessMessage()) {
                if (0 != DxLib::CheckHitKey(KEY_INPUT_ESCAPE)) {
                    break;
                }
                else if (0 != DxLib::CheckHitKey(KEY_INPUT_F11)) {
                    // Performance test for output log.
                    std::wofstream logFile(_static::LogFileManager::GetLogFileName(), std::ios::app);
                    logFile << L"[" + util_time::getCurrentTimeWithMilliseconds() + L"]" << std::endl;
                }
            }
        });
    }

    void AppEngine::finalize() {
        DxLib::DxLib_End();
    }

}
