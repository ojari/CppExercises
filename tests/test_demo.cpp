#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../HashTable.hpp"
#include "../LinkList.hpp"


TEST_CASE( "Add items to hash", "[hashtable]" ) {
    HashTable<int> htable(5);

    htable.set("one", 11);
    htable.set("two", 22);

    REQUIRE( htable.get("one") == 11);
    REQUIRE( htable.get("two") == 22);
}

TEST_CASE( "Testing keys", "[hashtable]" ) {
    HashTable<int> htable(5);

    htable.set("one", 11);
    htable.set("two", 22);

    auto result = htable.keys();

    REQUIRE( result.size() == 2);
    REQUIRE( std::find(result.begin(), result.end(), "one") != result.end());
    REQUIRE( std::find(result.begin(), result.end(), "two") != result.end());
}

TEST_CASE( "Testing linked list", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(123);
    llist.append(402);

    result = llist.pop();
    REQUIRE( result == 123 );

    result = llist.pop();
    REQUIRE( result == 402 );
}

TEST_CASE( "Testing linked Push and Pop 1", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.prepend(11);
    llist.prepend(22);

    result = llist.pop();
    REQUIRE( result == 22 );

    result = llist.pop();
    REQUIRE( result == 11 );
}

TEST_CASE( "Testing linked Insert", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.insert(1, 33);
    llist.insert(2, 44);

    result = llist.pop();
    REQUIRE( result == 11 );

    result = llist.pop();
    REQUIRE( result == 33 );

    result = llist.pop();
    REQUIRE( result == 44 );

    result = llist.pop();
    REQUIRE( result == 22 );
}

TEST_CASE( "Testing linked Remove", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.append(33);

    llist.remove(1);

    result = llist.pop();
    REQUIRE( result == 11 );

    result = llist.pop();
    REQUIRE( result == 22 );
}

TEST_CASE( "Testing linked Reverse", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.append(33);

    llist.reverse();

    result = llist.pop();
    REQUIRE( result == 33 );

    result = llist.pop();
    REQUIRE( result == 22 );

    result = llist.pop();
    REQUIRE( result == 11 );
}

/*int main(int argc, char* argv[])
{
    Catch::RunTests()
    Catch::Session session; // Initialize Catch2
    // Customize configuration here (e.g., session.configData())
    int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) // Handle command line options
        return returnCode;
    return session.run(); // Run tests
}*/