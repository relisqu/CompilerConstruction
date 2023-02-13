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


std::vector<Token> Parser::ParseText(std::string textProgram){
    std::string buffer;
    SymbolState firstSymbolState;
    TokenState currentBufferStatus;
    int wordLength = 0;
    Span currentSpan;
    for ( int i=0; i<textProgram.length(); i++) { //wtf is this if, need to fix tomorrow
        char symbol = textProgram[i];
        if(std::isdigit(symbol)){
            if(wordLength==0){
                firstSymbolState= SymbolState::Number;
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
            wordLength+=1;
        }
        else if(std::isalpha(symbol)){
            if(wordLength==0){
                firstSymbolState= SymbolState::Literal;
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
        }
    }

};


std::string Parser::RemoveComments(std::string textProgram) {
    // TODO: decide comments type and add preprocessing stage
    return textProgram;
}

void Parser::ThrowError(std::string errorMessage, Span errorSpan) {

}
