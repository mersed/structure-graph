/**
 * The Depth First Search (DFS) is the most fundamental search
 * algorithm used to explore nodes and edges of a graph. It runs with a
 * time complexity O(V+E) and is often used as a building block in other
 * algorithms.
 *
 * By itself the DFS isn't all that useful, but when augmented to perform
 * other tasks such as count connected components, determine connectivity,
 * or find bridges/articulation points, then DFS really shines.
 *
 * As the name suggests, a DFS plunges depth first into a graph without
 * regard for which edge it takes until it cannot go any further at which
 * point it backtracks and continues.
 *
 * DFS HAS TO START AT NODE 0.
 *
 * Depth First search does not care about types of the edges, are they bidirectional,
 * or something like that. It just wants to "touch" every single node using every single
 * connection from node it currently process.
 */

#include <vector>
#include <iostream>
#include "Graph.h"

void DFSExecute(const Graph &graph, std::vector<bool> &visited, int vertex)
{
    if(visited[vertex]) return;
    std::cout << "Started vertex depth search: " << vertex << std::endl;
    visited[vertex] = true;

    std::list<int> neighbours = graph.getNeighbours(vertex);
    std::list<int>::iterator it;
    for(it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        std::cout << "--- Parent: " << vertex << " neighbour " << (*it) << std::endl;
        if(!visited[*it])
        {
            std::cout << "--- --- Neighbour not visited" << std::endl;
            DFSExecute(graph, visited, *it);
        }
    }
    std::cout << "Ended vertex depth search:: " << vertex << std::endl;
}

void DFS(const Graph &graph, int startNode)
{
    std::vector<bool> visited(graph.size());
    DFSExecute(graph, visited, startNode);
}

int main()
{

    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    DFS(g, 0);

    return 0;
}