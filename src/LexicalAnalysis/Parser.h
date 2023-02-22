#pragma once

#include "../Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"
#include <vector>
#include <string>

class Parser {
public:
    std::vector<Token> GetLexicalAnalysisTokens(std::string textProgram);

    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

private:

    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);

    std::vector<Token> GetTokens();
    std::vector<PreprocessedToken> preprocessedTokens;
};