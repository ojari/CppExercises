#include "Sorting.hpp"

void bubbleSort(std::vector<int>& data)
{
    int skipLast = data.size() - 1;

    while (skipLast > 0) {
        for (int i=0; i<skipLast; i++) {
            if (data[i] > data[i+1]) {
                std::swap(data[i], data[i+1]);
            }
        }
        skipLast--;
    }
}