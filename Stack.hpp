#pragma once

#include "LinkList.hpp"
#include <vector>

template <typename T> class Stack {
public:
    Stack() :
        list {}
    {
    }

    T Peek() {
        return list.PeekHead();
    }

    void Push(T value) {
        list.Prepend(value);
    }

    T Pop() {
        return list.Pop();
    }

private:
    LinkList<T> list;
};


template <typename T> class StackArr {
public:
    StackArr()
    {
    }

    T Peek() {
        if (arr.size() == 0) throw std::runtime_error("Peek empty stack");
        return arr.back();
    }

    void Push(T value) {
        arr.push_back(value);
    }

    T Pop() {
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