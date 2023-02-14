//
// Created by kopko on 13.02.2023.
//
#include "Parser.h"

enum class SymbolState {
    Number,
    Literal,
    Other,
    Empty
};

enum class TokenState {
    Identifier,
    IntConstant,
    Error,
    Other
};

void CreateToken(std::string buffer,TokenState token_code, Span span);

std::vector<Token> Parser::ParseText(std::string textProgram){
    std::string buffer;
    SymbolState firstSymbolState;
    TokenState currentBufferStatus;
    int wordLength = 0;
    int symbolCurrentPosition = 0;
    int currentLinePosition = 0;
    Span currentSpan{0, 0, 0};

    for ( int i=0; i<textProgram.length(); i++) { //wtf is this if, need to fix tomorrow
        char symbol = textProgram[i];
        if(std::isdigit(symbol)){
            if(wordLength==0){
                firstSymbolState= SymbolState::Number;
                currentSpan.posBegin=symbolCurrentPosition;
            }else{
                switch (firstSymbolState) {
                    case SymbolState::Number:
                        currentBufferStatus= TokenState::IntConstant;
                        break;
                    case SymbolState::Literal:
                        currentBufferStatus= TokenState::Identifier;
                        break;
                }
            }
            buffer.push_back(symbol);
            wordLength+=1;
        }
        else if(std::isalpha(symbol)){
            if(wordLength==0){
                firstSymbolState= SymbolState::Literal;
                currentSpan.posBegin=symbolCurrentPosition;
            }else{
                switch (firstSymbolState) {
                    case SymbolState::Number:
                        ThrowError("Expected unqualified-id", currentSpan);
                        break;
                    case SymbolState::Literal:
                        currentBufferStatus= TokenState::Identifier;
                        break;
                }
            }
            buffer.push_back(symbol);
            wordLength+=1;
        }
        else{
            CreateToken(buffer, currentBufferStatus, currentSpan);
            currentSpan.posBegin=symbolCurrentPosition;
            currentSpan.posEnd=symbolCurrentPosition;
            CreateToken(std::to_string(symbol), TokenState::Other, currentSpan);
            wordLength=0;
            symbolCurrentPosition++;
            if(symbol=='\n'){
                currentLinePosition++;
                symbolCurrentPosition = 0;
                currentSpan.MoveSpanToNewLine();
            }

        }
    }
}
std::vector<Token> tokens;

void CreateToken(std::string buffer,TokenState token_code, Span span){
    Token();
}

std::string Parser::RemoveComments(std::string textProgram) {
    // TODO: decide comments type and add preprocessing stage
    return textProgram;
}

void Parser::ThrowError(std::string errorMessage, Span errorSpan) {
    std::cout<<errorMessage;
    exit( -1 );
}
