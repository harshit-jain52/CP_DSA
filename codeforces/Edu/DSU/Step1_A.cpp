#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int set_size[N];

void make(int v)
{
    parent[v] = v;
    set_size[v] = 1;
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
        if (set_size[a] < set_size[b])
            swap(a, b);

        parent[b] = a;
        set_size[a] += set_size[b];
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
    while (m--)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (s == "union")
        {
            unionBySize(u, v);
        }
        else
        {
            cout << ((find(u) == find(v)) ? "YES" : "NO") << endl;
        }
    }
}