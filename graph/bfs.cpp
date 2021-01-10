/*
** @Author: Sandeep Thapar
**
** BFS traversal for a undirected unweighted graph
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void bfs(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        cout << v << "  ";
        q.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}
int main() {
    int V = 7; // vertices
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "BFS traversal starting from node 0:" << "  ";
    bfs(graph, 0);
    return 0;
}
