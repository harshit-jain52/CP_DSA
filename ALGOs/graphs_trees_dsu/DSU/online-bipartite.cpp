#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
//  DSU that supports parity

pair<int, int> parent[N]; // {root, parity}
int set_size[N];
bool bipartite[N]; // is the connected component containing this vertex bipartite?
bool isBipartite = true; // is the whole graph bipartite?

void make(int v)
{
    parent[v] = make_pair(v, 0);
    set_size[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find(int v)
{
    if (v != parent[v].first)
    {
        int parity = parent[v].second;
        parent[v] = find(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b)
{
    pair<int, int> pa = find(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find(b);
    b = pb.first;
    int y = pb.second;

    if (a == b)
    {
        if (x == y)
        {
            bipartite[a] = false;
            isBipartite = false;
        }
    }
    else
    {
        if (set_size[a] < set_size[b])
            swap(a, b);

        parent[b] = make_pair(a, x ^ y ^ 1);
        set_size[a] += set_size[b];
        bipartite[a] &= bipartite[b];
    }
}

bool is_bipartite(int v)
{
    return bipartite[find(v).first];
}