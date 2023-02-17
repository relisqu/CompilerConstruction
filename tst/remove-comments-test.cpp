//
// Created by dyllas on 17.02.23.
//
#include "gtest/gtest.h"
#include "LexicalAnalysis/Parser.h"

TEST(commentsTest, linecom) {
    std::vector<std::pair<std::string,std::string>> tests ={
            {"",""},
            {"var A : integer is 10;"           ,"var A : integer is 10;"},
            {"var A : integer is 10; //prIVET\n","var A : integer is 10;\n"},
            {"var A : integer is 10;// // // "  ,"var A : integer is 10;"},
            {"var A : integer is 10;\n"         ,"var A : integer is 10;\n"},
            {"var A : integer is 10;/"          ,"var A : integer is 10;/"},
            {"var A : integer is 10;///\n"      ,"var A : integer is 10;\n"},
            {"var A : integer is 10;\n//\n"     ,"var A : integer is 10;\n\n"}
    };
    for (auto [in, out]:tests){
        EXPECT_EQ (Parser::RemoveSingleLineComments (in), out);
    }


}
