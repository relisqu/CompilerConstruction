#pragma once

#include <string>
/**
 * Class Span is class which stores position of tokens.
 * Stores \b lineNum, \b posBegin and \b posEnd
 */
class Span {
public:
    int lineNum{};
    int posBegin{}, posEnd{};

    Span() = default;

    Span(int lineNum, int posBegin, int posEnd) : lineNum(lineNum), posBegin(posBegin), posEnd(posEnd) {}

    Span(const Span& other) = default;

    void ClearSpanPosition();

    void MoveSpanToNewLine();
};