#include "graph.hpp"
#include "algorithms.hpp"
#include "linkedlist.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace algo;
int main() {
    graphs::Graph g(5); 
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    g.printGraph(); // Should print something like:
    /*
    Adjacency list of vertex 0: (4, 1) -> (1, 1) -> NULL
    Adjacency list of vertex 1: (4, 1) -> (3, 1) -> (2, 1) -> (0, 1) -> NULL
    Adjacency list of vertex 2: (3, 1) -> (1, 1) -> NULL
    Adjacency list of vertex 3: (4, 1) -> (2, 1) -> (1, 1) -> NULL
    Adjacency list of vertex 4: (3, 1) -> (1, 1) -> (0, 1) -> NULL
    */
    
    cout << "BFS starting from vertex 0:" << endl;
    LinkedList bfs = Algorithms::bfs_scan(g, 0); 
    Algorithms::print_algorithm_result(bfs) // Should print 0 4 1 3 2 
    
    cout << "DFS starting from vertex 0:" << endl;
    LinkedList dfs = algos::Algorithms::dfs_scan(g, 0); 
    Algorithms::print_algorithm_result(dfs) // Should print 0 4 3 2 1
    
    cout << "Dijkstra from 0 to 3:" << endl;
    LinkedList dijkstra = algos::Algorithms::dijkstra_path(g, 0, 3); 
    Algorithms::print_algorithm_result(dijkstra, true) // Should print something like: Shortest path from 0 to 3 is: 0->4->3 with weight 2
        
    cout << algos::Algorithms::has_cycle(g) << endl; // Should print true
    
    return 0;
}
