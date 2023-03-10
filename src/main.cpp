#include <iostream>
#include "FileReader/FileReader.cpp"
#include "LexicalAnalysis/Scanner.h"
#include "LexicalAnalysis/Demonstration.h"
#include "Parser/Parser.tab.hpp"

/**
 Compilers Construction, team A
 Implementing Compiler for 'Imperative toy language' on C++ to target code C
 @authors Anna Kopeikina, Danila Korneenko, Tasha Sakovets, Yaroslav Kim, Dmitriy Pirozhenko
 @version \b 1.3 \e 11/03/2023
 **/

Scanner scanner;

int main(int argc, char *argv[]) {

    ReadFile(R"(ILanguageCodeSnippets/ult.i)");
    scanner.GetLexicalAnalysisTokens();
    DemonstrateLexer(scanner.get_tokens());
    return 0;
}

namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}