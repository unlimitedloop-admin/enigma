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
//      File name       : launch_component.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_A01_LAUNCHCOMPONENT_H_
#define _R2REFINED_APP_COMPONENTS_A01_LAUNCHCOMPONENT_H_

#include "src/app/components/component.h"
#include "src/app/components/component_context.h"
#include "src/app/components/phase.h"
#include "src/app/components/phase_context.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace A01 {

            class LaunchComponent : public IComponent, public IPhaseContext {
            public:
                LaunchComponent();
                LaunchComponent(const LaunchComponent&) = delete;
                ~LaunchComponent();

                _static::ResultSet doExecuteComponents(IComponentContext* object) override;
                bool setPhase(IPhase* phase) override;

            private:
                IPhase* _phase;
            };

        }

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_A01_LAUNCHCOMPONENT_H_
