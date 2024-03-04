#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "HashTable.hpp"
#include "LinkList.hpp"
#include "DoubleLinkList.hpp"
#include "BinarySearchTree.hpp"
#include "Queue.hpp"

using namespace std;

int test1()
{
    vector<int> items{1, 2, 3, 4, 5};

    for (auto i : items) {
        for (auto j : items) {
            if (i != j) {
                cout << i << ", " << j << endl;
            }
        }
    }
    return 0;
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

void test01()
{
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

void test02()
{
    Queue<int> queue;
    queue.enqueue(10);
    queue.deQueue();
    queue.deQueue();
}

void test03()
{
    BinarySearchTree<int> bst;

    bst.insert(9);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(170);
    bst.insert(15);
    bst.insert(1);

    bst.remove(20);
}

int main()
{
    vector<char> one{'a', 'b', 'c', 'x'};
    vector<char> two{'z', 'y', 'i'};
    vector<char> twob{'z', 'y', 'x'};

    cout << "case1 " << find_common2(one, two) << endl;
    cout << "case2 " << find_common2(one, twob) << endl;

    vector<int> arr1{0, 3, 4, 31, 34};
    vector<int> arr2{4, 6, 35};
    cout << reverse_string("Hello my name is Jari") << endl;

    cout << "merged array is: ";
    for (auto value : merge_sorted_arrays(arr1, arr2)) {
        cout << value << " ";
    }
    cout << endl;

    cout << "set1: " << first_recurring_numb(vector<int>{2, 5, 1, 2, 3, 5, 1, 2, 4}) << endl;
    cout << "set2: " << first_recurring_numb(vector<int>{2, 5, 1, 3, 3, 5, 1, 2, 4}) << endl;


    /*HashTable<int> htable(3);
    htable.set("one", 11);
    htable.set("two", 22);
    htable.set("three", 33);
    htable.set("four", 44);
    htable.set("five", 55);

    cout << "Hash1 " << htable.get("one") << endl;
    cout << "Hash2 " << htable.get("two") << endl;
    cout << "Hash3 " << htable.get("three") << endl;
    cout << "Hash3 " << htable.get("four") << endl;
    htable.dump();

    cout << "Keys:" << endl;
    for (auto key : htable.keys()) {
        cout << " - " << key << endl;
    }*/

/*
    LinkList<int> list;
    list.Append(10);
    list.Append(20);
    list.Print();
*/
    //test01();
    //test02();
    test03();

    return 0;
}
