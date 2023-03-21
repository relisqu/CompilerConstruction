#include <iostream>
#include "FileReader/FileReader.cpp"
#include "LexicalAnalysis/Scanner.h"
#include "LexicalAnalysis/Demonstration.h"

/**
 Compilers Construction, team A
 Implementing Compiler for 'Imperative toy language' on C++ to target code C
 @authors Anna Kopeikina, Danila Korneenko, Tasha Sakovets, Yaroslav Kim, Dmitriy Pirozhenko
 @version \b 1.3 \e 11/03/2023
 **/

Scanner scanner;

//TODO: Исправить баг с пустым файлом/не найденным файлом
int main(int argc, char *argv[]) {
    std::string text_file = ReadFile("/home/justsomedude/Documents/GitHub/CompilerConstruction/ILanguageCodeSnippets/ArraySum.imp");
    std::cout << text_file;

    scanner.GetLexicalAnalysisTokens(text_file);

    yy::parser p;
    p.parse();
    //DemonstrateLexer(scanner.get_tokens());
    return 0;
}

namespace yy
{
    parser::symbol_type yylex()
    {
        return scanner.get_next_token();
    }
}