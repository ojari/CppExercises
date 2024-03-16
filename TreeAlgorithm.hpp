#pragma once

#include "LinkList.hpp"
#include "BinarySearchTree.hpp"
#include "Queue.hpp"

template<typename T>
LinkList<T> breadthFirstSearch(BinarySearchTree<T> tree)
{
    LinkList<T> result;
    Queue<BinaryNode<T>*> store;

    store.enqueue(tree.getRoot());

    while (!store.isEmpty()) {
        BinaryNode<T>* item = store.deQueue();
        result.append(item->Value());

        if (item->Left() != nullptr) {
            store.enqueue(item->Left());
        }
        if (item->Right() != nullptr) {
            store.enqueue(item->Right());
        }
    }
    return result;
}


template<typename T>
void depthFirstSearchInOrder(BinaryNode<T> *node, LinkList<T> &result)
{
    if (node->Left() != nullptr) {
        depthFirstSearchInOrder(node->Left(), result);
    }

    result.append(node->Value());

    if (node->Right() != nullptr) {
        depthFirstSearchInOrder(node->Right(), result);
    }
}


template<typename T>
void depthFirstSearchPreOrder(BinaryNode<T> *node, LinkList<T> &result)
{
    result.append(node->Value());

    if (node->Left() != nullptr) {
        depthFirstSearchPreOrder(node->Left(), result);
    }
    if (node->Right() != nullptr) {
        depthFirstSearchPreOrder(node->Right(), result);
    }
}


template<typename T>
void depthFirstSearchPostOrder(BinaryNode<T> *node, LinkList<T> &result)
{
    if (node->Left() != nullptr) {
        depthFirstSearchPostOrder(node->Left(), result);
    }
    if (node->Right() != nullptr) {
        depthFirstSearchPostOrder(node->Right(), result);
    }
    result.append(node->Value());
}

template<typename T>
bool isValidBST(BinaryNode<T> *node)
{
    if (node == nullptr) {
        return true;
    }
    if ((node->Left() == nullptr) && (node->Right() == nullptr)) {
        return true;
    }
    if ((node->Left() != nullptr)  && (node->Left()->Value() > node->Value())) {
        return false;
    }
    if ((node->Right() != nullptr)  && (node->Right()->Value() < node->Value())) {
        return false;
    }
    bool result1 = isValidBST(node->Left());
    bool result2 = isValidBST(node->Right());
    return result1 || result2;
}
