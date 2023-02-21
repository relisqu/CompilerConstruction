#include <algorithm>
#include "Demonstration.h"
#include "../Tokens/TokenNameMap.h"

static bool spanComparator(Span a, Span b) {
    if (a.lineNum != b.lineNum) {
        return a.lineNum < b.lineNum;
    } else {
        return a.posBegin < b.posBegin;
    }
}

static bool tokenComparator(Token a, Token b) {
    return spanComparator(a.getSpan(), b.getSpan());
}

void Demonstration::DemonstrateLexer(Parser parser) {
    std::vector<Token> tokens = parser.GetTokens();

    std::sort(tokens.begin(), tokens.end(), tokenComparator);

    TokenNameMap& tokenNameMap = TokenNameMap::getInstance();

    // Printing info on each token:
    for (auto & token : tokens) {
        Span span = token.getSpan();
        TokenCode tokenCode = token.getTokenCode();
        std::string tokenString = tokenNameMap.tokenMap[tokenCode];
        if (tokenString.length() > 0) {
            std::cout << "TokenCode: " << tokenString << '\n';
        }
        else
        {
            std::cout << "ERROR: no token -> string mapping\n";
        }
        std::cout << "ID: " << static_cast<int>(tokenCode) << '\n';
        std::cout << "Token line: " << span.lineNum + 1 << '\n';
        std::cout << "Token symbol range: " << span.posBegin << " - " << span.posEnd << '\n';
        std::cout << "----------------------------" << '\n';
    }

    // Printing the tokenized program:
    for (auto & token : tokens) {
        switch (token.getTokenCode()) {
            case TokenCode::tkSpace:
                std::cout << ' ';
                break;
            case TokenCode::tkNewLine:
                std::cout << '\n';
                break;
            default:
                std::cout << tokenNameMap.tokenMap[token.getTokenCode()];
        }
    }
}