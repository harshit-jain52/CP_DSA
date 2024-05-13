#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
int n;
int c[501];
int dp[501][501];

int func(int l, int r)
{
    if (l >= r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1e7;
    if (c[l] == c[r])
        ans = func(l + 1, r - 1);
    for (int i = l; i < r; i++)
    {
        if (c[i] == c[l])
            ans = min(ans, func(l, i) + func(i + 1, r));
    }
    return dp[l][r] = ans;
}

int main()
{
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    memset(dp, -1, sizeof(dp));
    cout << func(0, n - 1);
}