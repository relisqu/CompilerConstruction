#include <iostream>
#include "Span.h"
#include "TokenCode.h"

#pragma once
/**
 * Class Token is important part of lexer analysis. It's lexical unit of out \b Toy \b language.
 * Stores \b lineNum, \b posBegin and \b posEnd
 */
class Token {
public:
    Token() = default;

    Token(Span span, TokenCode code, std::string strValue, int intValue = 0, long double realValue = 0, bool boolValue = false) : span(span), code(code), strValue(std::move(strValue)), intValue(intValue), realValue(realValue), boolValue(boolValue) {}
    // A lot of getters
    Span getSpan();
    TokenCode getTokenCode();
    std::string getStringValue();
    long double getRealValue() const;
    int getIntValue() const;
    bool getBoolValue() const;
private:
    Span span{};
    TokenCode code{};
    std::string strValue;
    int intValue{};
    long double realValue{};
    bool boolValue{};

};