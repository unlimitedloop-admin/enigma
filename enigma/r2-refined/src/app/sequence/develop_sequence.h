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
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_
#define _R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_

#include "sequencer.h"
#include <memory>
#include "src/app/input/joystick.h"
#include "src/static/evaluations.h"



namespace app {

    namespace sequence {

        class DevelopSequence final : public ISequencer {
        public:
            DevelopSequence() : _joyStick(std::make_shared<input::Joystick>()) {}
            DevelopSequence(const DevelopSequence&) = delete;
            DevelopSequence& operator=(const DevelopSequence&) = delete;
            ~DevelopSequence() {}

            _static::ResultSet onExecute() override;

        private:
            std::shared_ptr<input::Joystick> _joyStick;
        };

    }

}

#endif // !_R2REFINED_APP_SEQUENCE_DEVELOPSEQUENCE_H_
