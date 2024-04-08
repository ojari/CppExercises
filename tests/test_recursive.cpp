#include "common.hpp"
#include "../RecursiveAlgorithms.hpp"

TEST_CASE( "algorithm factorial ", "[recursive]" ) {
    REQUIRE( findFactorialRecursive(5) == 120);
    REQUIRE( findFactorialRecursive(1) == 1);
    REQUIRE( findFactorialRecursive(10) == 3628800);

    REQUIRE( findFactorialIterative(5) == 120);
    REQUIRE( findFactorialIterative(1) == 1);
    REQUIRE( findFactorialIterative(10) == 3628800);
}

TEST_CASE( "algorithm fibonacci ", "[recursive]" ) {
    REQUIRE( fibonacciRecursive(1) == 1);
    REQUIRE( fibonacciRecursive(0) == 0);
    REQUIRE( fibonacciRecursive(7) == 13);
    REQUIRE( fibonacciRecursive(11) == 89);

    REQUIRE( fibonacciIterative(1) == 1);
    REQUIRE( fibonacciIterative(0) == 0);
    REQUIRE( fibonacciIterative(7) == 13);
    REQUIRE( fibonacciIterative(11) == 89);
}

TEST_CASE( "algorithm reverse string ", "[recursive]" ) {
    REQUIRE( reverseRecursive("Hello") == std::string("olleH"));

    REQUIRE( reverseIterative("Hello") == std::string("olleH"));
}
