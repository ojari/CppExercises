#include <catch2/catch_all.hpp>
#include <algorithm>
#include "../Stack.hpp"


TEST_CASE( "Testing stack Push, Pop", "[stack]") {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);

    REQUIRE( stack.pop() == 20 );
    REQUIRE( stack.pop() == 10 );
}

TEST_CASE( "Testing stack Peek", "[stack]") {
    Stack<int> stack;

    stack.push(10);

    REQUIRE( stack.peek() == 10 );
    REQUIRE( stack.pop() == 10 );
}

TEST_CASE( "Testing stack underflow", "[stack]") {
    Stack<int> stack;

    stack.push(12);

    REQUIRE( stack.pop() == 12 );
    REQUIRE_THROWS_WITH( stack.pop(), "Pop empty stack");
}

TEST_CASE( "Testing stack Peek empty", "[stack]") {
    Stack<int> stack;

    REQUIRE_THROWS_WITH( stack.peek(), "Peek empty stack");
}




//--------------------------------------------------------------

TEST_CASE( "Testing stackarr Push, Pop", "[stackarr]") {
    StackArr<int> stack;

    stack.push(10);
    stack.push(20);

    REQUIRE( stack.pop() == 20 );
    REQUIRE( stack.pop() == 10 );
}

TEST_CASE( "Testing stackarr Peek", "[stackarr]") {
    StackArr<int> stack;

    stack.push(10);

    REQUIRE( stack.peek() == 10 );
    REQUIRE( stack.pop() == 10 );
}

TEST_CASE( "Testing stackarr underflow", "[stackarr]") {
    StackArr<int> stack;

    stack.push(12);

    REQUIRE( stack.pop() == 12 );
    REQUIRE_THROWS_WITH( stack.pop(), "Pop empty stack");
}

TEST_CASE( "Testing stackarr Peek empty", "[stackarr]") {
    StackArr<int> stack;

    REQUIRE_THROWS_WITH( stack.peek(), "Peek empty stack");
}
