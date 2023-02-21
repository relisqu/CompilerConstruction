#pragma once

#include <string>

class Span {
public:
    int lineNum{};
    int posBegin{}, posEnd{};

    Span() = default;

    Span(int lineNum, int posBegin, int posEnd) : lineNum(lineNum), posBegin(posBegin), posEnd(posEnd) {}

    void ClearSpanPosition();

    void MoveSpanToNewLine();

    std::string toString() const;
};