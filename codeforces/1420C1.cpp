#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 3e5 + 10;
const int INF = 1e15;

int a[N];
ll dp[N][2];

void reset(int n)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = INF;
    }
}

ll func(int idx, bool toAdd)
{
    if (idx < 0)
        return 0;

    if (dp[idx][toAdd] != INF)
        return dp[idx][toAdd];

    ll ans = 0;

    ans = max(ans, func(idx - 1, toAdd));

    if (toAdd)
        ans = max(ans, a[idx] + func(idx - 1, 0));
    else
        ans = max(ans, -a[idx] + func(idx - 1, 1));

    return dp[idx][toAdd] = ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        reset(n);

        cout << max(func(n - 1, 1), func(n - 1, 0)) << endl;
    }
}