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

#include <cstdint>
#include <DxLib.h>
#include <string>
#include "bg_loader.h"



namespace app {

    namespace raw {

        namespace bg {

            BGLoader::BGLoader(std::wstring filepath) {
                _softImage = 0;
                _allnum = 0;
                _xnum = 0;
                _ynum = 0;
                _xsize = 0;
                _ysize = 0;
                _graphicHandler.clear();
                setFiles(filepath);
            }


            BGLoader::~BGLoader() {
                for (auto& v : _graphicHandler) {
                    DxLib::DeleteGraph(v);
                }
                DxLib::DeleteSoftImage(_softImage);
                _graphicHandler.clear();
                _graphicHandler.shrink_to_fit();
            }


            bool BGLoader::unzip(int allNum, int xNum, int yNum, int xSize, int ySize) {
                _softImage = DxLib::LoadSoftImage(getFiles().c_str());
                _graphicHandler.resize(static_cast<size_t>(allNum));
                if (-1 == DxLib::CreateDivGraphFromSoftImage(_softImage, allNum, xNum, yNum, xSize, ySize, &_graphicHandler[0])) return false;
                _allnum = allNum;
                _xnum = xNum;
                _ynum = yNum;
                _xsize = xSize;
                _ysize = ySize;
                return true;
            }


            bool BGLoader::use(int16_t axisX, int16_t axisY, size_t number, bool transparent) const {
                if (_graphicHandler.size() < number) return false;
                if (DxLib::DrawGraph(axisX, axisY, _graphicHandler[number], transparent)) return false;
                return true;
            }


            bool BGLoader::changePalette(uint32_t paletteNo, uint16_t red, uint16_t green, uint16_t blue, uint16_t alpha) {
                if (-1 == DxLib::SetPaletteSoftImage(_softImage, paletteNo, red, blue, green, alpha)) return false;
                if (1 == _allnum) {
                    _graphicHandler[0] = DxLib::CreateGraphFromSoftImage(_softImage);
                    if (-1 == _graphicHandler[0]) return false;
                }
                else {
                    if (DxLib::CreateDivGraphFromSoftImage(_softImage, _allnum, _xnum, _ynum, _xsize, _ysize, &_graphicHandler[0])) return false;
                }
                return true;
            }

        }

    }

}
