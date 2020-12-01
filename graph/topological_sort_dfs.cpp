/*
** Topological sort using modified DFS for a directed acyclic graph
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
** Please subscribe if you like the content
*/

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void topological_sort(vector<int> graph[], vector<bool>& visited,
                      vector<int>& result, int node)
{
    visited[node] = true;
    for (auto i = graph[node].begin(); i != graph[node].end(); i++) {
        if (!visited[*i])
           topological_sort(graph, visited, result, *i);
    }
    result.emplace_back(node);
}

int main() {
    vector<int> graph[5];
    vector<bool> visited(5, false);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    
    vector<int> result ;
    cout << "Topological sort using DFS: " << endl;
    topological_sort(graph, visited, result, 0);
    for (int i=result.size()-1; i >= 0; i--)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

