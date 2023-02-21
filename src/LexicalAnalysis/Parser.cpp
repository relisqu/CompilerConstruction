#include "Parser.h"
#include "Error/ErrorHandler.h"
#include "../Tokens/PreprocessedToken.h"
#include "Tokens/TokenMap.h"

enum class SymbolState {
    Number,
    Literal
};


Span MakeNewSpan(const Span& span1, const Span& span2) {
    if (span1.lineNum == span2.lineNum) {
        return {span1.lineNum, span1.posBegin, span2.posEnd};
    }
}


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
        ++symbolCurrentPosition;
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
        ++currentLine;
    }

    int currentSymbol = 0;

    for (int i = 0; i < textProgram.length(); ++i) {
        ++currentSymbol;
        if (textProgram[i] == '\n') {
            ++currentLine;
            currentSymbol = 0;
        }
        if (textProgram.size() - 1 != i) {
            if (textProgram[i] == '/' && textProgram[i + 1] == '*') {
                ++isComment;
            }
            if (textProgram[i] == '*' && textProgram[i + 1] == '/') {
                --isComment;
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
    textProgram = RemoveMultiLineComments(textProgram);
    textProgram = RemoveSingleLineComments(textProgram);
    return textProgram;
}

void Parser::PrintPreprocessedTokens() {
    for (const auto &ppToken: preprocessedTokens) {
        std::cout << ppToken.toString();
    }
}

std::vector<Token> Parser::GetTokens() {
    TokenMap &map = TokenMap::getInstance();

    std::vector<Token> tokens;
    std::vector<bool> used_preprocessed_tokens(preprocessedTokens.size(), false);

    for (int i = 0; i < preprocessedTokens.size(); ++i) {
        if (map.tokenMap.find(preprocessedTokens[i].value) != map.tokenMap.end()) {
            switch (map.tokenMap[preprocessedTokens[i].value]) {
                case TokenCode::tkTrue:
                    tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkConstBoolean, preprocessedTokens[i].value, 0, 0, true);
                    used_preprocessed_tokens[i] = true;
                    break;
                case TokenCode::tkFalse:
                    tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkConstBoolean, preprocessedTokens[i].value, 0, 0, false);
                    used_preprocessed_tokens[i] = true;
                    break;

                default:
                    tokens.emplace_back(preprocessedTokens[i].span, map.tokenMap[preprocessedTokens[i].value], preprocessedTokens[i].value);
                    used_preprocessed_tokens[i] = true;
                    break;
            }
        }
    }

    for (int i = 1; i < preprocessedTokens.size() - 1; ++i) {
        if (!used_preprocessed_tokens[i]) {
            if (preprocessedTokens[i].value == "=") {
                if (preprocessedTokens[i - 1].value == ">") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].span, preprocessedTokens[i].span), TokenCode::tkGreaterEquals, ">=");
                } else if (preprocessedTokens[i - 1].value == "<") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].span, preprocessedTokens[i].span), TokenCode::tkLessEquals, "<=");
                } else if (preprocessedTokens[i - 1].value == "/") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].span, preprocessedTokens[i].span), TokenCode::tkNotEquals, "/=");
                } else if (preprocessedTokens[i - 1].value == ":") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].span, preprocessedTokens[i].span), TokenCode::tkCOLON_EQUALS, ":=");
                } else {
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkEquals, preprocessedTokens[i].value);
                }
            } else if (preprocessedTokens[i].value == ".") {
                if (preprocessedTokens[i - 1].state == PreprocessedToken::TokenState::IntConstant and
                        preprocessedTokens[i + 1].state == PreprocessedToken::TokenState::IntConstant) {
                        used_preprocessed_tokens[i - 1] = true;
                        used_preprocessed_tokens[i] = true;
                        used_preprocessed_tokens[i + 1] = true;
                        std::string real_str = preprocessedTokens[i - 1].value + preprocessedTokens[i].value + preprocessedTokens[i + 1].value;
                        long double real_value = std::stold(real_str);
                        Span tmp_span = MakeNewSpan(preprocessedTokens[i - 1].span, preprocessedTokens[i].span);
                        tokens.emplace_back(MakeNewSpan(tmp_span, preprocessedTokens[i + 1].span), TokenCode::tkConstReal, real_str, 0,real_value);
                } else if (preprocessedTokens[i + 1].value == ".") {
                    used_preprocessed_tokens[i + 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i].span, preprocessedTokens[i + 1].span), TokenCode::tkDOT_DOT, "..");
                }
            }
        }
    }

    for (int i = 0; i < preprocessedTokens.size(); ++i) {
        if (!used_preprocessed_tokens[i]) {
            if (preprocessedTokens[i].value == "<") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkLess, preprocessedTokens[i].value);
            } else if (preprocessedTokens[i].value == ">") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkGreater, preprocessedTokens[i].value);
            } else if (preprocessedTokens[i].value == "/") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkDivide, preprocessedTokens[i].value);
            } else if (preprocessedTokens[i].state == PreprocessedToken::TokenState::IntConstant) {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkConstInt, preprocessedTokens[i].value, std::stoi(preprocessedTokens[i].value));
            } else if (preprocessedTokens[i].state == PreprocessedToken::TokenState::Identifier) {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].span, TokenCode::tkIdentifier, preprocessedTokens[i].value);
            }
        }
    }

    return tokens;
}

