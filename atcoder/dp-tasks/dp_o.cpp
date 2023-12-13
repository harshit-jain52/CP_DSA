#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int SIZE = 22;
int n;

int a[SIZE][SIZE];
int dp[SIZE][1 << SIZE];

int matching(int idx, int mask)
{
    if (idx >= n)
        return 1;

    if (dp[idx][mask] != -1)
        return dp[idx][mask];

    int ct = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[idx][j] == 1 && (mask & (1 << j)) != 0)
        {
            ct = (ct + matching(idx + 1, mask ^ (1 << j)) % M) % M;
        }
    }

    return dp[idx][mask] = ct;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << matching(0, (1 << n) - 1);
}