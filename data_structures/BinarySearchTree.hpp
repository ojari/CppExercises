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

    BinaryNode(T val, BinaryNode<T> *l, BinaryNode<T> *r) :
        value { val },
        left { l },
        right { r }
    {}

    void setLR(BinaryNode<T> *ref, BinaryNode<T> *value) {
        if (left == ref) {
            left = value;
        }
        else if (right == ref) {
            right = value;
        }
    }
    T Value() {
        return value;
    }

    void set(T val) {
        value = val;
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

    BinaryNode<T> *getRoot() {
        return root;
    }

    void insert(T value) {
        auto newnode = new BinaryNode<T>(value);
        if (root == nullptr) {
            root = newnode;
            return;
        }

        auto position = find(value);
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

    bool lookup(T value) {
        if (root == nullptr) {
            return false;
        }

        auto position = find(value);

        return position->value == value;
    }

    void remove(T value) {
        if (root == nullptr) {
            return;
        }

        // search correct position in the tree
        BinaryNode<T> *current = root;
        BinaryNode<T> *parent = nullptr;
        while (current != nullptr) {
            if ((value < current->value) && (current->left != nullptr)) {
                parent = current;
                current = current->left;
            }
            else if ((value > current->value) && (current->right != nullptr)) {
                parent = current;
                current = current->right;
            }
            else {
                break;
            }
        }
        // item not found from list
        if (current == nullptr || (current->value != value)) {
            return;   
        }

        // no right child
        if (current->right == nullptr) {
            if (parent == nullptr)
                root = current->left;
            else
                parent->setLR(current, current->left);
            delete current;
        }
        else if (current->right->left == nullptr) {
            current->right->left = current->left;
            if (parent == nullptr)
                root = current->right;
            else
                parent->setLR(current, current->right);
            delete current;
        }
        else {
            BinaryNode<T> *leftmost = current->right->left;
            BinaryNode<T> *leftmostParent = leftmost->right;
            while (leftmost->left != nullptr) {
                leftmostParent = leftmost;
                leftmost = leftmost->left;
            }

            leftmostParent->left = leftmost->right;
            leftmost->left = current->left;
            leftmost->right = current->right;

            if (parent == nullptr) {
                root = leftmost;
            }
            else {
                parent->setLR(current, leftmost);
            }
        }
    }

private:
    /** Search closes node for a value.
     */
    BinaryNode<T> *find(T value) {
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