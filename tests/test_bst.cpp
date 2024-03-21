#include <catch2/catch_all.hpp>
#include <algorithm>
#include "../BinarySearchTree.hpp"
#include "../TreeAlgorithm.hpp"

/** Makes default binarytree
 * 
 *                 9
 *              4       20 
 *            1   6   15   170
*/
void FillTree(BinarySearchTree<int>& bst)
{
    bst.insert(9);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(170);
    bst.insert(15);
    bst.insert(1);
}

TEST_CASE( "Testing BTS Insert", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    auto root = bst.getRoot();

    REQUIRE(root->Value() == 9);
    REQUIRE(root->Left()->Value() == 4);
    REQUIRE(root->Left()->Left()->Value() == 1);
    REQUIRE(root->Left()->Right()->Value() == 6);
    REQUIRE(root->Right()->Value() == 20);
    REQUIRE(root->Right()->Left()->Value() == 15);
    REQUIRE(root->Right()->Right()->Value() == 170);
}

TEST_CASE( "Testing BTS Loopup empty", "[bst]") {
    BinarySearchTree<int> bst;

    REQUIRE( bst.lookup(10) == false);
}

TEST_CASE( "Testing BTS Loopup", "[bst]") {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);

    REQUIRE( bst.lookup(10) == true);
    REQUIRE( bst.lookup(20) == true);
    REQUIRE( bst.lookup(30) == false);
}

TEST_CASE( "Testing BTS Remove leaf", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    bst.remove(170);
    bst.remove(180);

    REQUIRE(bst.lookup(170) == false);
}

TEST_CASE( "Testing BTS Remove middle", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    bst.remove(20);

    REQUIRE(bst.lookup(20) == false);
    REQUIRE(bst.lookup(170) == true);
    REQUIRE(bst.lookup(15) == true);
}

TEST_CASE("Testing breadthFirstSearch", "[bst_algo]") {
    BinarySearchTree<int> bst;
    LinkList<int> result;

    FillTree(bst);

    result = breadthFirstSearch(bst);

    REQUIRE(result.pop() == 9);
    REQUIRE(result.pop() == 4);
    REQUIRE(result.pop() == 20);
    REQUIRE(result.pop() == 1);
    REQUIRE(result.pop() == 6);
    REQUIRE(result.pop() == 15);
    REQUIRE(result.pop() == 170);
}

TEST_CASE("Testing depthFirstSearchInOrder", "[bst_algo]") {
    BinarySearchTree<int> bst;
    LinkList<int> result;

    FillTree(bst);

    depthFirstSearchInOrder<int>(bst.getRoot(), result);

    REQUIRE(result.pop() == 1);
    REQUIRE(result.pop() == 4);
    REQUIRE(result.pop() == 6);
    REQUIRE(result.pop() == 9);
    REQUIRE(result.pop() == 15);
    REQUIRE(result.pop() == 20);
    REQUIRE(result.pop() == 170);
}


TEST_CASE("Testing depthFirstSearchPreOrder", "[bst_algo]") {
    BinarySearchTree<int> bst;
    LinkList<int> result;

    FillTree(bst);

    depthFirstSearchPreOrder<int>(bst.getRoot(), result);

    REQUIRE(result.pop() == 9);
    REQUIRE(result.pop() == 4);
    REQUIRE(result.pop() == 1);
    REQUIRE(result.pop() == 6);
    REQUIRE(result.pop() == 20);
    REQUIRE(result.pop() == 15);
    REQUIRE(result.pop() == 170);
}


TEST_CASE("Testing depthFirstSearchPostOrder", "[bst_algo]") {
    BinarySearchTree<int> bst;
    LinkList<int> result;

    FillTree(bst);

    depthFirstSearchPostOrder<int>(bst.getRoot(), result);

    REQUIRE(result.pop() == 1);
    REQUIRE(result.pop() == 6);
    REQUIRE(result.pop() == 4);
    REQUIRE(result.pop() == 15);
    REQUIRE(result.pop() == 170);
    REQUIRE(result.pop() == 20);
    REQUIRE(result.pop() == 9);
}


TEST_CASE("Testing isValidBST", "[bst_algo]") {
    BinaryNode<int> root {2,
        new BinaryNode<int> { 1 },
        new BinaryNode<int> { 3 }};

    bool result = isValidBST(&root);

    REQUIRE(result == true);

    root.Left()->set(4);
    result = isValidBST(&root);
    REQUIRE(result == false);
}
