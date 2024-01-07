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
//      File name       : object_provisioner.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include "object_provisioner.h"
#include "src/app/components/phase_context.h"
#include "src/app/components/F01/opening_scene.h"
#include "src/app/components/F01/state/credit_logo.h"
#include "src/app/raw/div_graph_param.h"



namespace app {

    namespace raw {

        using namespace components;


        bool ObjectProvisioner::execute(IPhaseContext* object) {
            if (nullptr != dynamic_cast<F01::OpeningScene*>(object)) {
                DivGraphParam params = { 10, 10, 1, 8, 8 };
                if (!_material->bgLoad(L"number", L"assets\\BG\\hieroglyph\\FlatNumberPack.png", &params)) return false;
                params = { 32, 16, 2, 8, 8 };
                if (!_material->bgLoad(L"alphabet", L"assets\\BG\\hieroglyph\\FlatAlphabetPack.png", &params)) return false;
                return object->setPhase(new F01::state::CreditLogo(_material));
            }
            return false;
        }

    }

}