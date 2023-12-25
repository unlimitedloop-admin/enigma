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
//      File name       : keyboards_in.h
//
//      Author          : u7
//
//      Last update     : 2023/12/25
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_
#define _R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_

#include <array>



namespace inputkey {

    class KeyboardsIn {
    public:
        KeyboardsIn() : _diKeyPressed{}, _diKeyReleased{} {}
        KeyboardsIn(const KeyboardsIn&) = delete;
        KeyboardsIn& operator=(const KeyboardsIn&) = delete;
        KeyboardsIn(KeyboardsIn&&) = delete;
        KeyboardsIn& operator=(KeyboardsIn&&) = delete;
        ~KeyboardsIn() {}

        bool updateAllStateKey();
        __int64 getHoldKeyValue(int keynumber);
        __int64 getFreeKeyValue(int keynumber);

    private:
        static const size_t KEY_NUM = 256;
        std::array<__int64, KEY_NUM> _diKeyPressed;
        std::array<__int64, KEY_NUM> _diKeyReleased;
    };

}

#endif // !_R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_
