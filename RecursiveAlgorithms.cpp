#include "RecursiveAlgorithms.hpp"

int findFactorialRecursive(int n)
{
    if (n > 2) {
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

int fibonacciRecursive(int n)
{
    if (n < 2) {
        return n;
    }
    return fibonacciRecursive(n - 2) + fibonacciRecursive(n - 1);
}

int fibonacciIterative(int n)
{
    if (n < 2) {
        return n;
    }

    int previous[] = {0, 1};
    int current;

    for (int i=2; i<=n; i++) {
        current = previous[0] + previous[1];
        previous[0] = previous[1];
        previous[1] = current;
    }
    return current;
}

/** This implementation takes character from the end of the string. So we do not
 *  need to shift characters in the string. If we take string from the end it might
 *  be possible to use tail optimization.
*/
std::string reverseRecursive(std::string text)
{
    if (text.empty()) {
        return std::string();
    }
    char last_ch = text.back();
    text.pop_back();
    return last_ch + reverseRecursive(text);
}

std::string reverseIterative(std::string text)
{
    std::string result;

    for (auto ch : text) {
        result.insert(result.begin(), ch);
    }
    return result;
}