#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct IRat {
    virtual string& get_name() = 0;
    virtual void add_rat(IRat* rat) = 0;
    virtual void del_rat(IRat* rat) = 0;
};

struct Game
{
    vector<IRat*> rats;
    
    void notify_add(IRat *rat) {
        for (auto r : rats) {
            r->add_rat(rat);  // old rats should know about new rat

            rat->add_rat(r); // new rat should know about all other rats
        }
        rats.push_back(rat);
    }
    
    void notify_del(IRat *rat) {
        for (auto r : rats) {
            r->del_rat(rat);
        }
        
        rats.erase(
            remove(rats.begin(), rats.end(), rat),
            rats.end());
    }
};

struct Rat : IRat
{
    Game& game;
    string name;
    int attack{1};

    Rat(string name, Game &game) : 
        name(name),
        game(game)
    {
      game.notify_add(this);
    }

    ~Rat() 
    { 
      game.notify_del(this);
    }

    string& get_name() override {
        return name;
    }
    
    void add_rat(IRat* rat) {
        if (rat != this) { attack++; }
    }
    
    void del_rat(IRat* rat) {
        if (rat != this) { attack--; }
    }
};