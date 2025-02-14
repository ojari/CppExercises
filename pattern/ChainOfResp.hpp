#pragma once
#include <string>
#include <vector>
using namespace std;

struct Creature;
struct Game
{
  vector<Creature*> creatures;

  void add(Creature *creature) {
    creatures.push_back(creature);
  }
};

struct StatQuery {
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature {
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual int get_attack() = 0;
  virtual int get_defense() = 0;

  int calculate_attach() {
    int attach = base_attack;
    for (auto c : game.creatures) {
      if (c != this)
        attach += c->get_attack();
    }
    return attach;
  }

  int calculate_defence() {
    int defence = base_defense;
    for (auto c : game.creatures) {
      if (c != this)
        defence += c->get_defense();
    }
    return defence;
  }
};

class Goblin : public Creature {
public:
  Goblin(Game &game, int base_attack, int base_defense) : 
    Creature(game, base_attack, base_defense)
  {}

  Goblin(Game &game) :
    Creature(game, 1, 1) 
  {}

  int get_attack() override {
    return 0;
  }

  int get_defense() override {
    return 1;
  }
};

class GoblinKing : public Goblin {
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}


  int get_attack() override {
    return 1;
  }

  int get_defense() override {
    return 1;
  }
};
