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
//      File name       : object_dealer.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_OBJECTDEALER_H_
#define _R2REFINED_APP_RAW_OBJECTDEALER_H_

#include <cstdint>
#include <string>
#include <vector>
#include "src/app/raw/div_graph_param.h"
#include "src/app/raw/bg/index_tiles.h"



namespace app {

    namespace raw {

        class ObjectDealer {
        public:
            ObjectDealer() {}
            ~ObjectDealer() {}

            bool bgLoad(const std::wstring name, const std::wstring filepath, const LPDivGraphParam parameter);
            bool bgDraw(const std::wstring name, const size_t number, int32_t x, int32_t y, int8_t z, bool transparent) const;
            bool bgChangePalettes(const std::wstring name, const uint32_t paletteNo, const uint16_t red, const uint16_t green, const uint16_t blue, const uint16_t alpha) const;

        private:
            std::vector<bg::IndexedTiles> _bg;
            //std::vector<sprite::IndexedClays> _sprite;
            //std::vector<sound::IndexedSounds> _sound;
        };

    }

}

#endif // !_R2REFINED_APP_RAW_OBJECTDEALER_H_
