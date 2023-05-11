//
// Created by dyllas on 17.02.23.
//
#include "gtest/gtest.h"
/**
 * Main function for loading tests
 * @return code of \b RUN_ALL_TESTS();
 */
int main (int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
