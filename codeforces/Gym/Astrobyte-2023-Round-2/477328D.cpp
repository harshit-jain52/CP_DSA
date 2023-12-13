#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 1;
const ll INF = 1e15;

int maxlen;
vector<int> g[N];
vector<ll> dp;
ll p[N];

void reset(int n)
{
    maxlen = 0;
    dp.clear();
    dp.push_back(-INF);
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        dp.push_back(INF);
    }
}

void func(int v, int par)
{
    int len = (int)(lower_bound(dp.begin(), dp.end(), p[v]) - dp.begin());
    ll tmp = dp[len];
    dp[len] = p[v];

    maxlen = max(maxlen, (int)(lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) - 1);

    for (int child : g[v])
    {
        if (child == par)
            continue;

        func(child, v);
    }

    dp[len] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        reset(n);

        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }

        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        func(1, 0);

        cout << maxlen << endl;
    }
}