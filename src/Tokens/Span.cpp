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

Span::Span(Span span1, Span span2) {
    if (span1.lineNum == span2.lineNum) {
        lineNum = span1.lineNum;
        lineEndNum = lineNum;
        posBegin = std::min(span1.posBegin, span2.posBegin);
        posEnd =   std::max(span1.posEnd,   span2.posEnd);
    } else {
        lineNum = std::min(span1.lineNum, span2.lineNum);
        lineEndNum = std::max(span1.lineEndNum, span2.lineEndNum);
        if (span1.lineNum < span2.lineNum) {
            posBegin = span1.posBegin;
        } else {
            posBegin = span2.posBegin;
        }

        if (span1.lineEndNum > span2.lineEndNum) {
            posEnd = span1.posEnd;
        } else {
            posEnd = span2.posEnd;
        }
    }
}