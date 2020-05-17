#include "Graph.h"

Graph::Graph(int V)
{
    this->V = V;
    adjacencyList = new std::list<int>[V];
}

// Return size of graph (number of vertices)
int Graph::size() const
{
    return this->V;
}

// Return neighbours for specific vertex
std::list<int> Graph::getNeighbours(int vertex) const
{
    return this->adjacencyList[vertex];
}

// Add w to v’s list.
void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}
