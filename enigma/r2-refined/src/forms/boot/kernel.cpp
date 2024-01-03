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
//      File name       : kernel.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#include "kernel.h"
#include <memory>
#include <Windows.h>
#include <VersionHelpers.h>
#include "src/forms/terminal/app_engine.h"
#include "src/static/evaluations.h"
#include "src/static/universal/global_object.h"



namespace boot {

    constexpr __int32 ARCHITECTURE_CHECK_OK = 0;
    constexpr __int32 ARCHITECTURE_CHECK_NG = -1;


    bool sysInit(LPTSTR cmdline) {
        if (!lstrcmp(cmdline, L"debug")) {
            _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
            MessageBox(NULL, L"Start in debug mode.", L"Message", MB_ICONINFORMATION | MB_OK);
        }
        auto checker = 0;

        // Checking for hardware processors.
        SYSTEM_INFO system_info;
        GetNativeSystemInfo(&system_info);
        switch (system_info.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
        case PROCESSOR_ARCHITECTURE_ARM:
        case PROCESSOR_ARCHITECTURE_ARM64:
        case PROCESSOR_ARCHITECTURE_INTEL:
            checker = ARCHITECTURE_CHECK_OK;
            break;
        default:
            checker = ARCHITECTURE_CHECK_NG;
            break;
        }
        if (checker) {
            return false;
        }

        // This application is only supported on Windows 7 or later OS.
        if (!IsWindows7OrGreater()) {
            return false;
        }

        // Checking whether RAM capacity of 256MB or over can be allocated.
        MEMORYSTATUSEX mem_status{};
        mem_status.dwLength = sizeof(mem_status);
        GlobalMemoryStatusEx(&mem_status);
        if ((static_cast<unsigned long long>(256 * 1024) * 1024) >= mem_status.ullTotalPhys) {
            return false;
        }

        return true;
    }


    bool sysMain(LPTSTR cmdline) {
        auto mode = _static::RunMode::DEFAULT_MODE;
        if (!lstrcmp(cmdline, L"debug")) {
            mode = _static::RunMode::DEBUG_MODE;
        }
        
        g_AppEngineInstance = new terminal::AppEngine(mode);
        EngineFinalizer finalizer(*g_AppEngineInstance);
        return g_AppEngineInstance->initialize() ? g_AppEngineInstance->eventLoop() : false;
    }


    bool sysFin(bool isResults) {
        // Here you can add system actions to be executed on exit.
        if (nullptr != g_AppEngineInstance) {
            delete g_AppEngineInstance;
            g_AppEngineInstance = nullptr;
        }
        return isResults;
    }


    bool systems(LPTSTR cmdline) {
        return sysInit(cmdline) ? sysFin(sysMain(cmdline)) : sysFin(false);
    }

}
