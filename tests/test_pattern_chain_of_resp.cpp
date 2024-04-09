#include "common.hpp"
#include "../PatternChainOfResp.hpp"

TEST_CASE("One Goblin", "[PatternChainOfResp]") {
    Game game;
    Goblin goblin(game);
    game.creatures.push_back(&goblin);

    REQUIRE(goblin.calculate_attach() == 1);
    REQUIRE(goblin.calculate_defence() == 1);
}

TEST_CASE("Two Goblins", "[PatternChainOfResp]") {
    Game game;
    Goblin goblin1(game);
    Goblin goblin2(game);
    game.creatures.push_back(&goblin1);
    game.creatures.push_back(&goblin2);

    REQUIRE(goblin1.calculate_attach() == 1);
    REQUIRE(goblin1.calculate_defence() == 2);
}

TEST_CASE("Three gobling + king", "[PatternChainOfResp]") {
    Game game;
    Goblin goblin1(game);
    Goblin goblin2(game);
    Goblin goblin3(game);
    GoblinKing king1(game);
    game.creatures.push_back(&goblin1);
    game.creatures.push_back(&goblin2);
    game.creatures.push_back(&goblin3);
    game.creatures.push_back(&king1);

    REQUIRE(goblin1.calculate_attach() == 2);
    REQUIRE(goblin1.calculate_defence() == 4);
}

