//
// Created by kopko on 14.02.2023.
//

#include "Token.h"

Token::Token(Span span, TokenCode code) {
    this->span=span;
    this->code=code;
}
