#pragma once

#include "LinkList.hpp"
#include <stdexcept>

template <typename T> class Queue {
public:
    Queue() :
        first { nullptr},
        last { nullptr}
    {
    }

    T peek() {
        if (first == nullptr) throw std::runtime_error("Peek from empty queue");

        return first->value;
    }

    void enqueue(T value) {
        auto newnode = new LinkNode<T>(value);

        if (last == nullptr) {
            last = newnode;
            first = newnode;
        }
        else {
            last->next = newnode;
            last = newnode;
        }
    }

    T deQueue() {
        if (first == nullptr) throw std::runtime_error("DeQueue from empty queue");

        T result = first->value;
        LinkNode<T> *tmp = first;
        first = first->next;
        delete tmp;

        if (first == nullptr) last = nullptr;

        return result;
    }

private:
    LinkNode<T> *first;
    LinkNode<T> *last;
};
