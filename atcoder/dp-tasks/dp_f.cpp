#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    string s, t;
    cin >> s >> t;

    int n1 = s.size(), n2 = t.size();

    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string str = "";
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            str.push_back(s[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(str.begin(), str.end());

    cout << str;
}