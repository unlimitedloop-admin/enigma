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
//      File name       : credit_logo.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_COMPONENTS_F01_STATE_CREDITLOGO_H_
#define _R2REFINED_APP_COMPONENTS_F01_STATE_CREDITLOGO_H_

#include <cstdint>
#include <memory>
#include "src/app/components/phase.h"
#include "src/app/components/phase_context.h"
#include "src/app/raw/object_dealer.h"



namespace app {

    namespace components {

        namespace F01 {

            namespace state {

                struct CreditLogoRegister {
                    int32_t lounge;     // NES memory RAM $0x00FD
                    int32_t lap;        // NES memory RAM $0x00FE
                    int32_t counter;    // NES memory RAM $0x00FF
                };

                class CreditLogo : public IPhase {
                public:
                    explicit CreditLogo(std::shared_ptr<raw::ObjectDealer> object);
                    CreditLogo(const CreditLogo&) = delete;
                    CreditLogo& operator=(const CreditLogo&) = delete;
                    ~CreditLogo() {}

                    bool execute(IPhaseContext* object) override;

                private:
                    CreditLogoRegister _memory;
                    std::shared_ptr<raw::ObjectDealer> _objDealer;
                    bool changeTileColor(uint32_t no);
                    bool drawTiles();
                    void accumlationRegister();
                };

            }

        }

    }

}

#endif // !_R2REFINED_APP_COMPONENTS_F01_STATE_CREDITLOGO_H_
