#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
int dp[1000010];

int func(int amt, vector<int> &coins)
{
    if (amt == 0)
        return 1;

    if (dp[amt] != -1)
        return dp[amt];

    int ans = 0;
    for (int coin : coins)
    {
        if (amt - coin >= 0)
        {
            ans = (ans % M + func(amt - coin, coins) % M) % M;
        }
    }
    return dp[amt] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    cout << func(x, c);
}