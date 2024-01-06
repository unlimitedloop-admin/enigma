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
//      File name       : component_context.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_COMPONENTCONTEXT_H_
#define _R2REFINED_APP_COMPONENTS_COMPONENTCONTEXT_H_

#include "component.h"



namespace app {

    namespace components {

        class IComponent;


        /// <summary>
        ///  Controls the behavior of a component's state.
        /// </summary>
        class IComponentContext {
        public:
            virtual bool changeComponents(IComponent* component) = 0;
            virtual ~IComponentContext() {}
        };

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_COMPONENTCONTEXT_H_
