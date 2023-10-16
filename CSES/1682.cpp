#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> rev[N];
vector<bool> vis(N, false);

void dfs1(int v)
{
    vis[v] = true;

    for (int child : graph[v])
    {
        if (vis[child])
            continue;
        dfs1(child);
    }
}

void dfs2(int v)
{
    vis[v] = true;

    for (int child : rev[v])
    {
        if (vis[child])
            continue;
        dfs2(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        rev[b].push_back(a);
    }

    dfs1(1);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO" << endl
                 << 1 << " " << i;
            return 0;
        }

        vis[i] = false;
    }

    dfs2(1);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO" << endl
                 << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";
}