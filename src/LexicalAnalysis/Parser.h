//
// Created by kopko on 13.02.2023.
//
#pragma once

#include "../Tokens/Token.h"
#include <vector>
#include <string>

class Parser{
    std::vector<Token> tokens;

    std::string RemoveSingleLineComments(std::string textProgram);
    std::string RemoveMultiLineComments(std::string textProgram);

    std::string RemoveComments(std::string textProgram);
    std::vector<Token> ParseText(std::string textProgram);
    void ThrowError(std::string errorMessage, Span errorSpan);
};