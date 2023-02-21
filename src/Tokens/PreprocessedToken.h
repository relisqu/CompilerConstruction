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

    PreprocessedToken(std::string value, TokenState state, Span span) : value(std::move(value)), state(state),
                                                                       span(span) {}

    std::string toString() const;

private:
    std::string value;
    Span span;
    TokenState state;

    friend class Parser;
};

