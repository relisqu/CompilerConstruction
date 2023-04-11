#pragma once

#include <string>
/**
 * Class Span is class which stores position of tokens.
 * Stores \b lineNum, \b posBegin and \b posEnd
 */
class Span {
public:
    int lineNum{};
    int lineEndNum{};
    int posBegin{}, posEnd{};

    Span() = default;

    Span(int lineNum, int posBegin, int posEnd) : lineNum(lineNum), lineEndNum(lineNum), posBegin(posBegin), posEnd(posEnd) {}

    Span(Span a, Span b);

    Span(const Span& other) = default;

    void ClearSpanPosition();

    void MoveSpanToNewLine();

    bool operator< (const Span &a);

    operator std::string() const
    {
        return std::to_string(lineNum)+":"+std::to_string(posBegin)+'-'+
               std::to_string(lineEndNum)+":"+std::to_string(posEnd);
    }
};