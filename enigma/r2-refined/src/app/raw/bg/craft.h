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
//      File name       : craft.h
//
//      Author          : u7
//
//      Last update     : 2024/01/07
//
//
// *************************************************************

#ifndef _R2REFINED_APP_RAW_BG_CRAFT_H_
#define _R2REFINED_APP_RAW_BG_CRAFT_H_

#include <string>
#include "tiles.h"



namespace app {

    namespace raw {

        namespace bg {

            /// <summary>
            ///  Factory class (Factory Method) for creating BG tiles.
            /// </summary>
            class Craft {
            public:
                virtual ITiles* create(std::wstring files) {
                    ITiles* object = createTile(files);
                    return object;
                }
                virtual ~Craft() {}

            protected:
                virtual ITiles* createTile(std::wstring files) = 0;
            };

        }

    }

}

#endif // !_R2REFINED_APP_RAW_BG_CRAFT_H_
