#ifndef INC_1_GRAPH_GRAPH_H
#define INC_1_GRAPH_GRAPH_H

#include <list>

class Graph
{
    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    std::list<int> *adjacencyList;
public:
    Graph(int V);
    int size() const;
    std::list<int> getNeighbours(int vertex) const;
    void addEdge(int v, int w);
};

#endif //INC_1_GRAPH_GRAPH_H
