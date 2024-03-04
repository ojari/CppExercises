#pragma once

#include <iostream>
template<typename T> class LinkList;
template<typename T> class Queue;

/** Linked list contains these items.
 */
template<typename T> class LinkNode {
    friend LinkList<T>;
    friend Queue<T>;
public:
    LinkNode(T val) :
        value { val },
        next { nullptr }
    {}
private:
    T value;
    LinkNode<T> *next;
};

/** Linked list implementation.
 */
template<typename T> class LinkList {
public:
    LinkList() :
        head { nullptr},
        tail { nullptr},
        count { 0 }
    {
    }

    void append(T value) {
        auto newnode = new LinkNode<T>(value);
        count++;
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void prepend(T value) {
        auto newnode = new LinkNode<T>(value);
        count++;
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            newnode->next = head;
            head = newnode;
        }
    }

    void insert(int position, T value) {
        if (position == 0) {
            prepend(value);
            return;
        }
        if (position >= count) {
            append(value);
            return;
        }

        LinkNode<T> *previous = moveToIndex(position-1);

        count++;
        auto newnode = new LinkNode<T>(value);
        newnode->next = previous->next;
        previous->next = newnode;
    }

    void remove(int position) {
        if (position == 0) {
            LinkNode<T> *next = head->next;
            delete head;
            head = next;
        }

        LinkNode<T> *previous = moveToIndex(position);
        LinkNode<T> *to_delete = previous->next;
        previous->next = previous->next->next;

        delete to_delete;
        count--;
    }

    T pop() {
        if (head != nullptr) {
            count--;
            T result = head->value;
            LinkNode<T> *first = head;
            head = head->next;
            delete first;
            return result;
        }
        throw std::runtime_error("Pop empty stack");
    }

    void reverse() {
        if (count < 2) {
            return;
        }
        if (count == 2) {
            head->next = nullptr;
            tail->next = head;

            head = tail;
            tail = head->next;
        }
        else {
            LinkNode<T> *previous = nullptr;
            LinkNode<T> *current = head;

            while (current != nullptr) {
                LinkNode<T> *next = current->next;

                current->next = previous;

                previous = current;
                current = next;
            }

            tail = head;
            head = previous;
        }
    }

    void print() {
        if (head == nullptr && tail == nullptr) {
            std::cout << "empty" << std::endl;
            return;
        }
        LinkNode<T> *current = head;
        while (current != nullptr) {
            std::cout << " node " << current->value << std::endl;
            current = current->next;
        }
    }

    T peekHead() {
        if (head != nullptr)
            return head->value;
        throw std::runtime_error("Peek empty stack");
    }

private:
    LinkNode<T>* moveToIndex(int index) {
        int counter = 0;
        LinkNode<T> *current = head;

        while (counter != index) {
            current = current->next;
            counter++;
        }
        return current;
    }

    LinkNode<T> *head;
    LinkNode<T> *tail;
    int count;
};

