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
//      File name       : index_tiles.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_BG_INDEXTILES_H_
#define _R2REFINED_APP_RAW_BG_INDEXTILES_H_

#include <string>
#include "tiles.h"



namespace app {

    namespace raw {

        namespace bg {

            struct IndexedTiles {
                std::wstring index;
                ITiles* value;

                IndexedTiles(std::wstring idx, ITiles* val) : index(idx), value(val) {}
            };

        }

    }

}

#endif // !_R2REFINED_APP_RAW_BG_INDEXTILES_H_
