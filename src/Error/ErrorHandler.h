#pragma once

#include <string>
#include <iostream>
#include "Tokens/Span.h"

class ErrorHandler {
public:
    /**
     *  @brief Simple Error thrower which shows where error happened and then exit program with code -1
     *  @param errorMessage : \b Message of error
     *  @param errorSpan : \b Where error happened
     *  @todo Implement throwing errors and showing errorSpan
     */
    inline static void ThrowError(const std::string &errorMessage, Span errorSpan) {
        std::cout << errorMessage;
        exit(-1);
    }
};