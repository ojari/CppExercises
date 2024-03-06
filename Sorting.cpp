#include "Sorting.hpp"

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