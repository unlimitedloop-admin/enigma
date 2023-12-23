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
//      File name       : log_file_manager.h
//
//      Author          : u7
//
//      Last update     : 2023/12/23
//
//
// *************************************************************

#ifndef _R2REFINED_STATIC_LOGFILEMANAGER_H_
#define _R2REFINED_STATIC_LOGFILEMANAGER_H_

#include <string>



namespace _static {

    /// <summary>
    ///  Generate and manage log file names.
    /// </summary>
    class LogFileManager final {
    public:
        /// <summary>
        ///  Get the log file name of a Singleton instance.
        /// </summary>
        /// <returns>Log file name.</returns>
        static const std::wstring& GetLogFileName();

    private:
        std::wstring _logFileName;
        
        LogFileManager();
        LogFileManager(const LogFileManager&) = delete;
        LogFileManager& operator=(const LogFileManager&) = delete;
        LogFileManager(LogFileManager&&) = delete;
        LogFileManager& operator=(LogFileManager&&) = delete;
    };

}

#endif // !_R2REFINED_STATIC_LOGFILEMANAGER_H_
