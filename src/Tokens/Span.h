#pragma once

#include <string>

//If we use classes, we WILL use them everywhere, Ana
class Span {
public:
    int lineNum;
    int posBegin, posEnd;

public:
    Span(int lineNum, int posBegin, int posEnd);

    Span() = default;

    void ClearSpanPosition();

    void MoveSpanToNewLine();


    std::string Span::toString() const {
        return std::to_string( lineNum) +std::to_string(posBegin);
    }
};

