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
//      File name       : kernel.h
//
//      Author          : u7
//
//      Last update     : 2023/12/23
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_BOOT_KERNEL_H_
#define _R2REFINED_FORMS_BOOT_KERNEL_H_

#include <Windows.h>
#include "src/forms/terminal/app_engine.h"



namespace boot {

    class EngineFinalizer {
    public:
        EngineFinalizer(terminal::AppEngine& engine) : _engine(engine) {}
        ~EngineFinalizer() { _engine.finalize(); }

    private:
        terminal::AppEngine& _engine;
    };

    bool systems(LPTSTR cmdline);

}

#endif // !_R2REFINED_FORMS_BOOT_KERNEL_H_
