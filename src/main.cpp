#include <iostream>
#include "FileReader.h"
#include "LexicalAnalysis/Parser.h"

int main(int argc, char *argv[]) {

        std::string fileText = FileReader::ReadFile("F:\\Study\\S23\\CompilerConstruction\\ILanguageCodeSnippets\\ArraySum.i");
        std::cout << fileText <<"\n";
        Parser parser= Parser();
        parser.ParseText(fileText);
        parser.PrintPreprocessedTokens();
    return 0;
}
