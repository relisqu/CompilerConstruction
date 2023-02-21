#include "Token.h"

Token::Token(Span span, TokenCode code): span(span), code(code) {}

Span Token::getSpan() {
    return this->span;
}

TokenCode Token::getTokenCode() {
    return this->code;
}
