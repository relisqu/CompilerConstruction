#include "Span.h"

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

