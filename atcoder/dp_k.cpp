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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool dp[k + 1][2];
    dp[0][0] = dp[0][1] = false;
    int i, p, j;

    for (i = 1; i <= k; i++)
    {
        for (p = 0; p < 2; p++)
        {
            bool ans = false;
            for (j = 0; j < n; j++)
            {
                if (a[j] <= i)
                {
                    ans |= !(dp[i - a[j]][!p]);
                }
                dp[i][p] = ans;
            }
        }
    }

    cout << ((dp[k][0]) ? "First" : "Second");
}