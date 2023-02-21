
#include "TokenNameMap.h"
#include "TokenMap.h"

void TokenNameMap::GenerateMap() {
    TokenMap& tokenMap = TokenMap::getInstance();
    for (auto it = tokenMap.tokenMap.begin(); it != tokenMap.tokenMap.end(); ++it) {
        TokenNameMap::tokenMap[it->second] = it->first;
    }
    TokenNameMap::tokenMap[TokenCode::tkIdentifier] = "identifier";
    TokenNameMap::tokenMap[TokenCode::tkNewLine] = "newline";
    TokenNameMap::tokenMap[TokenCode::tkSpace] = "space";
};