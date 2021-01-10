/*
** @Author: Sandeep Thapar
**
** Prim's algorithm for minimum spanning tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int,int,int>> prim(vector<vector<pair<int,int>>>& graph,
                                int start)
{
    vector<int> parent(graph.size(), -1);
    vector<int> key(graph.size(), INT_MAX);
    vector<bool> inMST(graph.size(), false);
    key[start] = 0;

    // <key, vertex> pair. First element of priority queue will be the minimum
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));
    
    vector<tuple<int,int,int>> result;
    while (!pq.empty())
    {
        // Get min distance vertex from pq
        int v = pq.top().second;
        pq.pop();
        
        if (parent[v] != -1 && inMST[v] == false)
            result.emplace_back(make_tuple(parent[v], v, key[v]));

        inMST[v] = true;
        cout << v <<endl;
        for(auto x : graph[v])
        {
            int av = x.first;
            int weight = x.second;
            if (inMST[av] == false && key[av] > weight)
            {
                parent[av] = v;
                key[av] = weight;
                pq.push(make_pair(key[av],av));
            }
        }
    }
    return result;
}

void addEdge(vector<vector<pair<int,int>>>& graph,
             int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    int V = 7;
    // pair of vertex, weight
    vector<vector<pair<int,int>>> graph(V, vector<pair<int,int>>(V));

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 7);
    addEdge(graph, 0, 5, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 1, 5, 5);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 6, 5);
    addEdge(graph, 4, 6, 7);

    vector<tuple<int,int,int>> res = prim(graph, 0);
    cout << "Minimum Spanning Tree: " << endl;
    for (tuple<int,int,int> t : res)
        cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;
    return 0;
}

