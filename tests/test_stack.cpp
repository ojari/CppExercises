#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../Stack.hpp"


TEST_CASE( "Testing stack Push, Pop", "[stack]") {
    Stack<int> stack;
    int result;

    stack.Push(10);
    stack.Push(20);

    REQUIRE( stack.Pop() == 20 );
    REQUIRE( stack.Pop() == 10 );
}

TEST_CASE( "Testing stack Peek", "[stack]") {
    Stack<int> stack;
    int result;

    stack.Push(10);

    REQUIRE( stack.Peek() == 10 );
    REQUIRE( stack.Pop() == 10 );
}

TEST_CASE( "Testing stack underflow", "[stack]") {
    Stack<int> stack;
    int result;

    stack.Push(12);

    REQUIRE( stack.Pop() == 12 );
    REQUIRE_THROWS_WITH( stack.Pop(), "Pop empty stack");
}

TEST_CASE( "Testing stack Peek empty", "[stack]") {
    Stack<int> stack;

    REQUIRE_THROWS_WITH( stack.Peek(), "Peek empty stack");
}
