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
//      File name       : converting.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/16
//
//
// *************************************************************

#include <string>
#include <stdexcept>
#include <Windows.h>



namespace util_conv {

    const wchar_t* wcharToConstWchar(wchar_t* expression) {
        return const_cast<wchar_t*>(expression);
    }

    std::wstring charToWString(const char* expression) {
        size_t len = MultiByteToWideChar(CP_ACP, 0, expression, -1, nullptr, 0);
        std::wstring wstr(len, L'\0');
        MultiByteToWideChar(CP_ACP, 0, expression, -1, &wstr[0], (int)len);
        return wstr;
    }

    bool tryParseStrToInt(int* byref, std::wstring num_str) {
        try {
            int num;
            num = std::stoi(num_str, nullptr);
            *byref = num;
            return true;
        }
        catch (std::logic_error&) {
            return false;
        }
    }

    bool tryParseStrToDouble(double* byref, std::wstring num_str) {
        try {
            double d_num;
            d_num = std::stod(num_str, nullptr);
            *byref = d_num;
            return true;
        }
        catch (std::logic_error&) {
            return false;
        }
    }

}
