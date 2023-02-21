#pragma once

#include <string>
#include <unordered_map>
#include "TokenCode.h"
/**
 * Class TokenMap is class which stores map \b String -> \b TokenCode.
 * \Pattern
 * The class uses the singleton template to use only a single object in the entire compiler.
 * The template is based on the use of static fields, which means there is no need to manually clear the memory
 */
class TokenMap {
public:
    /**
     * Get instance of \b TokenMap class
     * @return &TokenMap obj
     */
    static TokenMap &getInstance() {
        static TokenMap instance;
        return instance;
    }
    //Map of strings with tokens
    std::unordered_map<std::string, TokenCode> tokenMap;
    /**
     * Generate our map specific \b string to its \b TokenCode
     */
    void GenerateMap();

private:
    //Private constructor for singleton pattern
    TokenMap() { GenerateMap(); };
    // getting object will return same object
    TokenMap(const TokenMap &);
    // assignment will return same object
    TokenMap &operator=(const TokenMap &);
};