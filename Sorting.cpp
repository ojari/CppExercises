#include "Sorting.hpp"
#include <iostream>
#include <algorithm>

void bubbleSort(std::vector<int>& data)
{
    size_t skipLast = data.size() - 1;

    while (skipLast > 0) {
        for (int i=0; i<skipLast; i++) {
            if (data[i] > data[i+1]) {
                std::swap(data[i], data[i+1]);
            }
        }
        skipLast--;
    }
}

void selectionSort(std::vector<int>& data)
{
    for (int i=0; i<data.size() - 1; i++) {
        int min_index = i;
        for (int j=i+1; j<data.size(); j++) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            std::swap(data[i], data[min_index]);
        }
    }
}

void printVector(std::vector<int>& data)
{
    for (auto item : data) {
        std::cout << " " << item;
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& data)
{
    for (int i=1; i<data.size(); i++) {
        for (int j=i-1; j>=0; j--) {
            if (data[j] > data[j+1]) {
                std::swap(data[j], data[j+1]);
            }
        }
    }
}