#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 1;

int dp[1001][N];
int h[1001], s[1001];

int func(int idx, int money_left)
{
    if (money_left == 0 || idx < 0)
        return 0;

    if (dp[idx][money_left] != -1)
        return dp[idx][money_left];

    int ans = 0;
    if (h[idx] <= money_left)
    {
        ans = max(ans, s[idx] + func(idx - 1, money_left - h[idx]));
    }
    ans = max(ans, func(idx - 1, money_left));

    return dp[idx][money_left] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    cout << func(n - 1, x);
}