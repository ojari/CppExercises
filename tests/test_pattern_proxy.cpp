#include "common.hpp"
#include "../PatternProxy.hpp"

TEST_CASE("PatternProxy", "[PatternProxy]") {
    Person person{15};

    REQUIRE(person.drink() == "drinking");
    REQUIRE(person.drive() == "driving");
    REQUIRE(person.drink_and_drive() == "driving while drunk");

    ResponsiblePerson youngperson{person};

    REQUIRE(youngperson.drink() == "too young");
    REQUIRE(youngperson.drive() == "too young");
    REQUIRE(youngperson.drink_and_drive() == "dead");

    youngperson.set_age(20);

    REQUIRE(youngperson.drink() == "drinking");
    REQUIRE(youngperson.drive() == "driving");
    REQUIRE(youngperson.drink_and_drive() == "dead");
}
