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

std::string Span::toString() const {
    return std::to_string(lineNum) + std::to_string(posBegin);
}