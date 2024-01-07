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
//      File name       : loader.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_LOADER_H_
#define _R2REFINED_APP_RAW_LOADER_H_

#include <string>



namespace app {

    namespace raw {

        class Loader {
        public:
            Loader() {}
            ~Loader() {
                _files.clear();
                _files.shrink_to_fit();
            }

            void setFiles(std::wstring filepath) {
                _files = filepath;
            }

            std::wstring getFiles() {
                return _files;
            }

        private:
            std::wstring _files = {};
        };

    }

}

#endif // !_R2REFINED_APP_RAW_LOADER_H_
