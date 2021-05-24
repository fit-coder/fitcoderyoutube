/*
** @Author: Sandeep Thapar
**
** Topological sort using modified DFS for a directed acyclic graph
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
}

void topological_sort(vector<int> graph[], vector<bool>& visited,
                      list<int>& result, int node)
{
    visited[node] = true;
    for (auto i = graph[node].begin(); i != graph[node].end(); i++)
    {
        if (!visited[*i])
           topological_sort(graph, visited, result, *i);
    }
    result.push_front(node);
}

int main() {
    int V = 5;
    vector<int> graph[V];
    vector<bool> visited(V, false);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    
    list<int> result ;
    cout << "Topological sort using DFS: " << endl;
    for (int i=0; i < V; ++i)
        if (!visited[i])
           topological_sort(graph, visited, result, i);
    for (auto i : result)
       cout << i << " ";
    cout << endl;

    return 0;
}

