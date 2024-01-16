#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    string s;
    cin >> s;
    int n = s.size();

    bool dp[n][n];
    int substrPal[n][n];

    memset(dp, false, sizeof(dp));
    memset(substrPal, 0, sizeof(substrPal));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        substrPal[i][i] = 1;
    }
    
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (len == 2)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            substrPal[i][j] = substrPal[i][j - 1] + substrPal[i + 1][j] - substrPal[i + 1][j - 1] + dp[i][j];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << substrPal[l - 1][r - 1] << endl;
    }
}