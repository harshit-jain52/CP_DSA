#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
int dp[1000010]; // initialized to 0

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 1;
    int n, x;
    cin >> n >> x;
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    for (auto coin : c)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i >= coin)
                dp[i] = (dp[i] % M + dp[i - coin] % M) % M;
        }
    }
    cout << dp[x];
}