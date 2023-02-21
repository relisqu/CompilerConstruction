#include <iostream>
#include "Span.h"
#include "TokenCode.h"

#pragma once

class Token {
public:
    Token() = default;

    Token(Span span, TokenCode code, std::string strValue, int intValue = 0, long double realValue = 0, bool boolValue = false) : span(span), code(code), strValue(std::move(strValue)), intValue(intValue), realValue(realValue), boolValue(boolValue) {}

    Span getSpan();
    TokenCode getTokenCode();

private:
    Span span{};
    TokenCode code{};
    std::string strValue;
    int intValue;
    long double realValue;
    bool boolValue;
};