#pragma once

//If we use classes, we WILL use them everywhere, Ana
class Span {
public:
    long lineNum;
    int posBegin, posEnd;

    Span(long lineNum, int posBegin, int posEnd);

    Span() = default;

    void ClearSpanPosition();

    void MoveSpanToNewLine();
};

