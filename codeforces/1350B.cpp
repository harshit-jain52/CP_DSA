#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 5;
ll s[N];
int dp[N];

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
}

int func(int idx)
{
    if (idx == 1)
        return 1;
    if (dp[idx] != -1)
        return dp[idx];

    int ct = 1;
    for (ll i = 1; i * i <= idx; i++)
    {
        if (idx % i == 0)
        {
            if (s[idx] > s[i])
                ct = max(ct, 1 + func(i));
            if (s[idx] > s[idx / i])
                ct = max(ct, 1 + func(idx / i));
        }
    }
    return dp[idx] = ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        reset(n);

        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, func(i));
        }

        cout << ans << endl;
    }
}