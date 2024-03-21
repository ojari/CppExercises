#include <catch2/catch_all.hpp>
#include <algorithm>
#include "../Queue.hpp"


TEST_CASE( "Testing queue Push, Pop", "[queue]") {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);

    REQUIRE( queue.deQueue() == 10 );
    REQUIRE( queue.deQueue() == 20 );
}

TEST_CASE( "Testing queue Peek", "[queue]") {
    Queue<int> queue;

    queue.enqueue(10);

    REQUIRE( queue.peek() == 10 );
    REQUIRE( queue.deQueue() == 10 );
}

TEST_CASE( "Testing queue underflow", "[queue]") {
    Queue<int> queue;

    queue.enqueue(12);

    REQUIRE( queue.deQueue() == 12 );
    REQUIRE_THROWS_WITH( queue.deQueue(), "DeQueue from empty queue");
}

TEST_CASE( "Testing queue Peek empty", "[queue]") {
    Queue<int> queue;

    REQUIRE_THROWS_WITH( queue.peek(), "Peek from empty queue");
}