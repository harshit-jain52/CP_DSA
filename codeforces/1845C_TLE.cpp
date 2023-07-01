#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 3e5 + 5;
int dp[N][15];

int lcs(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    ans = max(lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]), max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2)));

    return dp[i][j] = ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, l, r;
        int m, n;
        cin >> s;
        cin >> m;
        cin >> l >> r;
        n = s.size();

        set<string> allCombinations;
        for (char c = l[0]; c <= r[0]; c++)
        {
            string str = "";
            str.push_back(c);
            allCombinations.insert(str);
        }
        for (int i = 1; i < m; i++)
        {
            set<string> tmpCombinations;
            for (auto it : allCombinations)
            {
                for (char c = l[i]; c <= r[i]; c++)
                {
                    string str = it;
                    str.push_back(c);
                    tmpCombinations.insert(str);
                }
            }
            allCombinations = tmpCombinations;
            tmpCombinations.clear();
        }

        bool ans = false;
        for (auto it : allCombinations)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dp[i][j] = -1;
                }
            }
            if (lcs(n - 1, m - 1, s, it) != m)
            {
                ans = true;
                break;
            }
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}