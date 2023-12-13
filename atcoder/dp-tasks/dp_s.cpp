#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e4 + 1;
int dp[N][100][2];

int func(int dig, int sumMod, bool strict, int d, string &k, int n)
{
    if (dig == n)
        return (sumMod == 0);

    if (dp[dig][sumMod][strict] != -1)
        return dp[dig][sumMod][strict];

    int lim = k[dig] - '0';

    int ans = 0;

    for (int i = 0; i < lim; i++)
        ans = (ans + func(dig + 1, (sumMod + i) % d, false, d, k, n)) % M;

    if (strict)
        ans = (ans + func(dig + 1, (sumMod + lim) % d, true, d, k, n)) % M;
    else
        for (int i = lim; i <= 9; i++)
            ans = (ans + func(dig + 1, (sumMod + i) % d, false, d, k, n)) % M;

    return dp[dig][sumMod][strict] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string k;
    int d, n;
    cin >> k >> d;
    n = k.length();

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    int first = k[0] - '0';

    for (int i = 0; i < first; i++)
        ans = (ans + func(1, i % d, false, d, k, n)) % M;

    ans = (ans + func(1, first % d, true, d, k, n)) % M;

    cout << (ans - 1 + M) % M;
}