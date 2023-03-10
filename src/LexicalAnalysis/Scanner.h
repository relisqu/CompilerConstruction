#pragma once


#include <vector>
#include <string>
#include <utility>

#include "FileReader/FileReader.cpp"
#include "Parser/Parser.tab.hpp"
#include "Error/ErrorHandler.h"
#include "Tokens/TokenMap.h"
#include "Debug/DebugMode.h"
#include "Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"

class Scanner {
public:
    std::vector<Token> GetLexicalAnalysisTokens();

    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

    yy::parser::symbol_type get_next_token();

private:
    std::vector<Token> tokens;

    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);

    std::vector<Token> get_tokens(){return tokens;};

    std::vector<Token> finalize_tokens();
    std::vector<PreprocessedToken> preprocessedTokens;

    void RemoveTabulationTokens();
};