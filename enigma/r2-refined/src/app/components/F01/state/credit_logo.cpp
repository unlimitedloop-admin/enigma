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
//      File name       : credit_logo.cpp
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#include <array>
#include <memory>
#include <string>
#include "credit_logo.h"
#include "src/app/components/phase.h"
#include "src/app/components/phase_context.h"
#include "src/app/raw/object_dealer.h"



namespace app {

    namespace components {

        namespace F01 {

            namespace state {

                CreditLogo::CreditLogo(std::shared_ptr<raw::ObjectDealer> object) {
                    _memory.counter = 0x08;
                    _memory.lap = 0x12;
                    _memory.lounge = 0x01;
                    _objDealer = object;
                }


                bool CreditLogo::execute(IPhaseContext* object) {
                    if (!changeTileColor(1) || !drawTiles()) return false;
                    accumlationRegister();
                    if (0 > _memory.lounge) {
                        object->setPhase(nullptr);      // TODO : Next scene object for IPhase.
                    }
                    return true;
                }


                bool CreditLogo::changeTileColor(uint32_t no) {
                    int red, green, blue;
                    std::wstring track;

                    // This is a frame adjustment that simulates a fade effect.
                    if (0x0F >= _memory.lap && _memory.lap >= 0x03) {
                        red = 0xFF, green = 0xFF, blue = 0xFF;
                    }
                    else if (0x10 == _memory.lap || _memory.lap == 0x02) {
                        red = 0xBC, green = 0xBC, blue = 0xBC;
                    }
                    else if (0x11 == _memory.lap || _memory.lap == 0x01) {
                        red = 0x75, green = 0x75, blue = 0x75;
                    }
                    else {
                        red = 0x00, green = 0x00, blue = 0x00;
                    }
                    track = 0x01 == _memory.lounge ? L"number" : L"alphabet";
                    return _objDealer->bgChangePalettes(track, no, red, green, blue, 255);
                }


                bool CreditLogo::drawTiles() {
                    int32_t x = 0, y = 0;
                    if (0x01 == _memory.lounge) {
                        // Arrange the graphic tiles in the label array while shifting the X coordinate value.
                        std::array<size_t, 4> label{ 2, 0, 2, 4 };      // 2024
                        x = 112; y = 104;
                        for (const auto& a : label) {
                            if (!_objDealer->bgDraw(L"number", a, x, y, 0, 0)) return false;
                            x = x + 8;
                        }
                    }
                    else {
                        // Arrange the graphic tiles in the label array while shifting the X coordinate value.
                        std::array<size_t, 8> label{ 19, 9, 18, 9, 21, 19, 0, 24 };     // SIRIUS X
                        x = 96; y = 104;
                        for (const auto& a : label) {
                            if (!_objDealer->bgDraw(L"alphabet", a, x, y, 0, 0)) return false;
                            x = x + 8;
                        }
                    }
                    return true;
                }


                void CreditLogo::accumlationRegister() {
                    _memory.counter--;
                    if (0x00 == _memory.counter) {
                        _memory.lap--;
                        _memory.counter = 0x08;
                    }
                    if (0 > _memory.lap) {
                        _memory.lounge--;
                        _memory.lap = 0x12;
                    }
                }

            }

        }

    }

}
