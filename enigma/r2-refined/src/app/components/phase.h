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
//      File name       : phase.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_PHASE_H_
#define _R2REFINED_APP_COMPONENTS_PHASE_H_

#include "phase_context.h"



namespace app {

    namespace components {

        class IPhaseContext;


        /// <summary>
        ///  An interface for creating child phase of component.
        /// </summary>
        class IPhase {
        public:
            /// <summary>
            ///  Execute the phase state.
            /// </summary>
            /// <param name="phase">The behavior body of the phase state</param>
            /// <returns>False will be returned only if there is a problem with the process itself.</returns>
            virtual bool execute(IPhaseContext* phase) = 0;
            virtual ~IPhase() {}
        };

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_PHASE_H_
