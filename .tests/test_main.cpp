#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../main.h"

TEST_CASE("BinaryRadixSort") {
    // Define test data
    std::vector<unsigned char> input = {5, 2, 7, 1, 8, 3, 6, 4};
    std::vector<unsigned char> expected_output = {1, 2, 3, 4, 5, 6, 7, 8};

    // Test binaryRadixSort function
    binaryRadixSort(input);
    REQUIRE(input == expected_output);
}
