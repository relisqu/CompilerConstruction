#pragma once

#include <string>
#include <iostream>
#include "Tokens/Span.h"

class ErrorHandler{
public:
    inline static void ThrowError(const std::string& errorMessage, Span errorSpan) {
            std::cout<<errorMessage;
            exit( -1 );
    }
};