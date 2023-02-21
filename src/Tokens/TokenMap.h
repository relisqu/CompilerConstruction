#pragma once

#include <string>
#include <map>
#include "TokenCode.h"

class TokenMap {
public:
    static TokenMap &getInstance() {
        static TokenMap instance;
        return instance;
    }

    std::map<std::string, TokenCode> tokenMap;

    void GenerateMap();

private:
    TokenMap() { GenerateMap(); };

    TokenMap(const TokenMap &);

    TokenMap &operator=(const TokenMap &);
};