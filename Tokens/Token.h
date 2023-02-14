#include <iostream>
#include "Span.h"
#pragma once
class Token {

    Span span;
    unsigned int code;
public:
    Token(Span span, int code);
    Token() = default;
};
