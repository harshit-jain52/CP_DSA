#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

int getSignificantBits(int x)
{
    int i;
    for (i = 0;; i++)
    {
        if (x < (1 << i))
        {
            return i - 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lim = getSignificantBits(N - 1);
    int a[N][lim + 1];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= lim; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int num = 1; num < N; num++)
    {
        for (int j = 0; j <= lim; j++)
        {
            if (!((num >> j) & 1))
            {
                a[num][j]++;
            }
        }
    }
    for (int num = 1; num < N; num++)
    {
        for (int j = 0; j <= lim; j++)
        {
            a[num][j] += a[num - 1][j];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r, ct = 2e5 + 1;
        cin >> l >> r;

        for (int i = 0; i <= lim; i++)
        {
            int diff = a[r][i] - a[l - 1][i];
            if (diff < ct)
            {
                ct = diff;
            }
        }

        cout << ct << endl;
    }
}