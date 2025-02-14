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

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> result;
    auto left_iter = left.begin();
    auto right_iter = right.begin();

    while (!(left_iter == left.end() && right_iter == right.end())) {
        if (left_iter == left.end()) {
            result.push_back(*right_iter);
            right_iter++;
        }
        else if (right_iter == right.end()) {
            result.push_back(*left_iter);
            left_iter++;
        }
        else {
            if (*left_iter <= *right_iter) {
                result.push_back(*left_iter);
                left_iter++;
            }
            else {
                result.push_back(*right_iter);
                right_iter++;
            }
        }
    }
    return result;
}

std::vector<int> mergeSort(std::vector<int> array)
{
    if (array.size() == 1) {
        return array;
    }

    int mid_point = array.size() / 2;

    std::vector<int> left(array.begin(), array.begin() + mid_point);
    std::vector<int> right(array.begin() + mid_point, array.end());

    return merge(
        mergeSort(left),
        mergeSort(right)
    );
}
