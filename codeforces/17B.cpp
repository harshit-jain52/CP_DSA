#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
int parent[N];
int st_size[N];

void make(int v)
{
    parent[v] = v;
    st_size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void unionDS(int a, int b)
{
    a = find(a);
    b = find(b);

    parent[b]=a;
    st_size[a]+=st_size[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    int q[n];
    for (i = 0; i < n; i++)
    {
        cin >> q[i];
        make(i + 1);
    }

    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> v;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());

    ll cost = 0;

    for (auto &it : v)
    {
        int c = it.first;
        int a = it.second.first;
        int b = it.second.second;

        if (find(a) == find(b))
            continue;
        if (find(b) != b)
            continue;

        unionDS(a, b);
        cost += c;
    }

    if (st_size[find(1)] != n)
        cout << -1;
    else
        cout << cost;
}