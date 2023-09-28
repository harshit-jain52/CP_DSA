#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a[k - 1][n + 1], a_pos[k - 1][n + 1];
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a_pos[i][a[i][j]] = j;
        }
    }
    int b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vector<int> dp(n + 1, 1);
    int maxlen = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int x;
            for (x = 0; x < k - 1 && a_pos[x][b[j]] < a_pos[x][b[i]]; x++);
            if (x == k-1)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        maxlen = max(maxlen, dp[i]);
    }

    cout << maxlen;
}