#include "common.hpp"
#include "../PatternState.hpp"

TEST_CASE("State", "[Pattern,State]") {
    SECTION("CombinationLock - Correct Combination") {
        CombinationLock cl({1, 2, 3});
        REQUIRE(cl.status == "LOCKED");

        cl.enter_digit(1);
        REQUIRE(cl.status == "1");

        cl.enter_digit(2);
        REQUIRE(cl.status == "12");

        cl.enter_digit(3);
        REQUIRE(cl.status == "OPEN");
    }

    SECTION("CombinationLock - Incorrect Combination") {
        CombinationLock cl({4, 5, 6});
        REQUIRE(cl.status == "LOCKED");

        cl.enter_digit(1);
        REQUIRE(cl.status == "1");

        cl.enter_digit(2);
        REQUIRE(cl.status == "12");

        cl.enter_digit(3);
        REQUIRE(cl.status == "FAILED");
    }
}
