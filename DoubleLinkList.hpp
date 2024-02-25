#pragma once

#include <iostream>
template<typename T> class DoubleLinkList;

/** Double linked list contains these items.
 */
template<typename T> class DoubleLinkNode {
    friend DoubleLinkList<T>;
public:
    DoubleLinkNode(T val) :
        value { val },
        next { NULL },
        previous { NULL }
    {}
private:
    T value;
    DoubleLinkNode<T> *next;
    DoubleLinkNode<T> *previous;
};

/** Double linked list contains these items.
 */
template<typename T> class DoubleLinkList {
public:
    DoubleLinkList() :
        head { NULL},
        tail { NULL},
        count { 0 }
    {
    }

    void Append(T value) {
        auto newnode = new DoubleLinkNode<T>(value);
        count++;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            newnode->previous = tail;
            tail = newnode;
        }
    }

    void Prepend(T value) {
        auto newnode = new DoubleLinkNode<T>(value);
        count++;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            newnode->next = head;
            head->previous = newnode;
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

        DoubleLinkNode<T> *leader = MoveToIndex(position-1);
        DoubleLinkNode<T> *follower = leader->next;

        count++;
        auto newnode = new DoubleLinkNode<T>(value);
        newnode->next = follower;
        newnode->previous = leader;
        if (follower != NULL) {
            follower->previous = newnode;
        }
        leader->next = newnode;
    }

    void Remove(int position) {
        if (position == 0) {
            DoubleLinkNode<T> *next = head->next;
            delete head;
            next->previous = NULL;
            head = next;
        }

        DoubleLinkNode<T> *leader = MoveToIndex(position);
        DoubleLinkNode<T> *to_delete = leader->next;
        if (to_delete != NULL) {
            DoubleLinkNode<T> *follower = to_delete->next;

            leader->next = follower;
            if (follower != NULL) {
                follower->previous = leader;
            }

            delete to_delete;
            count--;
        }
    }

    T Pop() {
        if (head != NULL) {
            count--;
            T result = head->value;
            DoubleLinkNode<T> *first = head;
            if (head->next != NULL) { // is empty
                head = head->next;
                head->previous = NULL;
            }
            else {
                head = NULL;
                tail = NULL;
            }
            delete first;
            return result;
        }
        return 0;
    }

    void Print() {
        if (head == NULL && tail == NULL) {
            std::cout << "empty" << std::endl;
            return;
        }
        DoubleLinkNode<T> *current = head;
        while (current != NULL) {
            std::cout << " node " << current->value << std::endl;
            current = current->next;
        }
    }

private:
    DoubleLinkNode<T>* MoveToIndex(int index) {
        int counter = 0;
        DoubleLinkNode<T> *current = head;

        while (counter != index) {
            current = current->next;
            counter++;
        }
        return current;
    }

    DoubleLinkNode<T> *head;
    DoubleLinkNode<T> *tail;
    int count;
};

