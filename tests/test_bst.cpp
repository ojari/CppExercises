#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../BinarySearchTree.hpp"

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
