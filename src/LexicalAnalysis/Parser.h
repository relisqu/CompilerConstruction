#pragma once

#include "../Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"
#include <vector>
#include <string>

class Parser {

    std::vector<PreprocessedToken> preprocessedTokens;

public:
    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);

    std::vector<Token> GetTokens();

    void PrintPreprocessedTokens();
};