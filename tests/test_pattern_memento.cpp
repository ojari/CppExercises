#include "common.hpp"
#include "../PatternMemento.hpp"

TEST_CASE("TokenMachine", "[Memento]") {
    TokenMachine tokenMachine;
    auto m1 = tokenMachine.add_token(10);
    auto m2 = tokenMachine.add_token(20);
    
    REQUIRE(tokenMachine.get_last_token() == 20);

    tokenMachine.revert(m1);
    REQUIRE(tokenMachine.get_last_token() == 10);
}

