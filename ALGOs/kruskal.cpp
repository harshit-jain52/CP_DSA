// Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void unionBySize(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edges.push_back({wt, {a, b}});
    }
    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    for (auto &e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (find(u) == find(v))
            continue;

        unionBySize(u, v);
        total_cost += w;
        cout << u << " " << v << endl;
    }
    cout << total_cost << endl;
}