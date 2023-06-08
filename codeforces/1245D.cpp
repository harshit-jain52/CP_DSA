#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2001;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll x[n + 1], y[n + 1], c[n + 1], k[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    for (int i = 0; i <= n; i++)
    {
        make(i);
    }

    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll wt = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back({wt, {i, j}});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }

    sort(edges.begin(), edges.end());

    ll total_cost = 0;
    vector<int> power_station;
    vector<pair<int, int>> connections;

    for (auto &e : edges)
    {
        ll w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (find(u) == find(v))
            continue;

        unionBySize(u, v);
        total_cost += w;
        if (u == 0)
        {
            power_station.push_back(v);
        }
        else
        {
            connections.push_back({u, v});
        }
    }
    cout << total_cost << endl;

    cout << power_station.size() << endl;
    for (auto it : power_station)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << connections.size() << endl;
    for (auto &it : connections)
    {
        cout << it.first << " " << it.second << endl;
    }
}