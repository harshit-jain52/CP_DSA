#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef unsigned long long ull;
const int M = 1e9 + 7;

ull dp[15][127][126][2];

ull func(int dig, int sum, bool strict, int d, string &k, int n, ull num)
{
    if (dig == n)
        return (sum == 0 && num % d == 0);

    if (dp[dig][sum][num % d][strict] != -1)
        return dp[dig][sum][num % d][strict];

    int lim = k[dig] - '0';

    ull ans = 0;

    for (int i = 0; i < lim; i++)
        if (sum - i >= 0)
            ans += func(dig + 1, sum - i, false, d, k, n, num * 10 + i);

    if (strict)
    {
        if (sum - lim >= 0)
            ans += func(dig + 1, sum - lim, true, d, k, n, num * 10 + lim);
    }
    else
        for (int i = lim; i <= 9; i++)
            if (sum - i >= 0)
                ans += func(dig + 1, sum - i, false, d, k, n, num * 10 + i);

    return dp[dig][sum][num % d][strict] = ans;
}

ull digitSum(int d, string &k)
{
    int n = k.length();

    memset(dp, -1, sizeof(dp));

    ull ans = 0;
    int first = k[0] - '0';

    for (int i = 0; i < first; i++)
        if (d - i >= 0)
            ans += func(1, d - i, false, d, k, n, i);

    if (d - first >= 0)
        ans += func(1, d - first, true, d, k, n, first);

    return ans;
}

int main()
{
    FASTIO
    ull n;
    cin >> n;
    string k = to_string(n);
    ull final = 0;
    for (int num = 1; num <= 126; num++)
        final += digitSum(num, k);

    cout << final;
}