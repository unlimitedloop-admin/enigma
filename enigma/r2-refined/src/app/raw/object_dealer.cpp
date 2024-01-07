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
//      File name       : object_dealer.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include <memory>
#include "object_dealer.h"
#include "src/app/raw/div_graph_param.h"
#include "src/app/raw/bg/craft.h"
#include "src/app/raw/bg/tile_craft.h"
#include "src/app/raw/bg/tiles.h"



namespace app {

    namespace raw {

        bool ObjectDealer::bgLoad(const std::wstring name, const std::wstring filepath, const LPDivGraphParam parameter) {
            std::unique_ptr<bg::Craft> factory(new bg::TileCraft());
            bg::ITiles* product = factory->create(filepath);
            if (!product->unzip(parameter->allNum, parameter->xNum, parameter->yNum, parameter->xSize, parameter->ySize)) return false;
            _bg.emplace_back(name, product);
            return true;
        }


        bool ObjectDealer::bgDraw(const std::wstring name, const size_t number, int32_t x, int32_t y, int8_t z, bool transparent) const {
            for (const auto& idx : _bg) {
                if (name == idx.index) {
                    return idx.value->use(x, y, number, transparent);
                }
            }
            return false;
        }


        bool ObjectDealer::bgChangePalettes(const std::wstring name, const uint32_t paletteNo, const uint16_t red, const uint16_t green, const uint16_t blue, const uint16_t alpha) const {
            for (const auto& idx : _bg) {
                if (name == idx.index) {
                    return idx.value->changePalette(paletteNo, red, green, blue, alpha);
                }
            }
            return false;
        }

    }

}
