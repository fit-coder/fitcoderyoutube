/*
** @Author: Sandeep Thapar
**
** Dinic's algorithm for maximum flow problem
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

#define V 6

// Finds if more flow can be sent from source to sink.
// Also assigns levels to nodes.
bool bfs(vector<vector<int>>& residualGraph, vector<int>& level, int source, int sink)
{
    fill(level.begin(), level.end(), -1);
	level[source] = 0;
	
	queue<int> q;
	q.push(source);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v=0; v < V; v++)
		{
			if (u != v && residualGraph[u][v] > 0 && level[v] < 0)
			{
				// Level of current vertex is level of parent + 1
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	// IF we can not reach to the sink we
	// return false else true
	return level[sink] < 0 ? false : true ;
}

// A DFS based function to send flow after BFS has figured out that there is a possible flow and
// constructed levels. This function called multiple times for a single call of BFS.
// flow : Current flow send by parent function call
// count[] : count of edges explored from i.
// u : Current vertex
int sendFlow(vector<vector<int>>& residualGraph, vector<int>& level, vector<int>& count, int u, int sink, int flow)
{
	// Sink reached
	if (u == sink)
		return flow;

    if (count[u] == residualGraph[u].size())
	    return 0;

	// Traverse all adjacent edges one-by-one.
	for (int v=0; v < V; v++)
	{
		if (residualGraph[u][v] > 0)
		{
		    count[u]++;
			if (level[v] == level[u]+1)
			{
                // find minimum flow from u to sink
			 	int curr_flow = min(flow, residualGraph[u][v]);

			    int min_cap = sendFlow(residualGraph, level, count, v, sink, curr_flow);
			    if (min_cap > 0)
			    {
                    residualGraph[u][v] -= min_cap;
                    residualGraph[v][u] += min_cap;
				    return min_cap;
			    }
			}
		}
	}
	return 0;
}

int dinic_algorithm(vector<vector<int>>& graph, int source, int sink)
{
	if (source == sink)
		return -1;

	int max_flow = 0;
    vector<vector<int>> residualGraph = graph;
    vector<int> level(V, -1);

	// Augment the flow while there is path from source to sink
	while (bfs(residualGraph, level, source, sink) == true)
	{
		// store how many neighbors are visited
		vector<int> count(V, 0);

		// while flow is not zero in graph from source to sink
		while (int flow = sendFlow(residualGraph, level, count, source, sink, INT_MAX))
			max_flow += flow;
	}
	return max_flow;
}

void addEdge(vector<vector<int>>& graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{
    vector<vector<int>> graph(V, vector<int> (V, 0));

	addEdge(graph, 0, 1, 10);
	addEdge(graph, 0, 2, 10);
	addEdge(graph, 1, 2, 2);
	addEdge(graph, 1, 3, 4);
	addEdge(graph, 1, 4, 8);
	addEdge(graph, 2, 4, 9);
	addEdge(graph, 3, 5, 10);
	addEdge(graph, 4, 3, 6);
	addEdge(graph, 4, 5, 10);

	cout << "Maximum flow: " << dinic_algorithm(graph, 0, 5);
	return 0;
}

