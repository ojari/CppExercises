#include "common.hpp"
#include "../LinkList.hpp"

TEST_CASE("Testing append and pop", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(123);
    llist.append(402);

    result = llist.pop();
    REQUIRE(result == 123);

    result = llist.pop();
    REQUIRE(result == 402);
}

TEST_CASE("Testing prepend and pop", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.prepend(11);
    llist.prepend(22);

    result = llist.pop();
    REQUIRE(result == 22);

    result = llist.pop();
    REQUIRE(result == 11);
}

TEST_CASE("Testing insert and pop", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.insert(1, 33);
    llist.insert(2, 44);

    result = llist.pop();
    REQUIRE(result == 11);

    result = llist.pop();
    REQUIRE(result == 33);

    result = llist.pop();
    REQUIRE(result == 44);

    result = llist.pop();
    REQUIRE(result == 22);
}

TEST_CASE("Testing remove and pop", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.append(33);

    llist.remove(1);

    result = llist.pop();
    REQUIRE(result == 11);

    result = llist.pop();
    REQUIRE(result == 33);
}

TEST_CASE("Testing reverse", "[linklist]") {
    LinkList<int> llist;
    int result;

    llist.append(1);
    llist.append(2);
    llist.append(3);
    llist.append(4);

    llist.reverse();

    result = llist.pop();
    REQUIRE(result == 4);

    result = llist.pop();
    REQUIRE(result == 3);

    result = llist.pop();
    REQUIRE(result == 2);

    result = llist.pop();
    REQUIRE(result == 1);
}