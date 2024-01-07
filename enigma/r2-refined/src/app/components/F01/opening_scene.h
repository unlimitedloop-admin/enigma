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
//      File name       : opening_scene.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_F01_OPENINGSCENE_H_
#define _R2REFINED_APP_COMPONENTS_F01_OPENINGSCENE_H_

#include <memory>
#include "src/app/components/component.h"
#include "src/app/components/component_context.h"
#include "src/app/components/phase.h"
#include "src/app/components/phase_context.h"
#include "src/app/raw/object_dealer.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace F01 {

            class OpeningScene : public IComponent, public IPhaseContext {
            public:
                explicit OpeningScene();
                OpeningScene(const OpeningScene&) = delete;
                OpeningScene& operator=(const OpeningScene&) = delete;
                ~OpeningScene() {}

                _static::ResultSet doExecuteComponents(IComponentContext* object) override;
                bool setPhase(IPhase* phase) override;

            private:
                IPhase* _phase;
                std::shared_ptr<raw::ObjectDealer> _objDealer;
            };

        }

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_F01_OPENINGSCENE_H_
