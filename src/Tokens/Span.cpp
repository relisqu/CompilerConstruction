//
// Created by kopko on 14.02.2023.
//

#include "Span.h"

void Span::ClearSpanPosition() {
    posEnd=0;
    posBegin=0;
    lineNum=0;
}
void Span::MoveSpanToNewLine() {
    posEnd=0;
    posBegin=0;
    lineNum++;
}

Span::Span(long lineNum, int posBegin, int posEnd) {
  lineNum=lineNum;
  posBegin=posBegin;
  posEnd=posEnd;
}
