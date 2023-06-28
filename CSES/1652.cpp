#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '*');
        }
    }

    int prefix_sum[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        prefix_sum[0][i] = 0;
        prefix_sum[i][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prefix_sum[i + 1][j + 1] = a[i][j] + prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j];
        }
    }

    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << prefix_sum[y2][x2] - prefix_sum[y2][x1 - 1] - prefix_sum[y1 - 1][x2] + prefix_sum[y1 - 1][x1 - 1] << endl;
    }
}