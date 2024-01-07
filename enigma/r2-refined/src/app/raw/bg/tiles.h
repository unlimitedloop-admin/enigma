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
//      File name       : tiles.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_BG_TILES_H_
#define _R2REFINED_APP_RAW_BG_TILES_H_

#include <cstdint>



namespace app {

    namespace raw {

        namespace bg {

            /// <summary>
            ///  Product class (Factory Method) for creating BG tiles.
            /// </summary>
            class ITiles {
            public:
                virtual bool unzip(int allNum, int xNum, int yNum, int xSize, int ySize) = 0;
                virtual bool use(int16_t axisX, int16_t axisY, size_t number, bool transparent) const = 0;
                virtual bool changePalette(uint32_t paletteNo, uint16_t red, uint16_t green, uint16_t blue, uint16_t alpha = 0) = 0;
                virtual ~ITiles() {}
            };

        }

    }

}

#endif // !_R2REFINED_APP_RAW_BG_TILES_H_
