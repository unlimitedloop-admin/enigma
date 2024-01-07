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
//      File name       : tile_craft.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_BG_TILECRAFT_H_
#define _R2REFINED_APP_RAW_BG_TILECRAFT_H_

#include <string>
#include "bg_loader.h"
#include "craft.h"
#include "tiles.h"



namespace app {

    namespace raw {

        namespace bg {

            class TileCraft : public Craft {
            public:
                TileCraft() {}
                ~TileCraft() {}
                ITiles* createTile(std::wstring files) override;
            };

            inline ITiles* TileCraft::createTile(std::wstring files) {
                BGLoader* object = new BGLoader(files);
                return object;
            }

        }

    }

}

#endif // !_R2REFINED_APP_RAW_BG_TILECRAFT_H_
