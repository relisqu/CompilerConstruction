#include "Token.h"


Span Token::getSpan() {
    return this->span;
}

TokenCode Token::getTokenCode() {
    return this->code;
}

std::string Token::getStringValue() {
    return this->strValue;
}

int Token::getIntValue() {
    return this->intValue;
}

float Token::getRealValue() {
    return this->realValue;
}

bool Token::getBoolValue() {
    return this->boolValue;
}