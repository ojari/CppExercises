#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

struct Token {
  int value;

  Token(int value) : value(value) {
    //cout << "creating token with value " << value << endl;
  }

  //~Token() {
   // cout << "deleting token with value " << value << endl;
  //}
};

struct Memento {
  Memento(int value) : value(value) {}

private:
  friend struct TokenMachine;
  int value;
};

struct TokenMachine {
  TokenMachine() {
  }
  ~TokenMachine() {
    // cout << "deleting tokens: " << tokens.size() << " tokens" << endl;
    tokens.clear();
  }

  Memento add_token(int value) {
    auto token = make_shared<Token>(value);
    tokens.emplace_back(make_shared<Token>(value));
    current = tokens.size() - 1;
    return Memento(value);
  }

  int get_last_token() {
    cout << "current: " << current << " size:" << tokens.size() << endl;
    if (current >= tokens.size())
      return 0;
    return tokens[current]->value;
  }

  // reverts the system to a state represented by the token
  void revert(const Memento& m) {
    /* int index = 0;
    for (auto t : tokens) {
      if (t->value == m.value) {
        current = index;
        break;
      }
      index++;
    }*/
    auto pos = find_if(tokens.begin(), tokens.end(), [&](const shared_ptr<Token>& t) {
      return t->value == m.value;
    });
    if (pos != tokens.end()) {
      current = distance(tokens.begin(), pos);
    } 
    // tokens.push_back(make_shared<Token>(m.value));
  }
private:
  vector<shared_ptr<Token>> tokens;
  //vector<Token> tokens;
  unsigned int current{0};
};
