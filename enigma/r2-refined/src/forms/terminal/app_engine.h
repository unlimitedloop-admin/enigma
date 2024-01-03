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
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_TERMINAL_APPENGINE_H_
#define _R2REFINED_FORMS_TERMINAL_APPENGINE_H_

#include <Windows.h>
#include "src/app/sequence/sequencer.h"
#include "src/static/evaluations.h"



namespace terminal {

    class AppEngine final {
    public:
        AppEngine(_static::RunMode mode) : _mode(mode), _sequence(nullptr), _activator(_static::Activator::DISABLED) {}
        AppEngine(const AppEngine&) = delete;
        AppEngine& operator=(const AppEngine&) = delete;
        ~AppEngine() {}

        static HWND HWnd;
        static WNDPROC DxLibWnd;
        static LRESULT CALLBACK definitiveProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

        bool initialize();
        bool eventLoop();
        void finalize();

    private:
        _static::RunMode _mode;
        _static::Activator _activator;
        app::sequence::ISequencer* _sequence;

        void setAppsActiveFlag(bool, bool = false);
        void ignition();
    };

}

#endif // !_R2REFINED_FORMS_TERMINAL_APPENGINE_H_
