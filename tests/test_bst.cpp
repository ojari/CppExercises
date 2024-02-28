#include "catch_amalgamated.hpp"
#include <algorithm>
#include "../BinarySearchTree.hpp"

TEST_CASE( "Testing BTS Insert", "[bst]") {
    BinarySearchTree<int> bst;

    bst.Insert(10);
    bst.Insert(4);
    bst.Insert(20);
}
