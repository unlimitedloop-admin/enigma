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
//      File name       : phase_context.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_PHASECONTEXT_H_
#define _R2REFINED_APP_COMPONENTS_PHASECONTEXT_H_

#include "phase.h"



namespace app {

    namespace components {

        class IPhase;


        /// <summary>
        ///  Controls the behavior of a phase's state of component.
        /// </summary>
        class IPhaseContext {
        public:
            virtual bool setPhase(IPhase* phase) = 0;
            virtual ~IPhaseContext() {}
        };

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_PHASECONTEXT_H_
