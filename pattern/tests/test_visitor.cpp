#include "common.hpp"
#include "../Visitor.hpp"

TEST_CASE("Visitor", "[Pattern,Visitor]") {
    Value v{2};
    AdditionExpression simple{v, v};
    MultiplicationExpression expr{simple, simple};

    ExpressionPrinter ep;
    ep.visit(expr);

    REQUIRE(ep.str() == "(2+2)*(2+2)");
}

TEST_CASE("Visitor 2", "[Pattern,Visitor]") {
    Value v1{3};
    Value v2{12};
    AdditionExpression expr{v1, v2};

    ExpressionPrinter ep;
    ep.visit(expr);

    REQUIRE(ep.str() == "(3+12)");
}
