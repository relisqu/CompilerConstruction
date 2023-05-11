execute_process(COMMAND
        bison -d ${CMAKE_CURRENT_SOURCE_DIR}/Parser/Parser.ypp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Parser
        )
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.hpp)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES} ${BISON_parser_OUTPUTS} ../main.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES})