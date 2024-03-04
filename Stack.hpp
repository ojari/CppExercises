#pragma once

#include "LinkList.hpp"
#include <vector>

template <typename T> class Stack {
public:
    Stack() :
        list {}
    {
    }

    T peek() {
        return list.peekHead();
    }

    void push(T value) {
        list.prepend(value);
    }

    T pop() {
        return list.pop();
    }

private:
    LinkList<T> list;
};


template <typename T> class StackArr {
public:
    StackArr()
    {
    }

    T peek() {
        if (arr.size() == 0) throw std::runtime_error("Peek empty stack");
        return arr.back();
    }

    void push(T value) {
        arr.push_back(value);
    }

    T pop() {
        if (arr.empty()) {
            throw std::runtime_error("Pop empty stack");
        }
        T result = arr.back();
        arr.pop_back();
        return result;
    }

private:
    std::vector<T> arr;
};