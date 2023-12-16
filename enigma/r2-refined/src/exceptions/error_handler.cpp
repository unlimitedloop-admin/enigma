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
//      File name       : error_handler.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/16
//
//
// *************************************************************

#include "error_handler.h"
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <Windows.h>
#include "src/static/log_file_manager.h"
#include "src/util/conv/converting.h"



namespace exceptions {

    void ErrorHandler::logMessage(const std::wstring& message) {
        // You can output strings to the Visual Studio output console. You can do this by passing the specified string.
        OutputDebugString(message.c_str());
    }
    
    bool ErrorHandler::tryCatchWithLogging(std::function<void()> action) {
        try {
            action();
            return true;
        }
        catch (std::exception ex) {
            MessageBox(NULL, util_conv::charToWString(ex.what()).c_str(), L"error information", MB_OK);
            std::wofstream logFile(_static::LogFileManager::GetLogFileName(), std::ios::app);
            logFile << util_conv::charToWString(ex.what()) << std::endl;
            return false;
        }
    }

}
