#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long double ld;

const ld x = -1.0;

ld dp[301][301][301];
int N;

ld E(int i, int j, int k)
{

    if (i == 0 && j == 0 && k == 0)
        return 0;

    if (dp[i][j][k] != x)
        return dp[i][j][k];

    ld sum = i + j + k;
    ld remove1 = ((i > 0) ? i * E(i - 1, j, k) / sum : 0);
    ld remove2 = ((j > 0) ? j * E(i + 1, j - 1, k) / sum : 0);
    ld remove3 = ((k > 0) ? k * E(i, j + 1, k - 1) / sum : 0);
    ld remove0 = ((1.0 * N) / sum);

    return dp[i][j][k] = (remove1 + remove2 + remove3 + remove0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= N; k++)
            {
                dp[i][j][k] = x;
            }
        }
    }

    int ct1 = 0, ct2 = 0, ct3 = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            ct1++;
            break;
        case 2:
            ct2++;
            break;
        default:
            ct3++;
            break;
        }
    }

    printf("%0.10Lf",E(ct1,ct2,ct3));
}