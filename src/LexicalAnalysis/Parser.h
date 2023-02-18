//
// Created by kopko on 13.02.2023.
//
#pragma once

#include "../Tokens/PreprocessedToken.h"
#include <vector>
#include <string>

class Parser{
    std::vector<PreprocessedToken> tokens;

public:
    static std::string RemoveSingleLineComments(std::string textProgram);
    static std::string RemoveMultiLineComments(std::string textProgram);
    std::string RemoveComments(std::string textProgram);
    void ParseText(const std::string& textProgram);
};