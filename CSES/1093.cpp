#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int dp[501][63000];

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int func(int x, int sum_left)
{
    if (sum_left == 0)
        return 1;
    if (x <= 0)
        return 0;

    if (dp[x][sum_left] != -1)
        return dp[x][sum_left];

    int notpick = func(x - 1, sum_left);

    int pick = 0;
    if (sum_left >= x)
        pick = func(x - 1, sum_left - x);

    return dp[x][sum_left] = (notpick % M + pick % M) % M;
}

int main()
{

    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;

    if (sum % 2 == 1)
        cout << 0;
    else
    {
        memset(dp, -1, sizeof(dp));
        int ans = func(n, sum / 2);

        cout << (ans * 1LL * binExp(2, M - 2)) % M; // a/b % M = (a * b^-1)%M
    }
}