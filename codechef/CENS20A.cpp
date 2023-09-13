#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (int)(c == '1');
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 0-based
        x1--;
        y1--;
        x2--;
        y2--;

        dp[x1][y1]++;
        dp[x2 + 1][y1]--;
        dp[x1][y2 + 1]--;
        dp[x2+1][y2+1]++;
    }

    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            prefix_sum[i + 1][j + 1] = dp[i][j] + prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j];

            a[i][j] = (prefix_sum[i + 1][j + 1] % 2 == 0) ? a[i][j] : !a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}