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
//      File name       : sequencer.h
//
//      Author          : u7
//
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_APP_SEQUENCE_SEQUENCER_H_
#define _R2REFINED_APP_SEQUENCE_SEQUENCER_H_

#include "src/static/evaluations.h"



namespace app {

    namespace sequence {

        class ISequencer {
        public:
            virtual _static::ResultSet onExecute() = 0;
            virtual ~ISequencer() {}
        };

    }

}

#endif // !_R2REFINED_APP_SEQUENCE_SEQUENCER_H_
