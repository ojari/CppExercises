#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../DoubleLinkList.hpp"


TEST_CASE( "Testing double linked list", "[dlinklist]") {
    DoubleLinkList<int> llist;
    int result;

    llist.Append(123);
    llist.Append(402);

    result = llist.Pop();
    REQUIRE( result == 123 );

    result = llist.Pop();
    REQUIRE( result == 402 );
}

TEST_CASE( "Testing double linked Push and Pop 1", "[linklist]") {
    DoubleLinkList<int> llist;
    int result;

    llist.Prepend(11);
    llist.Prepend(22);

    result = llist.Pop();
    REQUIRE( result == 22 );

    result = llist.Pop();
    REQUIRE( result == 11 );
}

TEST_CASE( "Testing linked Insert", "[dlinklist]") {
    DoubleLinkList<int> llist;
    int result;

    llist.Append(11);
    llist.Append(22);
    llist.Insert(1, 33);
    llist.Insert(2, 44);

    result = llist.Pop();
    REQUIRE( result == 11 );

    result = llist.Pop();
    REQUIRE( result == 33 );

    result = llist.Pop();
    REQUIRE( result == 44 );

    result = llist.Pop();
    REQUIRE( result == 22 );
}

TEST_CASE( "Testing linked Remove", "[dlinklist]") {
    DoubleLinkList<int> llist;
    int result;

    llist.Append(11);
    llist.Append(22);
    llist.Append(33);

    llist.Remove(1);

    result = llist.Pop();
    REQUIRE( result == 11 );

    result = llist.Pop();
    REQUIRE( result == 22 );
}


