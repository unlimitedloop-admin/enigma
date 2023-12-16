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
//      File name       : error_handler.h
//
//      Author          : u7
//
//      Last update     : 2023/12/16
//
//
// *************************************************************

#ifndef _R2REFINED_EXCEPTIONS_ERRORHANDLER_H_
#define _R2REFINED_EXCEPTIONS_ERRORHANDLER_H_

#include <functional>
#include <string>



namespace exceptions {

    /// <summary>
    ///  Error handling class.
    /// </summary>
    class ErrorHandler final {
    private:
        /// <summary>
        ///  You can output strings to the Visual Studio output console.
        /// </summary>
        /// <param name="message">String to send to the output console</param>
        void logMessage(const std::wstring& message);

    public:
        ErrorHandler() = default;
        /// <summary>
        ///  Use try-catch syntax to handle errors in case of errors. and outputs details to a log file.
        /// </summary>
        /// <param name="action">The function you want to include in the try construct</param>
        /// <returns>Returns false if error handling is controlled, true if nothing happens.</returns>
        static bool tryCatchWithLogging(std::function<void()> action);
    };

}

#endif // !_R2REFINED_EXCEPTIONS_ERRORHANDLER_H_
