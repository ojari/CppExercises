#include "common.hpp"
#include "../assignment1.hpp"

TEST_CASE("Assignment1", "[Assignment1]") {
    URI uri("http", "www.google.com", "/path/to/file.html");

    REQUIRE(uri.str() == "http://www.google.com/path/to/file.html");
}
