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
//      File name       : main_sequence.h
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_APP_SEQUENCE_MAINSEQUENCE_H_
#define _R2REFINED_APP_SEQUENCE_MAINSEQUENCE_H_

#include "sequencer.h"
#include <memory>
#include "src/app/input/joystick.h"
#include "src/static/configuration.h"



namespace app {

    namespace sequence {

        class MainSequence final : public ISequencer {
        public:
            MainSequence() : _joyStick(std::make_shared<input::Joystick>()) {}
            MainSequence(const MainSequence&) = delete;
            MainSequence& operator=(const MainSequence&) = delete;
            ~MainSequence() {}

            _static::ResultSet onExecute() override;

        private:
            std::shared_ptr<input::Joystick> _joyStick;
        };

    }

}

#endif // !_R2REFINED_APP_SEQUENCE_MAINSEQUENCE_H_
