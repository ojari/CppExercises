#include "common.hpp"
#include "../PatternObserver.hpp"


TEST_CASE("Observer 1", "[Pattern,Observer]") {
    Game game;
    Rat rat1("Rat1", game);

    REQUIRE(rat1.attack == 1);
}

TEST_CASE("Observer 2", "[Pattern,Observer]") {
    Game game;
    Rat rat1("Rat1", game);
    Rat rat2("Rat2", game);

    REQUIRE(rat1.attack == 2);
    REQUIRE(rat2.attack == 2);
}

TEST_CASE("Observer 3", "[Pattern,Observer]") {
    Game game;
    auto rat1 = new Rat { "Rat1", game};
    auto rat2 = new Rat { "Rat2", game};
    auto rat3 = new Rat { "Rat3", game};

    delete rat2; // only rat1 and rat3 should be left

    REQUIRE(rat1->attack == 2);
    REQUIRE(rat3->attack == 2);

    delete rat1;
    delete rat3;
}
