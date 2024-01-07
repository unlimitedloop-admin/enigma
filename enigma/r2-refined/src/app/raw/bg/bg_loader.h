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
//      File name       : bg_loader.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_BG_BGLOADER_H_
#define _R2REFINED_APP_RAW_BG_BGLOADER_H_

#include <cstdint>
#include <string>
#include <vector>
#include "src/app/raw/loader.h"
#include "tiles.h"



namespace app {

    namespace raw {

        namespace bg {

            class BGLoader : public Loader, public ITiles {
            public:
                BGLoader(std::wstring filepath);
                ~BGLoader();
                bool unzip(int allNum, int xNum, int yNum, int xSize, int ySize) override;
                bool use(int16_t axisX, int16_t axisY, size_t number, bool transparent) const override;
                bool changePalette(uint32_t paletteNo, uint16_t red, uint16_t green, uint16_t blue, uint16_t alpha = 0) override;

            private:
                int32_t _softImage;
                std::vector<int> _graphicHandler;
                int _allnum;
                int _xnum;
                int _ynum;
                int _xsize;
                int _ysize;
            };

        }

    }

}

#endif // !_R2REFINED_APP_RAW_BG_BGLOADER_H_
