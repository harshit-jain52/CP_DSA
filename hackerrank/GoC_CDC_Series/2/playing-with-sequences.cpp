#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 * 2000 + 1;
bitset<MAX> dp;

int main()
{
    int n;
    cin >> n;
    int tot = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        dp |= (dp << a);
        tot += a;
    }

    int find = tot / 2 + tot % 2;

    for (int i = find; i <= tot; i++)
    {
        if (dp[i])
        {
            cout << i;
            return 0;
        }
    }
}