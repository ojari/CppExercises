#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

enum token_type {
  integer,
  plus,
  minus,
  variable
};

struct Token {
  token_type type;
  string text;

  Token(token_type type, const string& text) : 
    type(type), 
    text(text)
  {}
};

vector<Token> lex(const string& input)
{
  vector<Token> result;
  string intstr;

  for (int i = 0; i < input.size(); ++i) {
      char ch = input[i];

      if (isdigit(ch)) {
          auto start = i;
          while (i < input.size() && isdigit(input[i]))
              ++i;
          intstr = input.substr(start, i - start);
          result.push_back({ token_type::integer, intstr });
          --i;
      }
      else if (isalpha(ch)) {
          auto start = i;
          while (i < input.size() && isalpha(input[i]))
              ++i;
          intstr = input.substr(start, i - start);
          result.push_back({ token_type::variable, intstr });
          --i;
      }
      else if (ch == '+') {
          result.push_back({ token_type::plus, "+" });
      }
      else if (ch == '-') {
          result.push_back({ token_type::minus, "-" });
      }
  }
  return result;
}


struct Element {
    virtual int eval(map<char,int>& variables) = 0;
};

struct Integer : Element {
    int value;

    Integer(int value) : 
        value(value)
    {}

    int eval(map<char,int>& variables) override {
        return value;
    }
};

struct Variable : Element {
    char name;

    Variable(string& name) : 
        name(name[0])
    {}

    int eval(map<char,int>& variables) override {
        return variables[name];
    }
};

struct BinaryOperation : Element {
    enum Type {
        addition,
        subtraction
    } type;
    shared_ptr<Element> lhs, rhs;

    int eval(map<char,int>& variables) override {
        switch (type) {
            case addition:
                return lhs->eval(variables) + rhs->eval(variables);
            case subtraction:
                return lhs->eval(variables) - rhs->eval(variables);
        }
        return 0;
    }
};

shared_ptr<Element> parser(const vector<Token>& tokens)
{
    auto result = make_shared<BinaryOperation>();
    bool have_lhs = false;
    bool have_rhs = false;

    for (int i = 0; i < tokens.size(); ++i) {
        auto token = tokens[i];
        switch (token.type) {
            case token_type::integer: {
                    int value = stoi(token.text);
                    auto integer = make_shared<Integer>(value);
                    if (!have_lhs) {
                        result->lhs = integer;
                        have_lhs = true;
                    } else {
                        result->rhs = integer;
                        have_rhs = true;
                    }
                }
                break;
            case token_type::plus:
            case token_type::minus: {
                    if (have_rhs) {
                        auto new_result = make_shared<BinaryOperation>();
                        new_result->lhs = result;
                        result = new_result;
                        have_rhs = false;
                    }
                    result->type = (token.type == token_type::plus) ? BinaryOperation::addition : BinaryOperation::subtraction;
                }
                break;
            case token_type::variable: {
                    auto variable = make_shared<Variable>(token.text);
                    if (!have_lhs) {
                        result->lhs = variable;
                        have_lhs = true;
                    } else {
                        result->rhs = variable;
                        have_rhs = true;
                    }
                }
                break;
        }
    }
    return result;
}

struct ExpressionProcessor
{
  map<char,int> variables;

   bool check(vector<Token>& tokens) {
    bool result = false;
    for (auto& t : tokens) {
      if (t.type == token_type::variable) {
        if (t.text.size() > 1) {
          result = true;
        }
        if (variables.find(t.text[0]) == variables.end()) {
          result = true;
        }
      }
    }
    return result;
  }

  int calculate(const string& expression) {
    auto tokens = lex(expression);

    if (check(tokens)) {
      return 0;
    }

    auto element = parser(tokens);
    auto result = element->eval(variables);

    return result;
  }
};
