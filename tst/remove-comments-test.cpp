//
// Created by dyllas on 17.02.23.
//
#include "gtest/gtest.h"
#include "LexicalAnalysis/Scanner.h"

TEST(commentsTest, linecom) {
    std::vector<std::pair<std::string,std::string>> tests ={
            {"var A : integer is 10;"           ,"var A : integer is 10;"},
            {"var A : integer is 10; //prIVET\n","var A : integer is 10; \n"},
            {"var A : integer is 10;// // // "  ,"var A : integer is 10;"},
            {"var A : integer is 10;\n"         ,"var A : integer is 10;\n"},
            {"var A : integer is 10;/"          ,"var A : integer is 10;/"},
            {"var A : integer is 10;///\n"      ,"var A : integer is 10;\n"},
            {"var A : integer is 10;\n//\n"     ,"var A : integer is 10;\n\n"}
    };
    for (auto [in, out]:tests){
        EXPECT_EQ (Scanner::RemoveSingleLineComments (in), out);
    }
}

TEST(commentsTest, multilinecom) {
    std::vector<std::pair<std::string,std::string>> tests ={
            {"1)var A : integer is 10;"             ,"1)var A : integer is 10;"},
            {"2)var A : integer is 10; /*prIVET*/\n","2)var A : integer is 10; \n"},
            {"3)var A : integer is 10;/* /**/ */ "  ,"3)var A : integer is 10; "},
            {"4)var A : integer is 10;\n"           ,"4)var A : integer is 10;\n"},
            {"5)var A : integer is 10;/**/"         ,"5)var A : integer is 10;"},
            {"6)var A : integer is 10;/*/\n*/"      ,"6)var A : integer is 10;"},
            {"7)var A : integer is 10;\n/**/\n"     ,"7)var A : integer is 10;\n\n"}
    };
    int i = 1;
    for (auto [in, out]:tests){
        EXPECT_EQ (Scanner::RemoveMultiLineComments(in), out);
    }
}
