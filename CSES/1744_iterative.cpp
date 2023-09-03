#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;

    int dp[a + 1][b + 1];

    for (int i = 1; i <= a; i++)
        dp[i][1] = i - 1;

    for (int j = 1; j <= b; j++)
        dp[1][j] = j - 1;

    for (int i = 2; i <= a; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            int ct = 1e9;

            for (int k = 1; k <= i - 1; k++)
            {
                ct = min(ct, 1 + dp[k][j] + dp[i - k][j]);
            }
            for (int k = 1; k <= j - 1; k++)
            {
                ct = min(ct, 1 + dp[i][k] + dp[i][j - k]);
            }

            dp[i][j] = ct;
        }
    }

    cout << dp[a][b];
}