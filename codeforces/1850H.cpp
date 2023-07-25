#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 5;

vector<pair<int, ll>> g[N];
bool visited[N];
ll x[N];
bool ans;

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        visited[i] = false;
        x[i] = 0;
    }
    ans = true;
}

void dfs(int vertex)
{
    visited[vertex] = true;

    for (auto it : g[vertex])
    {
        int num = it.first;
        ll dist = it.second;

        if (visited[num])
        {
            if (x[num] != x[vertex] + dist)
            {
                ans = false;
                return;
            }
        }
        else
        {
            x[num] = x[vertex] + dist;
            dfs(num);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        reset(n);

        while (m--)
        {
            int a, b;
            ll d;
            cin >> a >> b >> d;
            g[a].push_back({b, d});
            g[b].push_back({a, -d});
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}