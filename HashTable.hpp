#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>

/** Simple hash table where keys are always strings.
 */
template<typename T> class HashTable {
public:
    HashTable(int asize) : 
        values(asize),
        size(asize)
    {
    }

    void set(std::string key, T value) {
        int adr = makeHash(key);
        values[adr].push_back(std::make_pair(key, value));
    }

    T get(std::string key) {
        int adr = makeHash(key);
        for (auto item : values[adr]) {
            if (item.first == key) {
                return item.second;
            }
        }
        return -999;
    }

    void dump() {
        int counter = 0;
        for (auto lst : values) {
            std::cout << "--- " << counter << std::endl;
            for (auto item : lst) {
                std::cout << "    - " << item.first << " = " << item.second << std::endl;
            }
            counter++;
        }
    }

    std::vector<std::string> keys() {
        std::vector<std::string> result;
        for (auto lst : values) {
            if (!lst.empty()) {
                for (auto item : lst) {
                    result.push_back(item.first);
                }
            }
        }
        return std::move(result);
    }

private:
    int makeHash(std::string key);

private:
    std::vector<std::list<std::pair<std::string, T>>> values;
    int size;
};


template<typename T>
int HashTable<T>::makeHash(std::string key)
{
    int hash = 0;
    int index = 1;

    for (char ch : key) {
        hash = (hash + int(ch)*index) % size;
        index++;
    }
    return hash;
}
