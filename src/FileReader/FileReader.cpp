#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#pragma once
/**
 * Read file from specific folder
 * @param fileName : Path of input file
 * @return One line string with all text in file
 */

std::string static text_file;

void static ReadFile(const std::string &fileName) {
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    text_file = buffer.str();
}
