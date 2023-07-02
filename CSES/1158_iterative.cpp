#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    pair<int, int> books[n];

    for (int i = 0; i < n; i++)
    {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> books[i].second;
    }
    sort(books, books + n);

    int stop = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (books[i].first <= x)
        {
            stop = i;
            break;
        }
    }
    if (stop == -1)
    {
        cout << 0;
    }
    else
    {
        int dp[stop + 1][x + 1];
        memset(dp, 0, sizeof(dp));
        int minprice = books[0].first;
        for (int i = minprice; i <= x; i++)
        {
            dp[0][i] = books[0].second;
        }

        for (int i = 1; i <= stop; i++)
        {
            for (int j = minprice; j <= x; j++)
            {
                int tmp = -1;
                if (j >= books[i].first)
                {
                    tmp = books[i].second + dp[i - 1][j - books[i].first];
                }
                dp[i][j] = max(dp[i - 1][j], tmp);
            }
        }

        cout << dp[stop][x];
    }
}