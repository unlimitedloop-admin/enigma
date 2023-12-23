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
//      File name       : evaluations.h
//
//      Author          : u7
//
//      Last update     : 2023/12/23
//
//
// *************************************************************

#ifndef _R2REFINED_STATIC_EVALUATIONS_H_
#define _R2REFINED_STATIC_EVALUATIONS_H_

namespace _static {

    enum class Evaluate {
        DISABLED = -1,
        ENABLED
    };


    enum class ResultSet {
        PROC_FAILED = -1,
        PROC_SUCCEED,
        PROC_QUIT
    };


    enum class RunMode {
        DEFAULT_MODE,
        DEBUG_MODE
    };

}

#endif // !_R2REFINED_STATIC_EVALUATIONS_H_
