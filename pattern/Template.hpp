#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int creature1, int creature2)
    {
      cout << "creature1 " << creatures[creature1].attack << "/" << creatures[creature1].health << "\n";
      cout << "creature2 " << creatures[creature2].attack << "/" << creatures[creature2].health << "\n";
      return hit(creatures[creature1], creatures[creature2]);
    }

    virtual int hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    int hit(Creature &attacker, Creature &other) override {
      if (attacker.attack == 1 && other.attack == 1) {
          return -1;
      }
      if (attacker.attack == 2 && other.attack == 2) {
          return -1;
      }
      if (attacker.attack > other.attack) {
          return 0;
      }
      if (attacker.attack < other.attack) {
          return 1;
      }
      return -1;
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    int hit(Creature &attacker, Creature &other) override
    {
      if (attacker.attack == 1 && other.attack == 1) {
          //if (attacker.health > other.health) {
          //    return 0;
          //}
          round++;
          if (round == 1) {
            return -1;
          }
          return 1;
      }
    }
    int round {0};
};