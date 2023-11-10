// Eulerian Path: A path that goes exactly once through each edge of the graph
// Eulerian Circuit: Eulerian path that starts and ends at the same vertex

/*
Existence of Eulerian Path in an Undirected Graph:
(i) All vertices should belong to the same connected component
(ii) Either
    (a) Degree of all vertices is even; Each Eulerian path is an Eulerian Circuit.
     Or
    (b) Degree of exactly 2 vertices is odd, others even; odd-degree vertices are starting and ending points, not circuit

Existence of Eulerian Path in a Directed Graph:
(i) All vertices should belong to the same connected component
(ii) Either
    (a) in each node, indegree=outdegree; Each Eulerian Path is an Eulerian Circuit
     Or
    (b) in one node indegree=outdegree+1, in another node outdegree=indegree+1, all other nodes indegree=outdegree; not circuit
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vector<bool> seen(N, false);
vector<int> path; // behaves like a stack

void dfs(int v) // Hierholzer’s algorithm to find Eulerian Circuit; O(E)
{
    while (!g[v].empty())
    {
        auto [child, edgeNum] = g[v].back();
        g[v].pop_back(); // remove edge

        if (seen[edgeNum])
            continue;

        seen[edgeNum] = true;
        dfs(child);
    }
    path.push_back(v);
}