#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
typedef long long int ll;
ll row[N];
ll dp[1000005];
ll func(ll x)
{
    if (x <= 0)
    {
        return 0;
    }
    if (dp[x] != -1)
        return dp[x];
    ll n = row[x];
    ll sum = x * x;
    if (x == n * (n + 1) / 2)
    {
        sum += func(x - n);
    }
    else if (x == n * (n - 1) / 2 + 1)
    {
        sum += func(x - n + 1);
    }
    else
    {
        sum += func(x - n) + func(x - n + 1) - func(x - n - row[x - n] + 1);
    }

    return dp[x] = sum;
}

int main()
{
    row[0] = 0;
    for (ll n = 1; n * (n + 1) / 2 <= N; n++)
    {
        for (ll num = n * (n - 1) / 2 + 1; num <= n * (n + 1) / 2; num++)
        {
            row[num] = n;
        }
    }

    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        cout << func(n) << endl;
    }
}