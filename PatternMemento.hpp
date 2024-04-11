#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token {
  int value;

  Token(int value) : value(value) {}
};

struct Memento {
  Memento(int value) : value(value) {}

private:
  friend struct TokenMachine;
  int value;
};

struct TokenMachine {
  vector<shared_ptr<Token>> tokens;
  
  TokenMachine() {
  }
  virtual ~TokenMachine() {
  }

  Memento add_token(int value) {
    return add_token(make_shared<Token>(value));
  }

  int get_last_token() {
    if (tokens.empty()) 
        return 0;
    return tokens.back()->value;
  }

  // reverts the system to a state represented by the token
  void revert(const Memento& m) {
    tokens.push_back(make_shared<Token>(m.value));
  }

private:
  // adds the token to the set of tokens and returns the
  // snapshot of the entire system
  Memento add_token(const shared_ptr<Token>& token) {
    tokens.push_back(token);
    return Memento(token->value);
  }
};