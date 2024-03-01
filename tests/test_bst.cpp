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
    bst.Insert(9);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(20);
    bst.Insert(170);
    bst.Insert(15);
    bst.Insert(1);
}

TEST_CASE( "Testing BTS Insert", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    auto root = bst.GetRoot();

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

    REQUIRE( bst.Lookup(10) == false);
}

TEST_CASE( "Testing BTS Loopup", "[bst]") {
    BinarySearchTree<int> bst;

    bst.Insert(10);
    bst.Insert(20);

    REQUIRE( bst.Lookup(10) == true);
    REQUIRE( bst.Lookup(20) == true);
    REQUIRE( bst.Lookup(30) == false);
}

TEST_CASE( "Testing BTS Remove leaf", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    bst.Remove(170);
    bst.Remove(180);

    REQUIRE(bst.Lookup(170) == false);
}

TEST_CASE( "Testing BTS Remove middle", "[bst]") {
    BinarySearchTree<int> bst;

    FillTree(bst);

    bst.Remove(20);

    REQUIRE(bst.Lookup(20) == false);
    REQUIRE(bst.Lookup(170) == true);
    REQUIRE(bst.Lookup(15) == true);
}
