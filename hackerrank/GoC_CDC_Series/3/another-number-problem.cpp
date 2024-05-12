#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
int dp[N];

int func(int n)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    int ct = 0;
    if (n >= 3)
        ct = (ct + func(n - 3)) % M;
    if (n >= 5)
        ct = (ct + func(n - 5)) % M;
    if (n >= 10)
        ct = (ct + func(n - 10)) % M;

    return dp[n] = ct;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << func(n);
}