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
string s;
int dp[501][501];

int func(int l, int r)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 1 + func(l + 1, r);
    for (int i = l + 1; i <= r; i++)
    {
        if (s[i] == s[l])
            ans = min(ans, func(l + 1, i - 1) + func(i, r));
    }
    return dp[l][r] = ans;
}

int main()
{
    FASTIO
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    cout << func(0, n - 1);
}