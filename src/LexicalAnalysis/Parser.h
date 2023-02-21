#pragma once

#include "../Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"
#include <vector>
#include <string>

class Parser {
public:
    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);

    std::vector<Token> GetTokens();

    void PrintPreprocessedTokensValues();
    void PrintPreprocessedTokensStates();


private:
    std::vector<PreprocessedToken> preprocessedTokens;
};