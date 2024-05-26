#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> g[N];
int lo[N], tin[N];
int timer = 0, numBR = 0, numComp = 0;
vector<pair<int, int>> edges;

void dfs(int cur, int pp)
{
    tin[cur] = lo[cur] = ++timer;

    for (int to : g[cur])
    {
        if (to == pp)
            continue;

        if (!tin[to])
        {
            edges.push_back({cur, to}); // span-edge downwards
            dfs(to, cur);

            if (tin[cur] < lo[to])
                numBR++;

            lo[cur] = min(lo[cur], lo[to]);
        }
        else
        {
            lo[cur] = min(lo[cur], tin[to]);
            if (tin[cur] > tin[to])
                edges.push_back({cur, to}); // back-edge upwards
        }
    }
}

int main()
{
    FASTIO
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!tin[i])
        {
            numComp++;
            dfs(i, 0);
        }
    }

    if (numBR > 0 || numComp > 1)
        cout << "IMPOSSIBLE";
    else
    {
        for (auto e : edges)
        {
            cout << e.first << " " << e.second << endl;
        }
    }
}