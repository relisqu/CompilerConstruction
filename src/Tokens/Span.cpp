//
// Created by kopko on 14.02.2023.
//

#include "Span.h"

void Span::ClearSpanPosition() {
    this->posEnd=0;
    this->posBegin=0;
    this->lineNum=0;
}
void Span::MoveSpanToNewLine() {
    this->posEnd=0;
    this->posBegin=0;
    this->lineNum++;
}

Span::Span(int lineNum, int posBegin, int posEnd) {
  this->lineNum=lineNum;
  this->posBegin=posBegin;
  this->posEnd=posEnd;
}
