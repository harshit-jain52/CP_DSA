#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll dp[18][10][2];

ll func(int dig, int lastDigit, bool strict, string &k, int n)
{
    if (dig == n)
        return 1;

    if (dp[dig][lastDigit][strict] != -1)
        return dp[dig][lastDigit][strict];

    int lim = k[dig] - '0';
    ll ans = 0;

    for (int i = 0; i < lim; i++)
        if (i != lastDigit)
            ans += func(dig + 1, i, false, k, n);

    if (strict)
    {
        if (lim != lastDigit)
            ans += func(dig + 1, lim, true, k, n);
    }
    else
    {
        for (int i = lim; i <= 9; i++)
            if (i != lastDigit)
                ans += func(dig + 1, i, false, k, n);
    }

    return dp[dig][lastDigit][strict] = ans;
}

ll calc(string &k)
{
    memset(dp, -1, sizeof(dp));

    int n = k.size();
    ll ans = 0;
    int first = k[0] - '0';

    for (int i = 1; i < first; i++)
        ans += func(1, i, false, k, n);

    ans += func(1, first, true, k, n);

    return ans;
}

ll final(ll num)
{
    if (num <= 0)
        return num;

    string str = to_string(num);
    int n = str.size();

    ll ans = 0;
    ans += calc(str);
    n--;

    for (; n > 0; n--)
    {
        string s(n, '9');
        ans += calc(s);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    cout << final(b) - final(a - 1);
}