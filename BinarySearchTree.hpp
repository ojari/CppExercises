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

    void SetLR(BinaryNode<T> *ref, BinaryNode<T> *value) {
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

        if (current->left == nullptr && current->right == nullptr) {  // is leaf node
            parent->SetLR(current, nullptr);
            delete current;
        }
        else if (current->left == nullptr) {
            parent->SetLR(current, current->right);
            delete current;
        }
        else if (current->right == nullptr) {
            parent->SetLR(current, current->left);
            delete current;
        }
        else {
            if (current->right->left == nullptr) {
                current->right->left = current->left;
                parent->SetLR(current, current->right);
                delete current;
            }
            else if (current->left->right == nullptr) {
                current->left->right = current->right;
                parent->SetLR(current, current->left);
                delete current;
            }
            // not yet implemented harder cases
        }
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