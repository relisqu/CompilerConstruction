cmake_minimum_required(VERSION 3.24)
project(CompilerConstruction)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompilerConstruction src/main.cpp src/Tokens/Span.h src/Tokens/Identifier.h src/Tokens/Integer.h src/Tokens/Real.h src/LexicalAnalysis/Parser.h src/LexicalAnalysis/Parser.cpp src/Tokens/Span.cpp "src/Tokens/Token.cpp" src/ErrorHandler.h src/Tokens/PreprocessedToken.cpp src/Tokens/PreprocessedToken.h src/main.cpp src/FileReader.cpp src/FileReader.h)
include_directories(src)

#add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)
