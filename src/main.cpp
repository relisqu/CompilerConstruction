#include <iostream>
#include "FileReader/FileReader.h"
#include "LexicalAnalysis/Parser.h"
#include "LexicalAnalysis/Demonstration.h"

int main(int argc, char *argv[]) {

    std::string fileText = FileReader::ReadFile(
            R"(../../ILanguageCodeSnippets/ArraySum.i)");
    std::cout << fileText << "\n\n";

    Parser parser = Parser();
    Demonstration::DemonstrateLexer(parser.GetLexicalAnalysisTokens(fileText));
    return 0;
}
