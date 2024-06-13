#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int colbl[510], colwh[510];
int rowbl[510][250001], rowwh[510][250001];

int main()
{
    FASTIO
    int n, k;
    cin >> n >> k;

    // Rotate the board by 45 degrees and solve black and white separately

    int szbl = 0, szwh = 0;
    for (int i = 1; i <= n; i += 2) // odd rows - black
    {
        colbl[++szbl] = i;
        if (i != n)
            colbl[++szbl] = i;
    }
    for (int i = 2; i <= n; i += 2) // even rows - white
    {
        colwh[++szwh] = i;
        if (i != n)
            colwh[++szwh] = i;
    }

    // R[i][j] = ways to place j bishops in first i rows
    rowbl[0][0] = rowwh[0][0] = 1;
    for (int i = 1; i <= szbl; i++)
    {
        for (int j = 0; j <= colbl[i]; j++)
        {
            if (j == 0)
            {
                rowbl[i][j] = rowbl[i - 1][j];
                continue;
            }
            rowbl[i][j] = (rowbl[i - 1][j] + (rowbl[i - 1][j - 1] * 1LL * (colbl[i] - (j - 1))) % M) % M;
        }
    }
    for (int i = 1; i <= szwh; i++)
    {
        for (int j = 0; j <= colwh[i]; j++)
        {
            if (j == 0)
            {
                rowwh[i][j] = rowwh[i - 1][j];
                continue;
            }
            rowwh[i][j] = (rowwh[i - 1][j] + (rowwh[i - 1][j - 1] * 1LL * (colwh[i] - (j - 1))) % M) % M;
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = (ans + (rowbl[szbl][i] * 1LL * rowwh[szwh][k - i]) % M) % M;
    cout << ans;
}