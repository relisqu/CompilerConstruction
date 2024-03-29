#include "TokenMap.h"

void TokenMap::GenerateMap() {
    TokenMap::tokenMap["integer"] = TokenCode::tkInt;
    TokenMap::tokenMap["real"] = TokenCode::tkReal;
    TokenMap::tokenMap["var"] = TokenCode::tkVar;
    TokenMap::tokenMap["boolean"] = TokenCode::tkBoolean;
    TokenMap::tokenMap["string"] = TokenCode::tkString;
    TokenMap::tokenMap["array"] = TokenCode::tkArray;
    TokenMap::tokenMap["type"] = TokenCode::tkType;
    TokenMap::tokenMap["record"] = TokenCode::tkRecord;
    TokenMap::tokenMap["routine"] = TokenCode::tkRoutine;

    //booleans
    TokenMap::tokenMap["and"] = TokenCode::tkBoolAnd;
    TokenMap::tokenMap["or"] = TokenCode::tkBoolOr;
    TokenMap::tokenMap["xor"] = TokenCode::tkBoolXor;
    TokenMap::tokenMap["not"] = TokenCode::tkBoolNot;
    TokenMap::tokenMap["true"] = TokenCode::tkTrue;
    TokenMap::tokenMap["false"] = TokenCode::tkFalse;

    //operations
    TokenMap::tokenMap["+"] = TokenCode::tkPlus;
    TokenMap::tokenMap["-"] = TokenCode::tkMinus;
    TokenMap::tokenMap["*"] = TokenCode::tkMultiple;
    TokenMap::tokenMap["%"] = TokenCode::tkMod;

    //Cycles
    TokenMap::tokenMap["is"] = TokenCode::tkIs;
    TokenMap::tokenMap["if"] = TokenCode::tkIf;
    TokenMap::tokenMap["then"] = TokenCode::tkThen;
    TokenMap::tokenMap["else"] = TokenCode::tkElse;
    TokenMap::tokenMap["end"] = TokenCode::tkEnd;
    TokenMap::tokenMap["for"] = TokenCode::tkFor;
    TokenMap::tokenMap["in"] = TokenCode::tkIn;
    TokenMap::tokenMap["loop"] = TokenCode::tkLoop;
    TokenMap::tokenMap["reverse"] = TokenCode::tkReverse;
    TokenMap::tokenMap["while"] = TokenCode::tkWhile;
    TokenMap::tokenMap["return"] = TokenCode::tkReturn;
    TokenMap::tokenMap["continue"] = TokenCode::tkContinue;
    TokenMap::tokenMap["break"] = TokenCode::tkBreak;

    //Other
    TokenMap::tokenMap[","] = TokenCode::tkComma;
    TokenMap::tokenMap[";"] = TokenCode::tkSemiColon;
    TokenMap::tokenMap["\n"] = TokenCode::tkNewLine;
    TokenMap::tokenMap["\r"] = TokenCode::tkTabulation;
    TokenMap::tokenMap[" "] = TokenCode::tkTabulation;
    TokenMap::tokenMap["\""] = TokenCode::tkQuote;
    TokenMap::tokenMap["["] = TokenCode::tkSQUARE_BRACKET_START;
    TokenMap::tokenMap["]"] = TokenCode::tkSQUARE_BRACKET_END;
    TokenMap::tokenMap["("] = TokenCode::tkROUND_BRACKET_START;
    TokenMap::tokenMap[")"] = TokenCode::tkROUND_BRACKET_END;
    TokenMap::tokenMap["{"] = TokenCode::tkCURLY_BRACKET_START;
    TokenMap::tokenMap["}"] = TokenCode::tkCURLY_BRACKET_END;
    TokenMap::tokenMap["\\"] = TokenCode::tkBackSlash;
}