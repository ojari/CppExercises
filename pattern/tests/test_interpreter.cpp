#include "common.hpp"
#include "../Interpreter.hpp"

TEST_CASE("PatternInterpreter 1", "[PatternInterpreter]") {
    ExpressionProcessor ep;

    REQUIRE(ep.calculate("1+2+3") == 6);
}

TEST_CASE("PatternInterpreter 2", "[PatternInterpreter]") {
    ExpressionProcessor ep;

    ep.variables['x'] = 3;

    REQUIRE(ep.calculate("1+x+3") == 7);
    REQUIRE(ep.calculate("1+xy+3") == 0);
    REQUIRE(ep.calculate("10-2-x") == 5);
}

