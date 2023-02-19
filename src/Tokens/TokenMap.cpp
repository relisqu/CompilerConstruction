//
// Created by kopko on 19.02.2023.
//

#include "TokenMap.h"

void TokenMap::GenerateMap() {
    //types
    TokenMap::TokenMap["integer"] = TokenCode::tkInt;
    TokenMap::TokenMap["real"] = TokenCode::tkReal;
    TokenMap::TokenMap["var"] = TokenCode::tkVar;
    TokenMap::TokenMap["boolean"] = TokenCode::tkBoolean;
    TokenMap::TokenMap["string"] = TokenCode::tkString;
    TokenMap::TokenMap["array"] = TokenCode::tkArray;
    TokenMap::TokenMap["type"] = TokenCode::tkType;
    TokenMap::TokenMap["record"] = TokenCode::tkRecord;

    //booleans

    TokenMap::TokenMap["and"] = TokenCode::tkBoolAnd;
    TokenMap::TokenMap["or"] = TokenCode::tkBoolOr;
    TokenMap::TokenMap["xor"] = TokenCode::tkBoolXor;
    TokenMap::TokenMap["not"] = TokenCode::tkBoolNot;
    TokenMap::TokenMap["true"] = TokenCode::tkTrue;
    TokenMap::TokenMap["false"] = TokenCode::tkFalse;

    //conditions

    TokenMap::TokenMap["<"] = TokenCode::tkLess;
    TokenMap::TokenMap[">"] = TokenCode::tkBigger;
    TokenMap::TokenMap["="] = TokenCode::tkEquals;
    TokenMap::TokenMap["false"] = TokenCode::tkFalse;

    //operations

    TokenMap::TokenMap["+"] = TokenCode::tkPlus;
    TokenMap::TokenMap["-"] = TokenCode::tkMinus;
    TokenMap::TokenMap["*"] = TokenCode::tkMultiple;
    TokenMap::TokenMap["%"] = TokenCode::tkMod;
    TokenMap::TokenMap["/"] = TokenCode::tkDivide;

    //Cycles

    TokenMap::TokenMap["is"] = TokenCode::tkIs;
    TokenMap::TokenMap["if"] = TokenCode::tkIf;
    TokenMap::TokenMap["then"] = TokenCode::tkThen;
    TokenMap::TokenMap["else"] = TokenCode::tkElse;
    TokenMap::TokenMap["end"] = TokenCode::tkEnd;
    TokenMap::TokenMap["for"] = TokenCode::tkFor;
    TokenMap::TokenMap["in"] = TokenCode::tkIn;
    TokenMap::TokenMap["loop"] = TokenCode::tkLoop;
    TokenMap::TokenMap["reverse"] = TokenCode::tkReverse;
    TokenMap::TokenMap["while"] = TokenCode::tkWhile;
    TokenMap::TokenMap["return"] = TokenCode::tkReturn;
    TokenMap::TokenMap["continue"] = TokenCode::tkContinue;
    TokenMap::TokenMap["break"] = TokenCode::tkBreak;

    //Other

    TokenMap::TokenMap[":"] = TokenCode::tkColon;
    TokenMap::TokenMap["."] = TokenCode::tkDot;
    TokenMap::TokenMap[","] = TokenCode::tkComma;
    TokenMap::TokenMap[";"] = TokenCode::tkSemiColon;
    TokenMap::TokenMap["\n"] = TokenCode::tkNewLine;
    TokenMap::TokenMap["\""] = TokenCode::tkQuote;
    TokenMap::TokenMap["["] = TokenCode::tkSQUARE_BRACKET_START;
    TokenMap::TokenMap["]"] = TokenCode::tkSQUARE_BRACKET_END;
    TokenMap::TokenMap["("] = TokenCode::tkROUND_BRACKET_START;
    TokenMap::TokenMap[")"] = TokenCode::tkROUND_BRACKET_END;
    TokenMap::TokenMap["{"] = TokenCode::tkCURLY_BRACKET_START;
    TokenMap::TokenMap["}"] = TokenCode::tkCURLY_BRACKET_END;
    TokenMap::TokenMap["\\"] = TokenCode::tkBackSlash;
    TokenMap::TokenMap[" "] = TokenCode::tkSpace;

}
