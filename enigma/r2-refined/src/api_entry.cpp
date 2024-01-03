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
//      File name       : api_entry.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include <Windows.h>
#include "forms/boot/kernel.h"



/* Global variables. */
// AppEngine class pointer.
terminal::AppEngine* g_AppEngineInstance = nullptr;



INT APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpszCmdLine, _In_ int nCmdShow) {
    if (!boot::systems(lpszCmdLine)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
