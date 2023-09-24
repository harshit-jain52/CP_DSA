#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll dp[410][410];
ll prefix_sum[410];
int N;

ll slime(int l, int r, ll a[])
{
    if (l >= r || l < 0 || r >= N)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = 1e15;
    for (int i = l; i < r; i++)
    {
        ans = min(ans, (prefix_sum[r + 1] - prefix_sum[l]) + slime(l, i, a) + slime(i + 1, r, a));
        // Approach: assuming this to be the LAST slime
    }

    return dp[l][r] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    ll a[N];
    prefix_sum[0] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    cout << slime(0, N - 1, a);
}