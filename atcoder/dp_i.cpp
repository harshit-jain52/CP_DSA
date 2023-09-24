#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long double ld;

const ld x = -1.0;
ld dp[3000][3000];
int N;

ld func(int idx, int ct, ld p[])
{
    if (idx <= 0)
    {
        if (ct < (N + 1) / 2)
            return 0;
        else
            return 1;
    }

    if (dp[idx][ct] != x)
        return dp[idx][ct];

    return dp[idx][ct] = p[idx] * func(idx - 1, ct + 1, p) + (1 - p[idx]) * func(idx - 1, ct, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    ld p[N + 1];
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dp[i][j] = x;
        }
    }

    printf("%0.10Lf", func(N, 0, p));
}