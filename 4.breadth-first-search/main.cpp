/**
 * The breadth first search is another fundamental algorithm used to explore
 * nodes and edges in the graph. It runs with a time complexity of O(V+E) and
 * is often used as a building block in other algorithms.
 *
 * The BFS algorithm is particularly useful for one thing: finding the shortest path
 * on unweighted graphs.
 */
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

void breadthFirstSearch(const Graph &graph, int vertex)
{
    // Mark all the vertices as not visited
    std::vector<bool> visited(graph.size(), false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertex] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test methods of graph class
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

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    breadthFirstSearch(g, 2);

    return 0;
}
