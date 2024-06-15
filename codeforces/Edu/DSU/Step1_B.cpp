#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 3e5 + 10;
int parent[N];
int set_size[N];
vector<int> maximal(N, 0), minimal(N, N + 1);

void make(int v)
{
    parent[v] = v;
    set_size[v] = 1;
    maximal[v] = minimal[v] = v;
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
        maximal[a] = max(maximal[a], maximal[b]);
        minimal[a] = min(minimal[a], minimal[b]);
    }
}

int main()
{   
    FASTIO
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int u, v;
            cin >> u >> v;
            unionBySize(u, v);
        }
        else
        {
            int x;
            cin >> x;
            int p = find(x);
            cout << minimal[p] << " " << maximal[p] << " " << set_size[p] << endl;
        }
    }
}