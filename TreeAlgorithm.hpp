#pragma once

#include "LinkList.hpp"
#include "BinarySearchTree.hpp"
#include "Queue.hpp"

//template<typename T>
//extern LinkList<T> breadthFirstSearch(BinarySearchTree<T> tree);

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
