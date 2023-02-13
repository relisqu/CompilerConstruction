cmake_minimum_required(VERSION 3.24)
project(CompilerConstruction)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompilerConstruction main.cpp Tokens/Span.h Tokens/Identifier.h Tokens/Integer.h Tokens/Real.h LexicalAnalysis/Parser.h LexicalAnalysis/Parser.cpp)
