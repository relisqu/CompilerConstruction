#pragma once


#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>

#include "Error/ErrorHandler.h"
#include "Tokens/TokenMap.h"
#include "Debug/DebugMode.h"
#include "Tokens/PreprocessedToken.h"
#include "Tokens/Token.h"
#include "Parser/Parser.tab.hpp"

class Scanner {
public:
    void GetLexicalAnalysisTokens(std::string text_file);

    static std::string RemoveSingleLineComments(std::string textProgram);

    static std::string RemoveMultiLineComments(std::string textProgram);

    yy::parser::symbol_type get_next_token();

    std::vector<Token> get_tokens(){return tokens;};

    Scanner() = default;

private:
    std::vector<Token> tokens;
    size_t iter = -1;
    std::string RemoveComments(std::string textProgram);

    void ParseText(const std::string &textProgram);


    std::vector<Token> finalize_tokens();
    std::vector<PreprocessedToken> preprocessedTokens;



    std::unordered_map<TokenCode, yy::parser::symbol_type> token_to_bison =
            {
                    { TokenCode::tkGreaterEquals, yy::parser::make_tkGreaterEquals() },
                    { TokenCode::tkLess, yy::parser::make_tkLess() },
                    { TokenCode::tkLessEquals, yy::parser::make_tkLessEquals() },
                    { TokenCode::tkEquals, yy::parser::make_tkEquals() },
                    { TokenCode::tkNotEquals, yy::parser::make_tkNotEquals() },
                    { TokenCode::tkDivide, yy::parser::make_tkDivide() },
                    { TokenCode::tkSQUARE_BRACKET_START, yy::parser::make_tkSQUARE_BRACKET_START() },
                    { TokenCode::tkSQUARE_BRACKET_END, yy::parser::make_tkSQUARE_BRACKET_END() },
                    { TokenCode::tkROUND_BRACKET_START, yy::parser::make_tkROUND_BRACKET_START() },
                    { TokenCode::tkROUND_BRACKET_END, yy::parser::make_tkROUND_BRACKET_END() },
                    { TokenCode::tkPlus, yy::parser::make_tkPlus() },
                    { TokenCode::tkMinus, yy::parser::make_tkMinus() },
                    { TokenCode::tkMultiple, yy::parser::make_tkMultiple() },
                    { TokenCode::tkMod, yy::parser::make_tkMod() },
                    { TokenCode::tkComma, yy::parser::make_tkComma() },
                    { TokenCode::tkColon, yy::parser::make_tkColon() },
                    { TokenCode::tkCOLON_EQUALS, yy::parser::make_tkCOLON_EQUALS() },
                    { TokenCode::tkBoolAnd, yy::parser::make_tkBoolAnd() },
                    { TokenCode::tkBoolOr, yy::parser::make_tkBoolOr()  },
                    { TokenCode::tkBoolXor, yy::parser::make_tkBoolXor()  },
                    { TokenCode::tkIf, yy::parser::make_tkIf()  },
                    { TokenCode::tkThen, yy::parser::make_tkThen()  },
                    { TokenCode::tkElse, yy::parser::make_tkElse()  },
                    { TokenCode::tkVar, yy::parser::make_tkVar()  },
                    { TokenCode::tkType, yy::parser::make_tkType()  },
                    { TokenCode::tkRoutine, yy::parser::make_tkRoutine()  },
                    { TokenCode::tkReturn, yy::parser::make_tkReturn()  },
                    { TokenCode::tkIs, yy::parser::make_tkIs()  },
                    { TokenCode::tkIn, yy::parser::make_tkIn()  },
                    { TokenCode::tkReverse, yy::parser::make_tkReverse()  },
                    { TokenCode::tkFor, yy::parser::make_tkFor()  },
                    { TokenCode::tkWhile, yy::parser::make_tkWhile()  },
                    { TokenCode::tkLoop, yy::parser::make_tkLoop()  },
                    { TokenCode::tkEnd, yy::parser::make_tkEnd()  },
                    { TokenCode::tkRecord, yy::parser::make_tkRecord()  },
                    { TokenCode::tkArray, yy::parser::make_tkArray()  },
                    { TokenCode::tkInt, yy::parser::make_tkInt()  },
                    { TokenCode::tkReal, yy::parser::make_tkReal()  },
                    { TokenCode::tkBoolean, yy::parser::make_tkBoolean() },

                    { TokenCode::tkDOT_DOT, yy::parser::make_tkDOT_DOT() },
                    { TokenCode::tkDot, yy::parser::make_tkDot() },

            };


};