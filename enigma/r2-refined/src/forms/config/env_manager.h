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
//      File name       : env_manager.h
//
//      Author          : u7
//
//      Last update     : 2023/12/23
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_CONFIG_ENVMANAGER_H_
#define _R2REFINED_FORMS_CONFIG_ENVMANAGER_H_

#include <string>
#include <map>



namespace config {

    class EnvManager final {
    public:
        static const bool getParameter(const wchar_t* label, std::wstring* args);

    private:
        std::map<std::wstring, std::wstring> _parameters;

        EnvManager();
        EnvManager(const EnvManager&) = delete;
        EnvManager& operator=(const EnvManager&) = delete;
        EnvManager(EnvManager&&) = delete;
        EnvManager& operator=(EnvManager&&) = delete;
    };

}

#endif // !_R2REFINED_FORMS_CONFIG_ENVMANAGER_H_
