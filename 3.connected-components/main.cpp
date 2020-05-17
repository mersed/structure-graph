/**
 * We said that depth-first-search is the one of the base core algorithms for the graphs,
 * and other algorithms are using this algo as base.
 *
 * Depth first search is not that really useful by itself, because the only thing its doing,
 * is traversing through the graph and checking which nodes we have - and which we already visited.
 *
 * However, we can use depth first search to detect connected components for example.
 * Sometimes a graph is split into multiple components. It's useful to be able to identify
 * and count these components.
 *
 * We can do that by adding unique ID value per connected component to each vertex
 * in the connected component.
 *
 * Other things depth first search algorithm can do:
 * - Compute a graph's minimum spanning tree
 * - Detect and find cycles in graph
 * - Check if a graph is bipartite
 * - Find strongly connected components
 * - Topologically sort the nodes of a graph
 * - Finds bridges and articulation points
 * - Find augmenting paths in a flow network
 * - Generate mazes
 */

#include <vector>
#include <iostream>
#include "Graph.h"

void DFS(
        const Graph &graph,
        std::vector<bool> &visited,
        int vertex,
        std::vector<int> &components,
        const int componentId
)
{
    if(visited[vertex]) return;
    visited[vertex] = true;
    components[vertex] = componentId;

    std::list<int> neighbours = graph.getNeighbours(vertex);
    std::list<int>::iterator it;
    for(it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        if(!visited[*it])
        {
            DFS(graph, visited, *it, components, componentId);
        }
    }
}

std::vector<std::vector<int>> findComponents(const Graph &graph)
{
    int componentId = -1;
    std::vector<bool> visited(graph.size());
    std::vector<int> components(graph.size());

    for(int i=0; i<graph.size(); i++)
    {
        if(!visited[i])
        {
            componentId++;
            DFS(graph, visited, i, components, componentId);
        }
    }

    // Loop and organize
    std::vector<std::vector<int>> orgComponents(componentId + 1);
    for (auto itr = components.begin(); itr != components.end(); ++itr) {
        orgComponents[*itr].push_back(itr - components.begin());
    }

    return orgComponents;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(18);
    g.addEdge(0, 8);
    g.addEdge(8, 14);
    g.addEdge(8, 4);
    g.addEdge(4, 0);
    g.addEdge(14, 0);
    g.addEdge(14, 13);
    g.addEdge(13, 0);

    g.addEdge(1, 5);
    g.addEdge(5, 17);
    g.addEdge(5, 16);

    g.addEdge(6, 11);
    g.addEdge(11, 7);
    g.addEdge(7, 6);

    g.addEdge(9, 3);
    g.addEdge(9, 15);
    g.addEdge(15, 10);
    g.addEdge(15, 2);
    g.addEdge(2, 9);


    std::vector<std::vector<int>> components = findComponents(g);
    for (auto itr = components.begin(); itr != components.end(); ++itr)
    {
        std::cout << "Component (group) " << (itr - components.begin()) << " contains following verteces: " << std::endl;
        for(auto jItr = (*itr).begin(); jItr != (*itr).end(); ++jItr)
        {
            std::cout << *jItr << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }


    return 0;
}