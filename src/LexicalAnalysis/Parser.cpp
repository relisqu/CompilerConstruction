//
// Created by kopko on 13.02.2023.
//
#include "Parser.h"
#include "../ErrorHandler.h"
#include "../Tokens/PreprocessedToken.h"

enum class SymbolState {
    Number,
    Literal
};



PreprocessedToken::TokenState GetTokenState(SymbolState firstSymbol,SymbolState currentSymbol, Span currentSpan){
    switch (firstSymbol) {
        case SymbolState::Number:

            switch (currentSymbol) {
                case SymbolState::Number:
                    return PreprocessedToken::TokenState::IntConstant;
                case SymbolState::Literal:
                    ErrorHandler::ThrowError("Expected unqualified-id", currentSpan);
                    break;
            }

            break;

        case SymbolState::Literal:
            return PreprocessedToken::TokenState::Identifier;
    }
}


void Parser::ParseText(const std::string& textProgram){

    std::string buffer;
    SymbolState firstSymbolState;
    SymbolState currentSymbolState;
    PreprocessedToken::TokenState currentBufferStatus;
    int wordLength = 0;
    int symbolCurrentPosition = 0;
    int currentLinePosition = 0;
    Span currentSpan{0, 0, 0};
    currentSpan.lineNum=0;
    for (char symbol : textProgram) {

        symbolCurrentPosition++;
        if(std::isdigit(symbol)){
            currentSymbolState= SymbolState::Number;
        }
        else if(std::isalpha(symbol)){
            currentSymbolState= SymbolState::Literal;
        }
        else{
            if(!buffer.empty()) tokens.emplace_back(buffer, currentBufferStatus, currentSpan);
            currentSpan.posBegin=symbolCurrentPosition;
            currentSpan.posEnd=symbolCurrentPosition;
            std::string string(1, symbol);
            tokens.emplace_back(string, PreprocessedToken::TokenState::Other, currentSpan);
            wordLength=0;
            buffer="";
            currentBufferStatus= PreprocessedToken::TokenState::Other;
            if(symbol=='\n'){
                currentLinePosition+=1;
                currentSpan.MoveSpanToNewLine();
            }
            continue;
        }

        if(wordLength==0){
            firstSymbolState= currentSymbolState;
            currentSpan.posBegin=symbolCurrentPosition;

        }else{
            currentBufferStatus= GetTokenState(firstSymbolState,currentSymbolState, currentSpan);
            currentSpan.posEnd=symbolCurrentPosition;
        }
        buffer.push_back(symbol);
        wordLength+=1;
    }
}




std::string Parser::RemoveSingleLineComments(std::string textProgram) {
    std::string buffer;
    bool isComment = false;
    for (int i = 0; i < textProgram.length(); i++) {
        if(i != textProgram.length() - 1 && textProgram[i] == '/' && textProgram[i + 1] == '/'){
            isComment = true;
        }
        if(textProgram[i]=='\n'){
            isComment = false;
        }
        if(!isComment){
            buffer.push_back(textProgram[i]);
        }
    }
    return buffer;
}

std::string Parser::RemoveMultiLineComments(std::string textProgram) {

    std::string buffer;
    int isComment = 0;
    int currentLine = 0;

    if (textProgram[0] == '\n') {
        currentLine++;
    }

    int currentSymbol = 0;

    for (int i = 0; i < textProgram.length(); i++) {
        currentSymbol++;        
        if (textProgram[i] == '\n') {
            currentLine++;
            currentSymbol = 0;
        }
        if (textProgram.size() - 1 != i) {
            if (textProgram[i] == '/' && textProgram[i + 1] == '*') {
                isComment++;
            }
            if (textProgram[i] == '*' && textProgram[i + 1] == '/') {
                isComment--;
            }
        }
        if (isComment == 0) {
            buffer.push_back(textProgram[i]);
        }
        if (isComment < 0) {
            //this -> ThrowError("Unexpected end of comment", Span(currentLine, currentSymbol, currentSymbol));
        }
    }
    return buffer;
}

std::string Parser::RemoveComments(std::string textProgram) {
    textProgram = this -> RemoveMultiLineComments(textProgram);
    textProgram = this -> RemoveSingleLineComments(textProgram);
    return textProgram;
}

void Parser::PrintPreprocessedTokens() {
    for ( const auto& ppToken: tokens) {
        std::cout<<ppToken.toString();
    }
}

