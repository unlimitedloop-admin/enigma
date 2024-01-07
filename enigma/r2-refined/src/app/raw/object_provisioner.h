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
//      File name       : object_provisioner.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_OBJECTPROVISIONER_H_
#define _R2REFINED_APP_RAW_OBJECTPROVISIONER_H_

#include <memory>
#include <string>
#include "src/app/components/phase.h"
#include "src/app/components/phase_context.h"
#include "src/app/raw/object_dealer.h"



namespace app {

    namespace raw {

        class ObjectProvisioner : public components::IPhase {
        public:
            ObjectProvisioner(std::shared_ptr<raw::ObjectDealer> object) : _material(object) {}
            ObjectProvisioner(const ObjectProvisioner&) = delete;
            ObjectProvisioner& operator=(const ObjectProvisioner&) = delete;
            ~ObjectProvisioner() {}

            bool execute(components::IPhaseContext* object) override;

        private:
            std::shared_ptr<raw::ObjectDealer> _material;
        };

    }

}

#endif // !_R2REFINED_APP_RAW_OBJECTPROVISIONER_H_
