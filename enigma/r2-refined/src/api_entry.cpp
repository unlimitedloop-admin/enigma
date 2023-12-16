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
//      Last update     : 2023/12/12
//
//
// *************************************************************

#include <Windows.h>
#include "forms/boot/kernel.h"



INT APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpszCmdLine, _In_ int nCmdShow) {
    if (!boot::systems(lpszCmdLine)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
