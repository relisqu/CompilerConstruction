#include <iostream>
#include "Span.h"
#pragma once
class Token {

    Span span;
    unsigned int code;
    Token(Span span, int code);
};
