#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e7;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    int dp[h][w];

    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < w; j++)
            dp[i][j] = dp[i][j] = INF;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = (grid[0][0] == '#');
                continue;
            }
            int cost = INF;
            if (grid[i][j] == '.')
            {
                if (i > 0)
                    cost = min(cost, dp[i - 1][j]);
                if (j > 0)
                    cost = min(cost, dp[i][j - 1]);
            }
            else
            {
                if (i > 0)
                    cost = min(cost, (grid[i - 1][j] == '.') + dp[i - 1][j]);
                if (j > 0)
                    cost = min(cost, (grid[i][j - 1] == '.') + dp[i][j - 1]);
            }
            dp[i][j] = cost;
        }
    }
    cout << dp[h - 1][w - 1];
}