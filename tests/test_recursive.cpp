#include "catch_amalgamated.hpp"
#include "../RecursiveAlgorithms.hpp"

TEST_CASE( "Recursive algorithm factorial ", "[recursive]" ) {
    REQUIRE( findFactorialRecursive(5) == 120);
    REQUIRE( findFactorialRecursive(1) == 1);
    REQUIRE( findFactorialRecursive(10) == 3628800);

    REQUIRE( findFactorialIterative(5) == 120);
    REQUIRE( findFactorialIterative(1) == 1);
    REQUIRE( findFactorialIterative(10) == 3628800);
}
