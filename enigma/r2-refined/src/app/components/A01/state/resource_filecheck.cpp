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
//      File name       : resource_filecheck.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include "resource_filecheck.h"
#include "src/app/components/phase_context.h"



namespace app {

    namespace components {

        namespace A01 {

            namespace state {

                bool ResourceFilecheckPhase::execute(IPhaseContext* object) {
                    // TODO : Resource file check.
                    object->setPhase(nullptr);
                    return true;
                }

            }

        }

    }

}
