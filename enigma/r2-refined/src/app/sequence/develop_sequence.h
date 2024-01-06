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
//      File name       : develop_sequence.h
//
//      Author          : u7
//
//      Last update     : 2024/01/06
//
//
// *************************************************************

#ifndef _R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_
#define _R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_

#include <memory>
#include "sequencer.h"
#include "src/app/components/component.h"
#include "src/app/components/component_context.h"
#include "src/app/input/joystick.h"
#include "src/static/evaluations.h"



namespace app {

    namespace sequence {

        class DevelopSequence final : public ISequencer, public components::IComponentContext {
        public:
            DevelopSequence();
            DevelopSequence(const DevelopSequence&) = delete;
            DevelopSequence& operator=(const DevelopSequence&) = delete;
            ~DevelopSequence();

            _static::ResultSet onExecute() override;
            bool changeComponents(components::IComponent* component) override;

        private:
            std::shared_ptr<input::Joystick> _joyStick;
            components::IComponent* _component;
        };

    }

}

#endif // !_R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_
