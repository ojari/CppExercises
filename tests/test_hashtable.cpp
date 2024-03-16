#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../HashTable.hpp"


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
