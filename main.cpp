#include <iostream>
#include "FileReader/FileReader.cpp"
#include "LexicalAnalysis/Scanner.h"
#include "LexicalAnalysis/Demonstration.h"
#include "Debug/DebugMode.h"
#include "AST/AST.h"
#include "TypeCheck/TypeChecker.h"
#include "Parser/Parser.tab.hpp"
#include "CodeGenerator/CodeGenerator.h"

/**
 Compilers Construction, team A
 Implementing Compiler for 'Imperative toy language' on C++ to target code C
 @authors Anna Kopeikina, Danila Korneenko, Tasha Sakovets, Yaroslav Kim, Dmitriy Pirozhenko
 @version \b 1.3 \e 11/03/2023
 **/

Scanner scanner;

//TODO: Исправить баг с пустым файлом/не найденным файлом
int main(int argc, char *argv[]) {

    std::string text_file = "";
    if (argc < 2) {
        std::cerr << "dog: missing input file!\n"
                  << "usage: CompilerConstruction_run <input_file>\n";
        return EXIT_FAILURE;
    } else {
        text_file = ReadFile(std::string(argv[1]));
    }

    #if IS_DEBUG_MODE
    std::cout << text_file;
    #endif
    scanner.GetLexicalAnalysisTokens(text_file);

    yy::parser p;
    p.parse();
    //ast::show_dfs();
    sp<Program> ourProgram = ast::getProgram();
    ourProgram->accept(new ast::TypeChecker());

    std::cout<<"AAAAAAAAAAAAAAAAAAAAAAA\n";
    auto *myCodegen = new ast::CodeGenerator();
    ourProgram->accept(myCodegen);
    std::cout << "CODE GENERATED:";
    std::cout << "\n----------------\n";
    std::cout << myCodegen->returnStack.back();
    std::cout << "\n----------------\n";
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