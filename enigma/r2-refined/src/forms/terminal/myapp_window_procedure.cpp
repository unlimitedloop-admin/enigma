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
//      File name       : myapp_window_procedure.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include "app_engine.h"
#include <Windows.h>
#include "resource.h"
#include "src/static/evaluations.h"
#include "src/static/universal/global_object.h"



namespace terminal {

    /// <summary>
    /// User-specified window procedure.
    /// </summary>
    LRESULT CALLBACK AppEngine::definitiveProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
            case ID_40001:  // 起動   F1
                if (nullptr != g_AppEngineInstance) {
                    g_AppEngineInstance->setAppsActiveFlag(true, _static::RunMode::DEBUG_MODE == g_AppEngineInstance->_mode);
                }
                break;
            case ID_40005:  // 停止
                if (nullptr != g_AppEngineInstance) {
                    g_AppEngineInstance->setAppsActiveFlag(false);
                }
                break;
            case ID_40019:  // 終了   Alt+F4
                if (nullptr != g_AppEngineInstance) {
                    g_AppEngineInstance->setAppsActiveFlag(false);
                }
                SendMessage(HWnd, WM_CLOSE, NULL, NULL);
                break;
            }
            break;
        }
        return CallWindowProc(DxLibWnd, hWnd, msg, wParam, lParam);
    }

}
