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
vector<pair<int, int>> bridges;
int tin[N], lo[N], timer = 0;

void dfs(int cur, int par)
{
    tin[cur] = lo[cur] = ++timer;

    for (int ch : g[cur])
    {
        if (ch == par)
            continue;

        if (tin[ch])
            lo[cur] = min(lo[cur], tin[ch]);
        else
        {
            dfs(ch, cur);
            if (lo[ch] > tin[cur])
                bridges.push_back({cur, ch});
            lo[cur] = min(lo[cur], lo[ch]);
        }
    }
}

int main()
{
    FASTIO
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    cout << bridges.size() << endl;
    for (auto br : bridges)
        cout << br.first << " " << br.second << endl;
}