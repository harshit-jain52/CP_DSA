#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int dp[2001][2][2][2001];

string a, b;
int d, m, len;

int func(int id, bool lo, bool hi, int modsum)
{
    if (id == len)
        return (modsum == 0);

    if (dp[id][lo][hi][modsum] != -1)
        return dp[id][lo][hi][modsum];

    int loLim = (lo ? (a[id] - '0') : 0);
    int hiLim = (hi ? (b[id] - '0') : 9);
    int ct = 0;
    if (id % 2 == 1)
    {
        if (d >= loLim && d <= hiLim)
            ct = func(id + 1, lo && (d == loLim), hi && (d == hiLim), (modsum * 10 + d) % m);
    }
    else
    {
        for (int dig = loLim; dig <= hiLim; dig++)
        {
            if (dig == d)
                continue;
            ct = (ct + func(id + 1, lo && (dig == loLim), hi && (dig == hiLim), (modsum * 10 + dig) % m)) % M;
        }
    }

    return dp[id][lo][hi][modsum] = ct;
}

int main()
{
    FASTIO
    memset(dp, -1, sizeof(dp));
    cin >> m >> d >> a >> b;
    len = a.size();
    cout << func(0, 1, 1, 0);
}
