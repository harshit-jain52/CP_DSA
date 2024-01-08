#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> tree[n + 1];
    vector<int> numEdges(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        numEdges[u]++;
        numEdges[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (numEdges[i] == 1)
        {
            q.push(i);
        }
    }

    int left = n;
    int op = 0;
    vector<int> numLeft(n + 1);
    numLeft[0] = n;

    while (!q.empty())
    {
        int cut = q.size();
        left -= cut;
        while (cut--)
        {
            int v = q.front();
            q.pop();
            for (int u : tree[v])
            {
                if (numEdges[u] <= 1)
                    continue;
                numEdges[u]--;
                if (numEdges[u] == 1)
                    q.push(u);
            }
        }
        numLeft[++op] = left;
    }

    if (k >= op)
        cout << 0;
    else
        cout << numLeft[k];
    cout << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}