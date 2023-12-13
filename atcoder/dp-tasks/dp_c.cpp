#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 5;
int dp[N][3];
int abc[N][3];

int func(int idx, int choice)
{
    if (idx < 0)
        return 0;

    if (dp[idx][choice] != -1)
        return dp[idx][choice];

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != choice)
        {
            ans = max(ans, abc[idx][choice] + func(idx - 1, i));
        }
    }

    return dp[idx][choice] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> abc[i][0] >> abc[i][1] >> abc[i][2];
    }

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, func(n - 1, i));
    }

    cout << ans;
}