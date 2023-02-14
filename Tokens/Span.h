#pragma once

struct Span {
    long lineNum;
    int posBegin, posEnd;

    Span(long lineNum, int posBegin, int posEnd);


    void ClearSpanPosition();

    void MoveSpanToNewLine();
};

