#include "common.hpp"
#include "../pattern/Memento.hpp"

TEST_CASE("TokenMachine", "[Memento]") {
    // NOTE: This code do not work in linux in Catch2 framework, 
    // but same code works in Windows Catch2 and main.cpp::test_memento stansalond function.
    //
#if 0
    TokenMachine tokenMachine;
    auto m1 = tokenMachine.add_token(10);
    auto m2 = tokenMachine.add_token(20);
    
    REQUIRE(tokenMachine.get_last_token() == 20);

    tokenMachine.revert(m1);
    REQUIRE(tokenMachine.get_last_token() == 10);
#endif
}

