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
//      File name       : app_engine.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include <DxLib.h>
#include <string>
#include "app_engine.h"
#include "resource.h"
#include "src/app/sequence/develop_sequence.h"
#include "src/app/sequence/main_sequence.h"
#include "src/app/sequence/test_sequence.h"
#include "src/exceptions/error_handler.h"
#include "src/forms/config/env_manager.h"
#include "src/static/evaluations.h"



namespace terminal {

    using namespace exceptions;


    HWND AppEngine::HWnd = nullptr;
    WNDPROC AppEngine::DxLibWnd = nullptr;


    bool AppEngine::initialize() {
        constexpr unsigned __int16 DXLIBFUNC_AGREE_OK = 0;
        if (
            DXLIBFUNC_AGREE_OK != DxLib::SetDoubleStartValidFlag(FALSE) ||
            DXLIBFUNC_AGREE_OK != DxLib::SetOutApplicationLogValidFlag(FALSE) ||
            DXLIBFUNC_AGREE_OK != DxLib::SetAlwaysRunFlag(FALSE) ||
            DX_CHANGESCREEN_OK != DxLib::ChangeWindowMode(TRUE) ||
            DX_CHANGESCREEN_OK != DxLib::SetGraphMode(256, 240, 16) ||
            DXLIBFUNC_AGREE_OK != DxLib::SetWindowSizeExtendRate(2.0) ||
            DXLIBFUNC_AGREE_OK != DxLib::SetWindowPosition(32, 32) ||
            DXLIBFUNC_AGREE_OK != DxLib::LoadMenuResource(IDR_MENU1) ||
            DXLIBFUNC_AGREE_OK != DxLib::SetUseMenuFlag(TRUE)
        ) {
            return false;
        }
        std::wstring str = L"";
        config::EnvManager::getParameter(L"$WINDOW_TEXT", &str);
        if (!str.empty() && DXLIBFUNC_AGREE_OK != DxLib::SetWindowText(str.c_str())) {
            DxLib::SetWindowText(L"r2-refined");
        }
        str.clear();
        if (config::EnvManager::getParameter(L"$WINDOW_ALWAYS_RUN_ENABLED", &str) && L"1" == str) {
            DxLib::SetAlwaysRunFlag(TRUE);
        }

        DxLib::DxLib_Init();
        if (DxLib::DxLib_IsInit() && DxLib::GetUseMenuFlag()) {
            HWnd = DxLib::GetMainWindowHandle();
            DxLibWnd = reinterpret_cast<WNDPROC>(GetWindowLongPtr(HWnd, GWLP_WNDPROC));
            DxLib::SetUseKeyAccelFlag(TRUE);
            DxLib::AddKeyAccel_ID(ID_40001, KEY_INPUT_F1, FALSE, FALSE, FALSE);
            SetWindowLongPtr(HWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(definitiveProc));
            return true;
        }
        return false;
    }


    bool AppEngine::eventLoop() {
        return ErrorHandler::tryCatchWithLogging([=]() {
            while (!DxLib::ProcessMessage() && !DxLib::ScreenFlip() && !DxLib::ClearDrawScreen()) {
                // Begin the main program.
                /*
                 * NOTE :
                 * >>> _sequence = MainSequence defaults to the main program when executed.
                 * >>> _sequence = DevelopSequence provides a backdoor menu for development.
                 * >>> _sequence = TestSequence are not normally used. It's a laboratory table when you do temporary program testing.
                 * The value of _sequence is set by the _activator key, and the process is controlled by the 'AppEngine::iginition' method.
                 */
                ignition();
                if (nullptr != _sequence && _static::ResultSet::PROC_SUCCEED != _sequence->onExecute()) {
                    setAppsActiveFlag(false);
                }
            }
        });
    }


    void AppEngine::finalize() {
        DxLib::DxLib_End();
        if (nullptr != _sequence) {
            delete _sequence;
            _sequence = nullptr;
        }
    }


    void AppEngine::setAppsActiveFlag(bool active, bool devMode) {
        using act = _static::Activator;
        if (active) {
            _activator = devMode ? act::CHANGE_DEVELOPPROC : act::CHANGE_MAINPROC;
            std::wstring str = L"";
            if (config::EnvManager::getParameter(L"$TEST_DRIVER", &str) && L"1" == str) {
                _activator = act::CHANGE_DRIVER;
            }
            DxLib::SetDrawScreen(DX_SCREEN_BACK);
        }
        else {
            _activator = act::NOT_ACTIVATION;
            DxLib::SetDrawScreen(DX_SCREEN_FRONT);
        }
    }


    void AppEngine::ignition() {
        using act = _static::Activator;
        if (!_sequence && act::CHANGE_MAINPROC == _activator) {
            _sequence = new app::sequence::MainSequence();
            DxLib::SetBackgroundColor(0xFF, 0xFF, 0xFF);
        }
        else if (!_sequence && act::CHANGE_DEVELOPPROC == _activator) {
            _sequence = new app::sequence::DevelopSequence();
            DxLib::SetBackgroundColor(0x80, 0x80, 0x80);
        }
        else if (!_sequence && act::CHANGE_DRIVER == _activator) {
            _sequence = new app::sequence::TestSequence();
            DxLib::SetBackgroundColor(0x64, 0x50, 0x41);
        }
        else if (_sequence && act::NOT_ACTIVATION == _activator) {
            delete _sequence;
            _sequence = nullptr;
            DxLib::SetBackgroundColor(0x00, 0x00, 0x00);
        }
    }

}
