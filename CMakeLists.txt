cmake_minimum_required(VERSION 3.24)
project(CompilerConstruction)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

set(BINARY ${CMAKE_PROJECT_NAME})


include(CTest)
include(CPack)
enable_testing()

file(GLOB Ills "${CMAKE_CURRENT_SOURCE_DIR}/ITest/Ill/*.imp")
file(GLOB Wells "${CMAKE_CURRENT_SOURCE_DIR}/ITest/Well/*.imp")

foreach(file ${Ills})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" name ${file})
    add_test(NAME ${name}
            COMMAND ${BINARY}_run ${file})
    set_tests_properties(${name} PROPERTIES WILL_FAIL TRUE)
endforeach()

foreach(file ${Wells})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" name ${file})
    add_test(NAME ${name}
            COMMAND ${BINARY}_run ${file})
    set_tests_properties(${name} PROPERTIES WILL_FAIL FALSE)
endforeach()

add_executable(result cmake-build-debug/src/result.c)
target_compile_options(result PRIVATE -std=c11)

add_custom_command(TARGET result POST_BUILD COMMAND gcc -g ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/src/result.c -o result)

