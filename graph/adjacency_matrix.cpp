/*
** @Author: Sandeep Thapar
**
** Draw adjacency matrix for a graph
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Graph Playlist: https://youtube.com/playlist?list=PLFj4kIJmwGu3m30HfYDDufr3PZBfyngr0
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
using namespace std;

#define V 5

void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
}

int main()
{
    int graph[V][V] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);

    cout << "Adjacency matrix:" << endl;
    for (int i=0; i < V; i++)
    {
        for (int j=0; j < V; j++)
            cout << graph[i][j] << "   ";
        cout << endl;
    }
    return 0;
}

