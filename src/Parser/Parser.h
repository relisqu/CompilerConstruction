//
// Created by dyllas on 10.03.23.
//

#ifndef COMPILERCONSTRUCTION_PARSER_H
#define COMPILERCONSTRUCTION_PARSER_H
#include "Parser/Parser.tab.hpp"
namespace yy {
    parser::symbol_type yylex()
    {
        return 1;
    }
} // yy

#endif //COMPILERCONSTRUCTION_PARSER_H
