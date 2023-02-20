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

    PreprocessedToken() = default;

    PreprocessedToken(std::string text, TokenState state, Span span) : text(std::move(text)), state(state), span(span) {}

    std::string toString() const {
        return text;
    }

private:
    std::string text;
    Span span;
    TokenState state;
};

