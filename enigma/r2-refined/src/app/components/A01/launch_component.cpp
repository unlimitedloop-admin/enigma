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
//      File name       : launch_component.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#include "launch_component.h"
#include "src/app/components/component_context.h"
#include "src/app/components/phase.h"
#include "src/app/components/A01/state/resource_filecheck.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace A01 {

            LaunchComponent::LaunchComponent() {
                _phase = new state::ResourceFilecheckPhase();
            }


            LaunchComponent::~LaunchComponent() {
                if (_phase) {
                    delete _phase;
                    _phase = nullptr;
                }
            }


            _static::ResultSet LaunchComponent::doExecuteComponents(IComponentContext* object) {
                if (_phase && !_phase->execute(this)) {
                    return _static::ResultSet::PROC_FAILED;
                }
                if (!_phase) {
                    object->changeComponents(nullptr);
                }
                return _static::ResultSet::PROC_SUCCEED;
            }


            bool LaunchComponent::setPhase(IPhase* phase) {
                if (_phase) {
                    delete _phase;
                    _phase = phase;
                }
                return nullptr != _phase;
            }

        }

    }

}
