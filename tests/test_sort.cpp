#include "catch_amalgamated.hpp"
#include "../Sorting.hpp"
#include <iostream>

TEST_CASE( "bubble sort", "[sorting]" ) {
    std::vector<int> data {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    bubbleSort(data);

    /*std::cout << "sorted data is: ";
    for (auto item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    */
    REQUIRE( data[0] == 0);
    REQUIRE( data[1] == 1);
    REQUIRE( data[2] == 2);
    REQUIRE( data[3] == 4);
    REQUIRE( data[4] == 5);
    REQUIRE( data[5] == 6);
    REQUIRE( data[6] == 44);
    REQUIRE( data[7] == 63);
    REQUIRE( data[8] == 87);
    REQUIRE( data[9] == 99);
    REQUIRE( data[10] == 283);
}

TEST_CASE( "selection sort", "[sorting]" ) {
    std::vector<int> data {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    selectionSort(data);

    REQUIRE( data[0] == 0);
    REQUIRE( data[1] == 1);
    REQUIRE( data[2] == 2);
    REQUIRE( data[3] == 4);
    REQUIRE( data[4] == 5);
    REQUIRE( data[5] == 6);
    REQUIRE( data[6] == 44);
    REQUIRE( data[7] == 63);
    REQUIRE( data[8] == 87);
    REQUIRE( data[9] == 99);
    REQUIRE( data[10] == 283);
}

TEST_CASE( "insertion sort", "[sorting]" ) {
    std::vector<int> data {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    insertionSort(data);

    REQUIRE( data[0] == 0);
    REQUIRE( data[1] == 1);
    REQUIRE( data[2] == 2);
    REQUIRE( data[3] == 4);
    REQUIRE( data[4] == 5);
    REQUIRE( data[5] == 6);
    REQUIRE( data[6] == 44);
    REQUIRE( data[7] == 63);
    REQUIRE( data[8] == 87);
    REQUIRE( data[9] == 99);
    REQUIRE( data[10] == 283);
}

