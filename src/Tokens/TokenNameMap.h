#pragma once

#include <string>
#include <map>
#include "TokenCode.h"

class TokenNameMap {
private:
    TokenNameMap(){GenerateMap();};
    TokenNameMap( const TokenNameMap&);
    TokenNameMap& operator=( TokenNameMap& );
public:
    static TokenNameMap& getInstance() {
        static TokenNameMap instance;
        return instance;
    }
    std::map<TokenCode, std::string> tokenMap;
    void GenerateMap();
};