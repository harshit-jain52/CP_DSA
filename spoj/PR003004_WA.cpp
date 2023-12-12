#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int M = 1e9 + 7;

ull dp1[16][127][2];
ull dp2[16][127][2];

ull func(int dig, int sum, bool strict, string &k, int n, ull dp[16][127][2])
{
    if (dig == n)
        return (sum == 0);

    if (dp[dig][sum][strict] != ULLONG_MAX)
        return dp[dig][sum][strict];

    int lim = k[dig] - '0';

    ull ans = 0;

    for (int i = 0; i <= min(sum, lim - 1); i++)
        ans += func(dig + 1, sum - i, false, k, n, dp);

    if (strict)
    {
        if (sum >= lim)
            ans += func(dig + 1, sum - lim, true, k, n, dp);
    }
    else
        for (int i = lim; i <= min(sum, 9); i++)
            ans += func(dig + 1, sum - i, false, k, n, dp);

    return dp[dig][sum][strict] = ans;
}

ull calc(ll x, int sum, ull dp[16][127][2])
{
    if (x < 0)
        return 0;
    string k = to_string(x);
    int n = k.length();

    int first = k[0] - '0';

    ull ans = 0;
    for (int i = 0; i <= min(sum, first - 1); i++)
        ans += func(1, sum - i, false, k, n, dp);

    if (sum >= first)
        ans += func(1, sum - first, true, k, n, dp);

    return ans;
}

void MEMSET()
{
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 127; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                dp1[i][j][k] = ULLONG_MAX;
                dp2[i][j][k] = ULLONG_MAX;
            }
        }
    }
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
        ll a, b;
        cin >> a >> b;

        ull final = 0;
        MEMSET();
        for (int num = 1; num <= 126; num++)
        {
            final += num * (calc(b, num, dp1) - calc(a - 1, num, dp2));
        }

        cout << final << endl;
    }
}