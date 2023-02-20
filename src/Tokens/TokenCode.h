#pragma once

enum class TokenCode {

    //types
    tkInt,
    tkReal,
    tkVar,
    tkBoolean,
    tkString,
    tkArray,
    tkType,
    tkRecord,
    tkIdentifier,

    //booleans
    tkBoolAnd,
    tkBoolOr,
    tkBoolXor,
    tkBoolNot,
    tkTrue,
    tkFalse,

    //conditions
    tkLess,
    tkLessEquals,
    tkBigger,
    tkBiggerEquals,
    tkEquals,
    tkNotEquals,

    //operations
    tkPlus,
    tkMinus,
    tkMultiple,
    tkMod,
    tkDivide,

    //Cycles
    tkIs,
    tkIf,
    tkThen,
    tkElse,
    tkEnd,
    tkFor,
    tkIn,
    tkLoop,
    tkReverse,
    tkDOT_DOT,
    tkWhile,
    tkReturn,
    tkContinue,
    tkBreak,

    //Other
    tkColon,
    tkDot,
    tkComma,
    tkSemiColon,
    tkCOLON_EQUALS,
    tkNewLine,
    tkQuote,
    tkSQUARE_BRACKET_START,
    tkSQUARE_BRACKET_END,
    tkROUND_BRACKET_START,
    tkROUND_BRACKET_END,
    tkCURLY_BRACKET_START,
    tkCURLY_BRACKET_END,
    tkBackSlash,
    tkSpace
};