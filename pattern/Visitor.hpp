#pragma once
#include <string>
#include <sstream>
using namespace std;

struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor {
    virtual void visit(Value& expr) = 0;
    virtual void visit(AdditionExpression& expr) = 0;
    virtual void visit(MultiplicationExpression& expr) = 0;
};

struct Expression {
    virtual void accept(ExpressionVisitor& ev) = 0;
};

struct Value : Expression {
    int value;

    Value(int value) : value(value)
    {}

    void accept(ExpressionVisitor& ev) override {
        ev.visit(*this);
    }
};

struct AdditionExpression : Expression {
    Expression &lhs, &rhs;

    AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs)
    {}

    void accept(ExpressionVisitor& ev) override {
        ev.visit(*this); // this can't be in base class because this pointer is different there.
    }
};

struct MultiplicationExpression : Expression {
    Expression &lhs, &rhs;

    MultiplicationExpression(Expression &lhs, Expression &rhs)
        : lhs(lhs), rhs(rhs) 
    {}

    void accept(ExpressionVisitor& ev) override {
        ev.visit(*this);
    }
};

struct ExpressionPrinter : ExpressionVisitor {
    void visit(Value &expr) override {
        oss << expr.value;
    }
    void visit(AdditionExpression &expr) override {
        oss << "(";
        expr.lhs.accept(*this);
        oss << "+";
        expr.rhs.accept(*this);
        oss << ")";
    }
    void visit(MultiplicationExpression &expr) override {
        expr.lhs.accept(*this);
        oss << "*";
        expr.rhs.accept(*this);
    }

    string str() const {
        return oss.str();
     }
private:
    ostringstream oss;
};