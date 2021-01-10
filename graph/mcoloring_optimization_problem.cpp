/*
** @Author: Sandeep Thapar
**
** m coloring optimization problem
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void graphColoring(vector<int> graph[], int V)
{
    vector<int> color(V, -1);
    color[0]  = 1;

    // colors already assigned to neighbors
    vector<bool> alreadyAssigned(V);

    for (int u = 1; u < V; u++)
    {
        fill(alreadyAssigned.begin(), alreadyAssigned.end(), false);
        
        for (auto av : graph[u])
            if (color[av] != -1)
                alreadyAssigned[color[av]] = true;

        // Find the first available color
        int c;
        for (c = 1; c <= V; c++)
            if (alreadyAssigned[c] == false)
                break;

        color[u] = c; // Assign the found color
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex" << u << " ---> Color " << color[u] << endl;
    cout << "Number of colors required: " << *max_element(color.begin(), color.end()) << endl;
}

void addEdge(vector<int> graph[],
             int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

int main()
{
    int V = 10;
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 9);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 7);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);

    graphColoring(graph, V);
    cout << endl;
    return 0;
}


