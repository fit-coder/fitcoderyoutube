/*
** @Author: Sandeep Thapar
**
** Articulation point using Tarjan's algo
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int time = 0;
void find_articulation_points(vector<int> graph[], vector<int>& disc, vector<int>& low,
                              vector<bool>& visited, vector<int>& parent, set<int>& result,
                              int v)
{
    visited[v] = true;
    time++;
    disc[v] = low[v] = time;
    int child = 0;
    for (auto i=graph[v].begin(); i != graph[v].end(); i++) {
        int av = *i;
        if (visited[av] == false) {
            child++;
            parent[av] = v;
            find_articulation_points(graph, disc, low, visited, parent, result, av);
            low[v] = min (low[v], low[av]);
            if (parent[v] == -1 and child > 1)
                result.emplace(v);
            else if (parent[v] != -1 and low[av] >= disc[v])
                result.emplace(v);
        }
        else if (av != parent[v])
             low[v] = min (low[v], disc[av]);
    }
}

int main() {
    int V = 7;
    vector<int> graph[V];
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    vector<int> low(V, 0);
    vector<int> disc(V, 0);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    set<int> result ;
    cout << "Articulation points using Tarjans algorithm: " << endl;
    find_articulation_points(graph, disc, low, visited, parent, result, 0);
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}


