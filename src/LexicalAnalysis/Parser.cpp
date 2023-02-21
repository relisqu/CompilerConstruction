#include "Parser.h"
#include "Error/ErrorHandler.h"
#include "../Tokens/PreprocessedToken.h"
#include "Tokens/TokenMap.h"

enum class SymbolState {
    Number,
    Literal
};


PreprocessedToken::TokenState GetTokenState(SymbolState firstSymbol, SymbolState currentSymbol, Span currentSpan) {
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


void Parser::ParseText(const std::string &textProgram) {
    std::string buffer;
    SymbolState firstSymbolState;
    SymbolState currentSymbolState;
    PreprocessedToken::TokenState currentBufferStatus;
    int wordLength = 0;
    int symbolCurrentPosition = 0;
    int currentLinePosition = 0;
    Span currentSpan{0, 0, 0};
    currentSpan.lineNum = 0;
    for (char symbol: textProgram) {

        symbolCurrentPosition++;
        if (std::isdigit(symbol)) {
            currentSymbolState = SymbolState::Number;
        } else if (std::isalpha(symbol)) {
            currentSymbolState = SymbolState::Literal;
        } else {
            if (!buffer.empty()) preprocessedTokens.emplace_back(buffer, currentBufferStatus, currentSpan);
            currentSpan.posBegin = symbolCurrentPosition - 1;
            currentSpan.posEnd = symbolCurrentPosition;
            std::string string(1, symbol);
            preprocessedTokens.emplace_back(string, PreprocessedToken::TokenState::Other, currentSpan);
            wordLength = 0;
            buffer = "";
            currentBufferStatus = PreprocessedToken::TokenState::Other;
            if (symbol == '\n') {
                currentSpan.MoveSpanToNewLine();
                symbolCurrentPosition = 0;
                symbolCurrentPosition = 0;
            }
            continue;
        }

        if (wordLength == 0) {
            firstSymbolState = currentSymbolState;
            currentSpan.posBegin = symbolCurrentPosition;

        } else {
            currentBufferStatus = GetTokenState(firstSymbolState, currentSymbolState, currentSpan);
            currentSpan.posEnd = symbolCurrentPosition;
        }
        buffer.push_back(symbol);
        wordLength += 1;
    }
}


std::string Parser::RemoveSingleLineComments(std::string textProgram) {
    std::string buffer;
    bool isComment = false;
    for (int i = 0; i < textProgram.length(); ++i) {
        if (i != textProgram.length() - 1 && textProgram[i] == '/' && textProgram[i + 1] == '/') {
            isComment = true;
        }
        if (textProgram[i] == '\n') {
            isComment = false;
        }
        if (!isComment) {
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
    Span last_start;

    for (int i = 0; i < textProgram.length(); ++i) {
        currentSymbol++;
        if (textProgram[i] == '\n') {
            currentLine++;
            currentSymbol = 0;
        }
        if (textProgram.size() - 1 != i && textProgram[i] == '/' && textProgram[i + 1] == '*') {
            isComment++;
            last_start = Span(currentLine, currentSymbol, currentSymbol + 2);
        }
        if (i >= 2 && textProgram[i - 2] == '*' && textProgram[i - 1] == '/') {
            isComment--;
        }
        if (isComment == 0) {
            buffer.push_back(textProgram[i]);
        }
        if (isComment < 0) {
            ErrorHandler::ThrowError("Unexpected end of comment", Span(currentLine, currentSymbol, currentSymbol));
        }
    }
    if (isComment > 0) {
        ErrorHandler::ThrowError("Unclosed multiline comment", last_start);
    }
    return buffer;
}

std::string Parser::RemoveComments(std::string textProgram) {
    textProgram = this->RemoveMultiLineComments(textProgram);
    textProgram = this->RemoveSingleLineComments(textProgram);
    return textProgram;
}

void Parser::PrintPreprocessedTokens() {
    for (const auto &ppToken: preprocessedTokens) {
        std::cout << ppToken.toString();
    }
}

std::vector<Token> Parser::GetTokens() {
    TokenMap& map = TokenMap::getInstance();
    // Теперь в map есть поле tokenMap // инициализация мапы - она нужна для того, чтобы оптимально находить токен, используя строку (switch case для строк)
    // суть как пользоваться- вот тут https://stackoverflow.com/questions/3019153/how-do-i-use-an-enum-value-in-a-switch-statement-in-c/3019194#3019194
    std::vector<Token> tokens;

    /* обработать токены - сверить identifier c ключевыми словами по типу integer, присвоить им
     токенкод из енама кодов.

     Сначала всё обходим и приравниваем токены, где может. Потом возможно придется объединять некоторые по правилам в один
     Проверить некоторые случаи - если у нас две точки подряд - это один токен .., в таком случае спаны (координаты этого элемента) нужно объединить
     Если у нас встречается integer- точка - integer, это real число, надо объединить их, создать token real, совместить их спаны

     проверять и объединять одиночные токены по типу <  = друг в друга - по дефолту они будут в разных токенах, но они обозначают один

     если у нас identifier между двумя кавычками - это строчный элемент.

     все это можно проверять по документу i language, на выходе будет массив готовых токенов.
     Комплексити - O(n). Можно для удобства прогонять проверку токенов несколько раз - например сначала отсортировать ключевые слова и т.д., главное чтобы не было циклом в цикле

     */

}

