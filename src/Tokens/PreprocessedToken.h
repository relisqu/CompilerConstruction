#pragma once

#include <string>
#include <utility>
#include "Span.h"
/**
 * Class PreprocessedToken is class for first iteration of lexical analysis.
 * Stores \b value, \b token, \b state and \b span
 */
class PreprocessedToken {

public:
    enum class TokenState {
        Identifier,
        IntConstant,
        Other
    };
    PreprocessedToken() = default;
    PreprocessedToken(std::string value, TokenState state, Span span) : value(std::move(value)), state(state),
                                                                        span(span) {};
    std::string get_value() {return value;}
    Span get_span() {return span;}
    TokenState get_state() {return state;}
private:

    std::string value;
    Span span;
    TokenState state;

};

