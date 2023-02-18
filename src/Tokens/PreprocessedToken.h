
#pragma once
#include <string>
#include <utility>
#include "Span.h"

class PreprocessedToken {
public:
    enum class TokenState {
        Identifier,
        IntConstant,
        Other
    };
    PreprocessedToken() =default;

    inline PreprocessedToken(std::string text, TokenState state, Span span){
        this->span=span;
        this->text=std::move(text);
        this->state=state;
    };
private:
    std::string text;
    Span span;
    TokenState state;

};

