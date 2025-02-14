#pragma once

#include <map>
#include <string>
#include <list>
#include <iostream>

class Graph {
public: 
    Graph()  { 
    }

    void addVertex(std::string node)  {
        adjacentList.insert_or_assign(node, std::list<std::string>());
    }

    void addEdge(std::string node1, std::string node2) {
        adjacentList[node1].push_back(node2);
        adjacentList[node2].push_back(node1);
    }

    void showConnections() {
        for (const auto& pair : adjacentList) {
            std::cout << pair.first << "-->";
            for (const auto& vertex : pair.second) {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::map<std::string, std::list<std::string>> adjacentList;
};
