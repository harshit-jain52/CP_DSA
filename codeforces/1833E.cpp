#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int free_end = 0;
unordered_set<int> g[N];
vector<bool> vis(N, false);

void dfs(int v)
{
    vis[v] = true;

    for (auto it : g[v])
    {
        if (!vis[it])
            dfs(it);
    }

    if (g[v].size() == 1)
        free_end++;
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        vis[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        reset(n);

        for (i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            g[i].insert(v);
            g[v].insert(i);
        }

        int ends = 0, cycles = 0;

        for (i = 1; i < n; i++)
        {
            if (!vis[i])
            {
                free_end = 0;
                dfs(i);
                if (free_end == 0)
                    cycles++;
                else
                    ends += free_end;
            }
        }

        int maxr, minr;
        minr = cycles + int(ends != 0);
        maxr = cycles + ends / 2;

        cout << minr << " " << maxr << endl;
    }
}