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
//      File name       : opening_scene.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include <DxLib.h>
#include <memory>
#include "opening_scene.h"
#include "src/app/components/component_context.h"
#include "src/app/components/phase.h"
#include "src/app/raw/object_provisioner.h"
#include "src/static/evaluations.h"



namespace app {

    namespace components {

        namespace F01 {

            OpeningScene::OpeningScene() {
                _objDealer = std::make_shared<raw::ObjectDealer>();
                _phase = new raw::ObjectProvisioner(_objDealer);
                _phase->execute(this);
                DxLib::SetBackgroundColor(0x00, 0x00, 0x00);
            }


            _static::ResultSet OpeningScene::doExecuteComponents(IComponentContext* object) {
                if (_phase && !_phase->execute(this)) {
                    return _static::ResultSet::PROC_FAILED;
                }
                if (!_phase) {
                    object->changeComponents(nullptr);      // TODO : Next scene object for IComponent.
                }
                return _static::ResultSet::PROC_SUCCEED;
            }


            bool OpeningScene::setPhase(IPhase* phase) {
                if (_phase) {
                    delete _phase;
                    _phase = phase;
                }
                return nullptr != _phase;
            }

        }

    }

}
