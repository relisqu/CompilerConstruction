#pragma once


#include <vector>
#include <string>
#include <utility>

#include "Error/ErrorHandler.h"
#include "Tokens/TokenMap.h"
#include "Debug/DebugMode.h"
#include "Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"

class Scanner {
public:
    std::vector<Token> GetLexicalAnalysisTokens(std::string textProgram);

    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

private:

    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);

    std::vector<Token> GetTokens();
    std::vector<PreprocessedToken> preprocessedTokens;

    void RemoveTabulationTokens();
};