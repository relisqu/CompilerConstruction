#pragma once

#include <string>
#include <map>
#include "TokenCode.h"

class TokenMap {

public:
    static std::map<std::string, TokenCode> tokenMap;

    static void GenerateMap();
};