#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "HashTable.hpp"
#include "LinkList.hpp"
#include "DoubleLinkList.hpp"
#include "BinarySearchTree.hpp"
#include "Queue.hpp"
#include "RecursiveAlgorithms.hpp"
#include "PatternMemento.hpp"

using namespace std;

void test1()
{
    vector<int> items{1, 2, 3, 4, 5};

    for (auto i : items) {
        for (auto j : items) {
            if (i != j) {
                cout << i << ", " << j << endl;
            }
        }
    }
}

bool find_common(const vector<char>& first, const vector<char>& second)
{
    for (char ch : first) {
        if (find(second.begin(), second.end(), ch) != second.end()) {
            return true;
        }
    }
    return false;
}
bool find_common2(const vector<char>& first, const vector<char>& second)
{
    set<char> first_set;
    for (auto ch1 : first) {
        first_set.insert(ch1);
    }
    for (char ch2 : second) {
        if (first_set.find(ch2) != first_set.end()) {
            return true;
        }
    }
    return false;
}

string reverse_string(const string& source)
{
    string target;
    auto iterator = source.end();

    while (iterator != source.begin()) {
        --iterator;
        target.push_back(*iterator);
    }
    return std::move(target);
}

vector<int> merge_sorted_arrays(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> results;
    auto iter1 = arr1.begin();
    auto iter2 = arr2.begin();

    while (!((iter1 == arr1.end()) && (iter2 == arr2.end()))) {
        if (iter1 == arr1.end()) {
            results.push_back(*(iter2++));
        }
        else if (iter2 == arr2.end()) {
            results.push_back(*(iter1++));
        }
        else {
            if (*iter1 >= *iter2) {
                results.push_back(*(iter2++));
            }
            else {
                results.push_back(*(iter1++));
            }
        }
    }
    return std::move(results);
}

int first_recurring_numb(vector<int> array)
{
    std::set<int> earlier;

    for (int number : array) {
        if (earlier.find(number) != earlier.end()) {
            return number;
        }
        earlier.insert(number);
    }
    return -1;
}

void test_find_common() {
    vector<char> one{'a', 'b', 'c', 'x'};
    vector<char> two{'z', 'y', 'i'};
    vector<char> twob{'z', 'y', 'x'};

    cout << "case1 " << find_common2(one, two) << endl;
    cout << "case2 " << find_common2(one, twob) << endl;
}

void test_reverse_string() {
    cout << reverse_string("Hello my name is Jari") << endl;
}

void test_merge_array() {
    vector<int> arr1{0, 3, 4, 31, 34};
    vector<int> arr2{4, 6, 35};

    cout << "merged array is: ";
    for (auto value : merge_sorted_arrays(arr1, arr2)) {
        cout << value << " ";
    }
    cout << endl;
}

void test_first_recurring() {
    vector<int> arr1{2, 5, 1, 2, 3, 5, 1, 2, 4};
    vector<int> arr2{2, 1, 1, 2, 3, 5, 1, 2, 4};
    vector<int> arr3{2, 3, 4, 5};

    cout << "first recurring number is: " << first_recurring_numb(arr1) << endl;
    cout << "first recurring number is: " << first_recurring_numb(arr2) << endl;
    cout << "first recurring number is: " << first_recurring_numb(arr3) << endl;
}

void test_linklist() {
    LinkList<int> llist;
    int result;

    llist.append(11);
    llist.append(22);
    llist.append(33);

    llist.reverse();

    result = llist.pop();
    result = llist.pop();
    result = llist.pop();
}

void test_fibonacci() {
    fibonacciCounter = 0;
    cout << "Fibonacci 10: " << fibonacciRecursiveDyn(10) << " " << fibonacciCounter << endl;

    fibonacciCounter = 0;
    cout << "Fibonacci 20: " << fibonacciRecursiveDyn(20) << " " << fibonacciCounter << endl;
}

void test_memento() {
    TokenMachine tokenMachine;
    auto m1 = tokenMachine.add_token(10);
    auto m2 = tokenMachine.add_token(20);
    
    cout << "Last token: " << tokenMachine.get_last_token() << endl;

    tokenMachine.revert(m1);
    cout << "Last token: " << tokenMachine.get_last_token() << endl;
}

int main(int argc, char* argv[])
{
    int choice {8};

    if (argc > 1) {
        choice = atoi(argv[1]);
    }

    if (choice >= 1 && choice <= 8) {
        void (*testFunctions[])() = {
            test1, //  1
            test_find_common, //  2
            test_reverse_string, //  3
            test_merge_array, //  4
            test_first_recurring, //  5
            test_linklist, //  6
            test_fibonacci, //  7
            test_memento //  8
        };
        testFunctions[choice - 1]();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
