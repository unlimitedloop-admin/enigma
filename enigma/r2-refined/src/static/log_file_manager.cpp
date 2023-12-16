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
//      File name       : log_file_manager.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/16
//
//
// *************************************************************

#include "log_file_manager.h"
#include <ctime>
#include <iomanip>
#include <sstream>



namespace _static {

    LogFileManager::LogFileManager() {
        // Get the current date and set it to the file name.
        std::wstringstream ss;
        std::time_t t = std::time(nullptr);
        std::tm tm;
        localtime_s(&tm, &t);
        ss << std::put_time(&tm, L"%Y%m%d-system.log");
        _logFileName = ss.str();
    }

    const std::wstring& LogFileManager::GetLogFileName() {
        static LogFileManager instance;
        return instance._logFileName;
    }

}
