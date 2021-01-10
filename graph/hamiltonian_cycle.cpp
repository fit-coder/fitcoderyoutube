/*
** @Author: Sandeep Thapar
**
** Check if hamiltonian cycle is present or not
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define V 7

using namespace std;

bool hamiltonianCycle(vector<int> graph[], vector<bool> visited, vector<int>& path, int v)
{
    if (path.size() == V)
        return true;
    for (auto av : graph[v])
    {
        if (visited[av] == false)
        {
            visited[av] = true;
            path.emplace_back(av);
            if (hamiltonianCycle(graph, visited, path, av))
                return true;
            visited[av] = false;
            path.pop_back();
        }
    }
    return false;
}

void addEdge(vector<int> graph[],
             int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int main()
{
    vector<int> graph[V];
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);

    vector<bool> visited(V, false);
    vector<int> path;
    path.emplace_back(0);
    visited[0] = true;
    
    cout << "Hamiltonian Cycle: ";
    if (hamiltonianCycle(graph, visited, path, 0))
    {
        for (int i : path)
            cout << i << "  ";
        cout << path[0] << endl;
    }
    else
        cout << "0" << endl;
    return 0;
}


