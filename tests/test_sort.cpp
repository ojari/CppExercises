#include "common.hpp"
#include "../Sorting.hpp"
#include <iostream>

#define DATA_SET 99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0
#define DATA_SET2 5

void validate_dataset1(std::vector<int>& data)
{
    REQUIRE( data.size() == 11);

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

void validate_dataset2(std::vector<int>& data)
{
    REQUIRE( data.size() == 1);

    REQUIRE( data[0] == 5);
}

TEST_CASE( "bubble sort", "[sorting]" ) {
    std::vector<int> data {DATA_SET};

    bubbleSort(data);

    validate_dataset1(data);
}

TEST_CASE( "bubble sort one item", "[sorting]" ) {
    std::vector<int> data {DATA_SET2};

    bubbleSort(data);
    validate_dataset2(data);
}

TEST_CASE( "selection sort", "[sorting]" ) {
    std::vector<int> data {DATA_SET};

    selectionSort(data);

    validate_dataset1(data);
}

TEST_CASE( "selection sort one item", "[sorting]" ) {
    std::vector<int> data {DATA_SET2};

    selectionSort(data);
    validate_dataset2(data);
}

TEST_CASE( "insertion sort", "[sorting]" ) {
    std::vector<int> data {DATA_SET};

    insertionSort(data);

    validate_dataset1(data);
}

TEST_CASE( "insertion sort one item", "[sorting]" ) {
    std::vector<int> data {DATA_SET2};

    insertionSort(data);
    validate_dataset2(data);
}

TEST_CASE( "merge sort", "[sorting]" ) {
    std::vector<int> data {DATA_SET};

    std::vector<int> result = mergeSort(data);

    validate_dataset1(result);
}

TEST_CASE( "merge sort one item", "[sorting]" ) {
    std::vector<int> data {DATA_SET2};
    std::vector<int> result = mergeSort(data);

    validate_dataset2(result);
}
