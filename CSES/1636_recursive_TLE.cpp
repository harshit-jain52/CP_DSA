#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
int dp[110][1000010];

int func(int idx, int amt, vector<int> &coins)
{
    if (amt == 0)
        return 1;

    if (idx < 0)
        return 0;

    if (dp[idx][amt] != -1)
        return dp[idx][amt];

    int ans = 0;
    for (int ct_amt = 0; ct_amt <= amt; ct_amt += coins[idx])
    {
        ans = (ans % M + func(idx - 1, amt - ct_amt, coins) % M) % M;
    }
    return dp[idx][amt] = ans;
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
    sort(c.begin(), c.end());
    cout << func(n - 1, x, c);
}