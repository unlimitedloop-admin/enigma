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
//      File name       : app_engine.h
//
//      Author          : u7
//
//      Last update     : 2023/12/25
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_TERMINAL_APPENGINE_H_
#define _R2REFINED_FORMS_TERMINAL_APPENGINE_H_

#include "src/forms/inputkey/keyboards_in.h"



namespace terminal {

    class AppEngine final {
    public:
        AppEngine() : _test(0) {}
        AppEngine(const AppEngine&) = delete;
        ~AppEngine() {}

        bool initialize();
        bool eventLoop();
        void finalize();

    private:
        inputkey::KeyboardsIn _keyboards;
        int _test;
    };

}

#endif // !_R2REFINED_FORMS_TERMINAL_APPENGINE_H_
