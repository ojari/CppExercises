#include "common.hpp"
#include "../Decorator.hpp"

TEST_CASE("PatternDecorator", "[PatternDecorator]") {
    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};

    REQUIRE(rose.str() == "A rose");
    REQUIRE(red_rose.str() == "A rose that is red");
    REQUIRE(red_red_rose.str() == "A rose that is red");
    REQUIRE(blue_red_rose.str() == "A rose that is red and blue");
}