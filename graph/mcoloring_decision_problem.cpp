/*
** @Author: Sandeep Thapar
**
** m coloring decision problem
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

bool isValid(vector<int> graph[], vector<int>& color, int c, int v)
{
    for (auto u: graph[v])
    {
        if (color[u] == c)
           return false;
    }
    return true;
}

bool graphColoring(vector<int> graph[], vector<int> color, int m, int v, int V)
{
    if (v == V)
        return true;
    for (int c=1; c <=m; c++)
    {
        if (isValid(graph, color, c, v))
        {
            color[v] = c;
            if (graphColoring(graph, color, m, v+1, V))
                return true;
            color[v] = 0;
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
    int V = 10;
    vector<int> graph[V];
    vector<int> color(V, 0);
    
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

    int m = 1;
    cout << "Is coloring possible using 1 color: " << graphColoring(graph, color, m, 0, V) << endl;
    m = 2;
    cout << "Is coloring possible using 2 colors: " << graphColoring(graph, color, m, 0, V) << endl;
    m = 3;
    cout << "Is coloring possible using 3 colors: " << graphColoring(graph, color, m, 0, V) << endl;
    return 0;
}


