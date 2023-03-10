#include <iostream>
#include "FileReader/FileReader.cpp"
#include "LexicalAnalysis/Scanner.h"
#include "LexicalAnalysis/Demonstration.h"

/**
 Compilers Construction, team A
 Implementing Compiler for 'Imperative toy language' on C++ to target code C
 @authors Anna Kopeikina, Danila Korneenko, Tasha Sakovets, Yaroslav Kim, Dmitriy Pirozhenko
 @version \b 1.1 \e 21/02/2023
 **/

int main(int argc, char *argv[]) {

    std::string fileText = ReadFile(
            R"(../../ILanguageCodeSnippets/ult.i)");
    std::cout << fileText << "\n\n";

    Scanner parser = Scanner();
    DemonstrateLexer(parser.GetLexicalAnalysisTokens(fileText));
    return 0;
}
