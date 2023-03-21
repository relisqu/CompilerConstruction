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
    TokenNameMap::tokenMap[TokenCode::tkDOT_DOT] = "..";
    TokenNameMap::tokenMap[TokenCode::tkCOLON_EQUALS] = ":=";
    TokenNameMap::tokenMap[TokenCode::tkLessEquals] = "<=";
    TokenNameMap::tokenMap[TokenCode::tkGreaterEquals] = ">=";
    TokenNameMap::tokenMap[TokenCode::tkColon] = ":";
    TokenNameMap::tokenMap[TokenCode::tkDot] = ".";
    TokenNameMap::tokenMap[TokenCode::tkEquals] = "=";

    TokenNameMap::tokenMap[TokenCode::tkConstInt] = "constinteger";
    TokenNameMap::tokenMap[TokenCode::tkConstBoolean] = "constboolean";
    TokenNameMap::tokenMap[TokenCode::tkConstReal] = "constreal";

};