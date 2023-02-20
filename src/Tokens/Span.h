#pragma once

#include <string>

class Span {
public:
    int lineNum{};
    int posBegin{}, posEnd{};

    Span() = default;

    Span(int lineNum, int posBegin, int posEnd);

    void ClearSpanPosition();

    void MoveSpanToNewLine();

    std::string toString() const {
        return std::to_string(lineNum) + std::to_string(posBegin);
    }
};