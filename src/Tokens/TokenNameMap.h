#pragma once

#include <string>
#include <unordered_map>
#include "TokenCode.h"
/**
 * Class TokenMap is class which stores map \b TokenCode -> \b String. Used for demonstration for now.
 * \Pattern
 * The class uses the singleton template as the \b TokenMap \b class
 * @see TokenMap.h
 */
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
    std::unordered_map<TokenCode, std::string> tokenMap;
    void GenerateMap();
};