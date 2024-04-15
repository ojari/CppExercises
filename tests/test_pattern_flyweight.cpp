#include "common.hpp"
#include "../pattern/Flyweight.hpp"

TEST_CASE("PatternFlyweight", "[PatternFlyweight]") {
    Sentence sentence("hello world");

    sentence[1].capitalize = true;

    REQUIRE(sentence.str() == "hello WORLD");
}