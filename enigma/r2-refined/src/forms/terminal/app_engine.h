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
//      File name       : AppEngine.h
//
//      Author          : u7
//
//      Last update     : 2023/12/12
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_TERMINAL_APPENGINE_H_
#define _R2REFINED_FORMS_TERMINAL_APPENGINE_H_

namespace terminal {

    class AppEngine final {
    private:


    public:
        AppEngine() {}
        AppEngine(const AppEngine&) = delete;
        ~AppEngine() {}

        bool initialize();
        void eventLoop();
        void finalize();
    };

}

#endif // !_R2REFINED_FORMS_TERMINAL_APPENGINE_H_
