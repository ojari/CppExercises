#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../Queue.hpp"


TEST_CASE( "Testing queue Push, Pop", "[queue]") {
    Queue<int> queue;

    queue.Enqueue(10);
    queue.Enqueue(20);

    REQUIRE( queue.DeQueue() == 10 );
    REQUIRE( queue.DeQueue() == 20 );
}

TEST_CASE( "Testing queue Peek", "[queue]") {
    Queue<int> queue;

    queue.Enqueue(10);

    REQUIRE( queue.Peek() == 10 );
    REQUIRE( queue.DeQueue() == 10 );
}

TEST_CASE( "Testing queue underflow", "[queue]") {
    Queue<int> queue;

    queue.Enqueue(12);

    REQUIRE( queue.DeQueue() == 12 );
    REQUIRE_THROWS_WITH( queue.DeQueue(), "DeQueue from empty queue");
}

TEST_CASE( "Testing queue Peek empty", "[queue]") {
    Queue<int> queue;

    REQUIRE_THROWS_WITH( queue.Peek(), "Peek from empty queue");
}