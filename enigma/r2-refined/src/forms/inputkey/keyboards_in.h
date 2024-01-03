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
//      Last update     : 2024/01/03
//
//
// *************************************************************

#ifndef _R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_
#define _R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_

#include <array>
#include <cstdint>



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
        int64_t getHoldKeyValue(size_t keynumber);
        int64_t getFreeKeyValue(size_t keynumber);

    private:
        static const size_t KEY_NUM = 256;
        std::array<int64_t, KEY_NUM> _diKeyPressed;
        std::array<int64_t, KEY_NUM> _diKeyReleased;
    };

}

#endif // !_R2REFINED_FORMS_INPUTKEY_KEYBOARDSIN_H_
