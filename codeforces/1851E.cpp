#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 5;
ll cost[N];
bool vis[N];
vector<int> g[N];

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        g[i].clear();
    }
}

void dfs(int type)
{
    vis[type] = true;
    if (g[type].size() == 0)
        return;

    ll sum = 0;
    for (auto ingredient : g[type])
    {
        if (!vis[ingredient])
            dfs(ingredient);
        sum += cost[ingredient];
    }
    cost[type] = min(cost[type], sum);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        reset(n);

        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }

        for (int i = 0; i < k; i++)
        {
            int idx;
            cin >> idx;
            cost[idx] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int num;
                cin >> num;
                g[i].push_back(num);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i);
        }

        for (int i = 1; i <= n; i++)
        {
            cout << cost[i] << " ";
        }
        cout << endl;
    }
}