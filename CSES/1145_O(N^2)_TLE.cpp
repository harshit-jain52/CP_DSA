#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int dp[N];
vector<ll> x(N);

int func(int idx)
{
    if (dp[idx] != -1)
        return dp[idx];

    int ans = 1;
    for (int j = 0; j < idx; j++)
    {
        if (x[j] < x[idx])
        {
            ans = max(ans, 1 + func(j));
        }
    }
    return dp[idx] = ans;
}
// O(N^2)
int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, func(i));
    }
    cout << ans;
}