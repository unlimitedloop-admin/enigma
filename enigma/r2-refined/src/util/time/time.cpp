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
//      File name       : time.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/16
//
//
// *************************************************************

#include <string>
#include <chrono>



namespace util_time {

    std::wstring getCurrentTimeWithMilliseconds() {
        // Get the current time.
        auto now = std::chrono::system_clock::now();
        auto now_as_time_t = std::chrono::system_clock::to_time_t(now);
        auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        std::tm tm;
        localtime_s(&tm, &now_as_time_t);

        // Format using stringstream.
        std::wstringstream ss;
        ss << std::put_time(&tm, L"%Y-%m-%d %H:%M:%S");
        ss << '.' << std::setfill(L'0') << std::setw(3) << now_ms.count();

        return ss.str();
    }
}
