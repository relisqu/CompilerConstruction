#include <iostream>
#include "Span.h"
#include "TokenCode.h"

#pragma once

class Token {
public:
    Token() = default;

    Token(Span span, TokenCode code) : span(span), code(code) {}

private:
    Span span{};
    TokenCode code{};
};