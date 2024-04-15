#include "common.hpp"
#include "../pattern/Mediator.hpp"

TEST_CASE("Mediator", "[Mediator]") {
    Mediator mediator;
    Participant p1{mediator}, p2{mediator};

    SECTION("Initial value") {
        REQUIRE(p1.value == 0);
        REQUIRE(p2.value == 0);
    }

    SECTION("Say") {
        p1.say(5);
        p2.say(7);

        REQUIRE(p1.value == 7);
        REQUIRE(p2.value == 5);
    }
}
