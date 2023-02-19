#include <iostream>
#include "Span.h"
#include "TokenCode.h"

#pragma once

class Token {

    Span span;
    TokenCode code;
public:
    Token(Span span, TokenCode code);
    Token() = default;

};
