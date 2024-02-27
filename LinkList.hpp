#pragma once

#include <iostream>
template<typename T> class LinkList;

/** Linked list contains these items.
 */
template<typename T> class LinkNode {
    friend LinkList<T>;
public:
    LinkNode(T val) :
        value { val },
        next { nullptr }
    {}
private:
    T value;
    LinkNode<T> *next;
};

/** Linked list contains these items.
 */
template<typename T> class LinkList {
public:
    LinkList() :
        head { nullptr},
        tail { nullptr},
        count { 0 }
    {
    }

    void Append(T value) {
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

    void Prepend(T value) {
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

    void Insert(int position, T value) {
        if (position == 0) {
            Prepend(value);
            return;
        }
        if (position >= count) {
            Append(value);
            return;
        }

        LinkNode<T> *previous = MoveToIndex(position-1);

        count++;
        auto newnode = new LinkNode<T>(value);
        newnode->next = previous->next;
        previous->next = newnode;
    }

    void Remove(int position) {
        if (position == 0) {
            LinkNode<T> *next = head->next;
            delete head;
            head = next;
        }

        LinkNode<T> *previous = MoveToIndex(position);
        LinkNode<T> *to_delete = previous->next;
        previous->next = previous->next->next;

        delete to_delete;
        count--;
    }

    T Pop() {
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

    void Reverse() {
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

    void Print() {
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

    T PeekHead() {
        if (head != nullptr)
            return head->value;
        throw std::runtime_error("Peek empty stack");
    }

private:
    LinkNode<T>* MoveToIndex(int index) {
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

