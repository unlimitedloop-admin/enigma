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
//      File name       : div_graph_param.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_DIVGRAPHPARAM_H_
#define _R2REFINED_APP_RAW_DIVGRAPHPARAM_H_

namespace app {

    namespace raw {

        class DivGraphParam {
        public:
            int allNum;
            int xNum;
            int yNum;
            int xSize;
            int ySize;
        };

        typedef DivGraphParam* LPDivGraphParam;
    }

}

#endif // !_R2REFINED_APP_RAW_DIVGRAPHPARAM_H_
