#include "Span.h"

Span::Span(int lineNum, int posBegin, int posEnd) : lineNum(lineNum), posBegin(posBegin), posEnd(posEnd) {}

void Span::ClearSpanPosition() {
    posEnd = 0;
    posBegin = 0;
    lineNum = 0;
}

void Span::MoveSpanToNewLine() {
    posEnd = 0;
    posBegin = 0;
    ++lineNum;
}