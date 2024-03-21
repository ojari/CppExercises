#include <catch2/catch_all.hpp>
#include <algorithm>
#include "../Graph.hpp"


TEST_CASE( "Testing graph addVertex, addEdge", "[graph]") {
    Graph graph;

    graph.addVertex("0");
    graph.addVertex("1");
    graph.addVertex("2");
    graph.addVertex("3");
    graph.addVertex("4");
    graph.addVertex("5");
    graph.addVertex("6");

    graph.addEdge("3", "1"); 
    graph.addEdge("3", "4"); 
    graph.addEdge("4", "2"); 
    graph.addEdge("4", "5"); 
    graph.addEdge("1", "2"); 
    graph.addEdge("1", "0"); 
    graph.addEdge("0", "2"); 
    graph.addEdge("6", "5");

    graph.showConnections();
//Answer:
// 0-->1 2 
// 1-->3 2 0 
// 2-->4 1 0 
// 3-->1 4 
// 4-->3 2 5 
// 5-->4 6 
// 6-->5

    // REQUIRE( queue.DeQueue() == 10 );
    // REQUIRE( queue.DeQueue() == 20 );
}
