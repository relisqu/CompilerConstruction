//
// Created by kopko on 18.02.2023.
//

#include <fstream>
#include "FileReader.h"
#include <iostream>
#include <string>
#include <sstream>

std::string FileReader::ReadFile(std::string fileName) {
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}
