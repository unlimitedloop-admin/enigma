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
//      File name       : component.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_COMPONENT_H_
#define _R2REFINED_APP_COMPONENTS_COMPONENT_H_

#include "component_context.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        class IComponentContext;


        /// <summary>
        ///  An interface for creating component state.
        /// </summary>
        class IComponent {
        public:
            virtual _static::ResultSet doExecuteComponents(IComponentContext* object) = 0;
            virtual ~IComponent() {}
        };

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_COMPONENT_H_
