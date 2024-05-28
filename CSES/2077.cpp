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
bool ap[N];
int tin[N], lo[N], timer = 0;

int dfs(int cur, int par)
{
    tin[cur] = lo[cur] = ++timer;
    int children = 0;

    for (int ch : g[cur])
    {
        if (ch == par)
            continue;

        if (tin[ch])
            lo[cur] = min(lo[cur], tin[ch]);
        else
        {
            children++;
            dfs(ch, cur);
            if (lo[ch] >= tin[cur])
                ap[cur] = true;
            lo[cur] = min(lo[cur], lo[ch]);
        }
    }

    return children;
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

    int root = 1;
    ap[root] = dfs(root, 0) > 1;

    cout << count(ap + 1, ap + n + 1, true) << endl;
    for (int i = 1; i <= n; i++)
        if (ap[i])
            cout << i << " ";
}