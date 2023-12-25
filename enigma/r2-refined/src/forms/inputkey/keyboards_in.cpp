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
//      File name       : keyboards_in.cpp
//
//      Author          : u7
//
//      Last update     : 2023/12/25
//
//
// *************************************************************

#include "keyboards_in.h"
#include <DxLib.h>



namespace inputkey {

    bool KeyboardsIn::updateAllStateKey() {
        std::array<char, KEY_NUM> key_state_array{};
        if (-1 == DxLib::GetHitKeyStateAll(key_state_array.data())) {
            return false;
        }
        // Adds a numerical value (or clears to 0) to each press/release array according to the keyboard input command.
        for (int i = 0; i < KEY_NUM; i++) {
            if (key_state_array[i] != 0) {
                if (_diKeyReleased[i] > 0) _diKeyReleased[i] = 0;
                _diKeyPressed[i]++;
            }
            else {
                if (_diKeyPressed[i] > 0) _diKeyPressed[i] = 0;
                _diKeyReleased[i]++;
            }
        }
        return true;
    }


    __int64 KeyboardsIn::getHoldKeyValue(int keynumber)
    {
        return (KEY_NUM <= keynumber) ? -1 : _diKeyPressed[keynumber];
    }


    __int64 KeyboardsIn::getFreeKeyValue(int keynumber)
    {
        return (KEY_NUM <= keynumber) ? -1 : _diKeyReleased[keynumber];
    }

}
