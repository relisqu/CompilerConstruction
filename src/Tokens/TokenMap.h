//
// Created by kopko on 19.02.2023.
//

#pragma once

#include <string>
#include <map>
#include "TokenCode.h"

class TokenMap {

public:
    static std::map<std::string, TokenCode> TokenMap;
    static void GenerateMap();
};


