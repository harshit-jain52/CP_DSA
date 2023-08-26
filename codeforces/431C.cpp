#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll dp[110][110][2];
int n, k, d;

ll func(int idx, int rem, bool used)
{
    if (rem == 0)
        return (int)used;
    if (idx == n)
        return 0;

    if (dp[idx][rem][used] != -1)
        return dp[idx][rem][used];

    ll ct = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i > rem)
            break;

        ct = (ct + func(idx + 1, rem - i, used || (i >= d)) % M) % M;
    }

    return dp[idx][rem][used] = ct % M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> d;

    memset(dp, -1, sizeof(dp));

    cout << func(0, n, false);
}