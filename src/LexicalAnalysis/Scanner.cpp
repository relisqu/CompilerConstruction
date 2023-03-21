#include "Scanner.h"
#include "Tokens/TokenNameMap.h"

// Symbol state for specific character
enum class SymbolState {
    Number,
    Literal
};

/**
 * Make new span from two existing, used for tokens like '>=' '<=' ':=' and etc.
 * @param span1 : First span
 * @param span2 : Second span;
 * @return New \b Span with span1.lineNum, span1.posBegin, span2.posEnd
 *
 * @todo Add behavior when condition is false
 */
Span MakeNewSpan(const Span& span1, const Span& span2) {
    if (span1.lineNum == span2.lineNum) {
        return {span1.lineNum, span1.posBegin, span2.posEnd};
    }
}
/**
 * Compare span's \b lineNum or \b posBegin  to detect which span was earlier
 * @param a : First span to compare
 * @param b : Second span to compare
 * @return Which span appeared \e earlier in code snippet
 */
static bool spanComparator(Span a, Span b) {
    if (a.lineNum != b.lineNum) {
        return a.lineNum < b.lineNum;
    } else {
        return a.posBegin < b.posBegin;
    }
}
/**
 *
 * @param a : First token to compare
 * @param b : Second token to compare
 * @return Result of @code static bool spanComparator(a,b) @endcode
 */
static bool tokenComparator(Token a, Token b) {
    return spanComparator(a.getSpan(), b.getSpan());
}

/**
 * Return state of preprocessed token
 * @param firstSymbol : First symbol of \e buffer
 * @param currentSymbol : Current symbol of \e buffer
 * @param currentSpan : Current position of token in \e programm
 * @return
 */
PreprocessedToken::TokenState GetTokenState(SymbolState firstSymbol, SymbolState currentSymbol, Span currentSpan) {
    switch (firstSymbol) {
        case SymbolState::Number:
            switch (currentSymbol) {
                case SymbolState::Number:
                    return PreprocessedToken::TokenState::IntConstant;
                case SymbolState::Literal:
                    ErrorHandler::ThrowError("Expected unqualified-id", currentSpan);
            }
            break;
        case SymbolState::Literal:
            return PreprocessedToken::TokenState::Identifier;
    }
}
/**
 * Parse text of program to tokens
 * @param textProgram : text of input program
 */
void Scanner::ParseText(const std::string &textProgram) {
    std::string buffer;
    SymbolState firstSymbolState;
    SymbolState currentSymbolState;
    PreprocessedToken::TokenState currentBufferStatus;
    int wordLength = 0;
    int symbolCurrentPosition = 0;
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

            buffer = "";

            currentSpan.posBegin = symbolCurrentPosition - 1;
            currentSpan.posEnd = symbolCurrentPosition;
            std::string string(1, symbol);
            preprocessedTokens.emplace_back(string, PreprocessedToken::TokenState::Other, currentSpan);
            wordLength = 0;
            currentBufferStatus = PreprocessedToken::TokenState::Other;
            if (symbol == '\n') {
                currentSpan.MoveSpanToNewLine();
                symbolCurrentPosition = 0;
            }
            continue;
        }

        if (wordLength == 0) {
            firstSymbolState = currentSymbolState;
            currentBufferStatus =  GetTokenState(firstSymbolState, firstSymbolState, currentSpan);
            currentSpan.posBegin = symbolCurrentPosition-1;
            currentSpan.posEnd=symbolCurrentPosition;

        } else {
            currentBufferStatus = GetTokenState(firstSymbolState, currentSymbolState, currentSpan);
            currentSpan.posEnd = symbolCurrentPosition;
        }
        buffer.push_back(symbol);
        wordLength += 1;
    }
    if (!buffer.empty()) preprocessedTokens.emplace_back(buffer, currentBufferStatus, currentSpan);
}

/**
 * Remove from input string one line comments like '//'
 * @param textProgram : String with comments
 * @return Text program without \b one \b line \b comments
 */
std::string Scanner::RemoveSingleLineComments(std::string textProgram) {
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
/**
 * Remove from input string multi line comments
 * @param textProgram : String with comments
 * @return Text program without \b multi \b line \b comments
 **/
std::string Scanner::RemoveMultiLineComments(std::string textProgram) {

    std::string buffer;
    int isComment = 0;
    int currentLine = 0;

    if (textProgram[0] == '\n') {
        ++currentLine;
    }

    int currentSymbol = 0;
    Span last_start;

    for (int i = 0; i < textProgram.length(); ++i) {
        ++currentSymbol;
        if (textProgram[i] == '\n') {
            ++currentLine;
            currentSymbol = 0;
        }
        if (textProgram.size() - 1 != i && textProgram[i] == '/' && textProgram[i + 1] == '*') {
            isComment++;
            last_start = Span(currentLine, currentSymbol, currentSymbol + 2);
        }
        if (i >= 1 && textProgram[i - 1] == '*' && textProgram[i] == '/') {
            if (last_start.lineNum != currentLine || last_start.posBegin != currentSymbol - 2) {
                isComment--;
                i++;
            }
        }
        if (isComment == 0) {
            if (i < textProgram.length())
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

/**
 * Remove all types of comments from textProgram
 * @param textProgram : Input string
 * @return String of program without comments
 */
std::string Scanner::RemoveComments(std::string textProgram) {
    textProgram = RemoveMultiLineComments(textProgram);
    textProgram = RemoveSingleLineComments(textProgram);
    return textProgram;
}

/**
 * Go through program and get all \b simple and \b complex tokens
 * @return vector of all existing tokens in program
 */
std::vector<Token> Scanner::finalize_tokens() {
    TokenMap &map = TokenMap::getInstance();

    std::vector<Token> tokens;
    std::vector<bool> used_preprocessed_tokens(preprocessedTokens.size(), false);

    for (int i = 0; i < preprocessedTokens.size(); ++i) {
        if (map.tokenMap.find(preprocessedTokens[i].get_value()) != map.tokenMap.end()) {
            switch (map.tokenMap[preprocessedTokens[i].get_value()]) {
                case TokenCode::tkTabulation:
                    if(IS_DEBUG_MODE){
                        tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkTabulation, preprocessedTokens[i].get_value(), 0, 0, true);
                    }
                    used_preprocessed_tokens[i] = true;
                    break;
                case TokenCode::tkTrue:
                    tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkConstBoolean, preprocessedTokens[i].get_value(), 0, 0, true);
                    used_preprocessed_tokens[i] = true;
                    break;
                case TokenCode::tkFalse:
                    tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkConstBoolean, preprocessedTokens[i].get_value(), 0, 0, false);
                    used_preprocessed_tokens[i] = true;
                    break;
                default:
                    tokens.emplace_back(preprocessedTokens[i].get_span(), map.tokenMap[preprocessedTokens[i].get_value()], preprocessedTokens[i].get_value());
                    used_preprocessed_tokens[i] = true;
                    break;
            }
        }
    }

    for (int i = 1; i < preprocessedTokens.size() - 1; ++i) {
        if (!used_preprocessed_tokens[i]) {
            if (preprocessedTokens[i].get_value() == "=") {
                if (preprocessedTokens[i - 1].get_value() == ">") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].get_span(), preprocessedTokens[i].get_span()), TokenCode::tkGreaterEquals, ">=");
                } else if (preprocessedTokens[i - 1].get_value() == "<") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].get_span(), preprocessedTokens[i].get_span()), TokenCode::tkLessEquals, "<=");
                } else if (preprocessedTokens[i - 1].get_value() == "/") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].get_span(), preprocessedTokens[i].get_span()), TokenCode::tkNotEquals, "/=");
                } else if (preprocessedTokens[i - 1].get_value() == ":") {
                    used_preprocessed_tokens[i - 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i-1].get_span(), preprocessedTokens[i].get_span()), TokenCode::tkCOLON_EQUALS, ":=");
                } else {
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkEquals, preprocessedTokens[i].get_value());
                }
            } else if (preprocessedTokens[i].get_value() == ".") {
                if (preprocessedTokens[i - 1].get_state() == PreprocessedToken::TokenState::IntConstant and
                        preprocessedTokens[i + 1].get_state() == PreprocessedToken::TokenState::IntConstant and !used_preprocessed_tokens[i - 1]) {
                        used_preprocessed_tokens[i - 1] = true;
                        used_preprocessed_tokens[i] = true;
                        used_preprocessed_tokens[i + 1] = true;
                        std::string real_str = preprocessedTokens[i - 1].get_value() + preprocessedTokens[i].get_value() + preprocessedTokens[i + 1].get_value();
                        long double real_value = std::stold(real_str);
                        tokens.emplace_back(MakeNewSpan(preprocessedTokens[i - 1].get_span(), preprocessedTokens[i + 1].get_span()), TokenCode::tkConstReal, real_str, 0,real_value);
                } else if (preprocessedTokens[i + 1].get_value() == ".") {
                    used_preprocessed_tokens[i + 1] = true;
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(MakeNewSpan(preprocessedTokens[i].get_span(), preprocessedTokens[i + 1].get_span()), TokenCode::tkDOT_DOT, "..");
                } else {
                    used_preprocessed_tokens[i] = true;
                    tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkDot, ".");
                }
            }
        }
    }

    for (int i = 0; i < preprocessedTokens.size(); ++i) {
        if (!used_preprocessed_tokens[i]) {
            if (preprocessedTokens[i].get_value() == "<") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkLess, preprocessedTokens[i].get_value());
            } else if (preprocessedTokens[i].get_value() == ">") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkGreater, preprocessedTokens[i].get_value());
            } else if (preprocessedTokens[i].get_value() == "/") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkDivide, preprocessedTokens[i].get_value());
            } else if (preprocessedTokens[i].get_value() == ":") {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkColon, preprocessedTokens[i].get_value());
            } else if (preprocessedTokens[i].get_state() == PreprocessedToken::TokenState::IntConstant) {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkConstInt, preprocessedTokens[i].get_value(), std::stoi(preprocessedTokens[i].get_value()));
            } else if (preprocessedTokens[i].get_state() == PreprocessedToken::TokenState::Identifier) {
                used_preprocessed_tokens[i] = true;
                tokens.emplace_back(preprocessedTokens[i].get_span(), TokenCode::tkIdentifier, preprocessedTokens[i].get_value());
            }
        }
    }

    return tokens;
}

/**
 * Get \b all tokens from \b input text of program
 * @param textProgram
 * @return
 */
void Scanner::GetLexicalAnalysisTokens(std::string text_file) {
    std::string text= RemoveComments(std::move(text_file));
    ParseText(text);
    tokens = finalize_tokens();
    std::sort(tokens.begin(), tokens.end(), tokenComparator);
}

yy::parser::symbol_type Scanner::get_next_token() {
    // if we get to the end -> send signal of ending to Bison
    iter++;

    if (iter >= tokens.size()) return yy::parser::make_YYEOF();

    auto token = tokens[iter];

#ifdef IS_DEBUG_MODE
    std::cout << "Token line: " <<  token.getSpan().lineNum + 1 << '\n';
    std::cout<< TokenNameMap::getInstance().tokenMap[token.getTokenCode()]<<"\n";
    std::cout << "Token symbol range: " <<  token.getSpan().posBegin << " - " <<  token.getSpan().posEnd << '\n';
    std::cout << "----------------------------" << '\n';
#endif
    switch (token.getTokenCode()){
        case TokenCode::tkIdentifier :
            return yy::parser::make_tkIdentifier(token.getStringValue());
        case TokenCode::tkConstInt :
            return yy::parser::make_tkConstInt(token.getIntValue());
        case TokenCode::tkConstBoolean :
            return yy::parser::make_tkConstBoolean(token.getBoolValue());
        case TokenCode::tkConstReal :
            return yy::parser::make_tkConstReal(token.getRealValue());
        default:
            return token_to_bison[token.getTokenCode()];
    }




}
