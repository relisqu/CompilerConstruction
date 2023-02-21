#include "Token.h"


Span Token::getSpan() {
    return this->span;
}

TokenCode Token::getTokenCode() {
    return this->code;
}
