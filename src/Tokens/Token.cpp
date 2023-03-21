#include "Token.h"


Span Token::getSpan() {
    return span;
}

TokenCode Token::getTokenCode() {
    return code;
}

std::string Token::getStringValue() {
    return strValue;
}

int Token::getIntValue() const {
    return intValue;
}

long double Token::getRealValue() const {
    return realValue;
}

bool Token::getBoolValue() const {
    return boolValue;
}