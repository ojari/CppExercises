#pragma once

#include "LinkList.hpp"


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