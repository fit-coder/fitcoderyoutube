/*
** @Author: Sandeep Thapar
**
** Detect cycle in graph using disjoint set data structure
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>

using namespace std;

void make_set(vector<int>& parent)
{
    for (int i=0; i < parent.size(); i++)
        parent[i] = i;
}

int find(vector<int>& parent, int x)
{
    if(x != parent[x])
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_set(vector<int>& parent, vector<int>& rank, int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX == rootY)
        return;
    if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
            rank[rootY]++;
    }
}

bool isCyclePresent(vector<pair<int,int>>& allEdges, int size)
{
    vector<int> parent(size);
    vector<int> rank(size, 0);

    make_set(parent);

    for (int i = 0; i < allEdges.size() ; i++)
    {
        int rootX = find(parent, allEdges[i].first);
        int rootY = find(parent, allEdges[i].second);
        if (rootX == rootY)
            return true;
        else
            union_set(parent, rank, rootX, rootY);
    }
    return false;
}

void addEdge(vector<int> graph[], vector<pair<int,int>>& allEdges, int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
    allEdges.emplace_back(make_pair(u,v));
}

int main()
{
    int V = 6;
    vector<int> graph[V];
    vector<pair<int,int>> allEdges;
    
    addEdge(graph, allEdges, 0, 1);
    addEdge(graph, allEdges, 0, 2);
    addEdge(graph, allEdges, 1, 3);
    addEdge(graph, allEdges, 2, 3);
    addEdge(graph, allEdges, 3, 4);
    addEdge(graph, allEdges, 4, 5);

    cout << "IsCycle present: " << isCyclePresent(allEdges, V) << endl;
    return 0;
}
