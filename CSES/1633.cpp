#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
int dp[1000010];

int func(int amt, vector<int> &throws)
{
    if (amt == 0)
        return 1;

    if (dp[amt] != -1)
        return dp[amt];

    int ans = 0;
    for (int num : throws)
    {
        if (amt - num >= 0)
        {
            ans = (ans % M + func(amt - num, throws) % M) % M;
        }
    }
    return dp[amt] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> d = {1, 2, 3, 4, 5, 6};

    cout << func(n, d);
}