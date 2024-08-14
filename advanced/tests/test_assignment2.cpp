#include "common.hpp"
#include "../assignment2.hpp"

TEST_CASE("Assignment2", "[Assignment2]") {
    std::string source { "To be, or not to be, that is the question:" };
    const std::string target { "To be! or not to be! that is the question!" };

    std::string output = exclaim(source);

    REQUIRE(source == target);
    REQUIRE(output == target);
}
