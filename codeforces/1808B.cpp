#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i, j;
        cin >> n >> m;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ll arr[n][m], totalsum = 0;
            vector<ll> colsum(m, 0);

            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {
                    cin >> arr[i][j];
                }
            }

            for (j = 0; j < m; j++)
            {
                for (i = 0; i < n; i++)
                {
                    colsum[j] += arr[i][j];
                }
            }

            for (j = 0; j < m; j++)
            {
                for (i = 0; i < n; i++)
                {
                    totalsum += abs(colsum[j] - 2 * arr[i][j]);
                }
            }

            cout << totalsum << endl;
        }
    }
}