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
//      File name       : env_manager.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/23
//
//
// *************************************************************

#include "env_manager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "src/exceptions/error_handler.h"



namespace config {

    EnvManager::EnvManager() {
        const std::wstring filepath = L".env";
        const auto kSymbols = L'$';
        std::wifstream fs(filepath);
        if (fs) {
            std::wstring str_key, str_value;
            while (std::getline(fs, str_key)) {
                if (kSymbols == str_key[0]) {
                    std::wstringstream ss{ str_key };
                    std::getline(ss, str_key, L' ');
                    std::getline(ss, str_value);
                    _parameters[str_key] = str_value;
                }
            }
        }
    }


    const bool EnvManager::getParameter(const wchar_t* label, std::wstring* byref_args) {
        static EnvManager instance;
        auto itr = instance._parameters.find(label);
        if (itr != instance._parameters.end()) {
            *byref_args = instance._parameters[label];
            return true;
        }
        else {
            return false;
        }
    }

}
