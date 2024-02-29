#pragma once

#include <iostream>
template<typename T> class BinarySearchTree;
template<typename T> class Queue;

/** Linked list contains these items.
 */
template<typename T> class BinaryNode {
    friend BinarySearchTree<T>;
public:
    BinaryNode(T val) :
        value { val },
        left { nullptr },
        right { nullptr }
    {}
    T Value() {
        return value;
    }
    BinaryNode<T> *Left() {
        return left;
    }
    BinaryNode<T> *Right() {
        return right;
    }

private:
    T value;
    BinaryNode<T> *left;
    BinaryNode<T> *right;
};


/** Binary search tree.
 */
template<typename T> class BinarySearchTree {
public:
    BinarySearchTree() :
        root { nullptr},
        count { 0 }
    {
    }

    BinaryNode<T> *GetRoot() {
        return root;
    }

    void Insert(T value) {
        auto newnode = new BinaryNode<T>(value);
        if (root == nullptr) {
            root = newnode;
            return;
        }

        auto position = Find(value);
        if (value < position->value) {
            position->left = newnode; 
        }
        else if (value == position->value) {
            delete newnode;
            throw std::runtime_error("Duplicate value in BST");
        }
        else {
            position->right = newnode;
        }
    }

    bool Lookup(T value) {
        if (root == nullptr) {
            return false;
        }

        auto position = Find(value);

        return position->value == value;
    }

    void Remove(T value) {
        auto position = Find(value);

    }

private:
    /** Search closes node for a value.
     */
    BinaryNode<T> *Find(T value) {
        BinaryNode<T> *current = root;
        while (current != nullptr) {
            if ((value < current->value) && (current->left != nullptr)) {
                current = current->left;
            }
            else if ((value > current->value) && (current->right != nullptr)) {
                current = current->right;
            }
            else {
                return current;
            }
        }
        return nullptr; // this should never happend
    }

    BinaryNode<T> *root;
    int count;
};