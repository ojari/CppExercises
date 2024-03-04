#include "RecursiveAlgorithms.hpp"

int findFactorialRecursive(int n)
{
    if (n >= 2) {
        return n * findFactorialRecursive(n-1);
    }
    return n;
}


int findFactorialIterative(int n)
{
    int sum = 1;

    for (int i=2; i<=n; i++) {
        sum = sum * i;
    }
    return sum;
}