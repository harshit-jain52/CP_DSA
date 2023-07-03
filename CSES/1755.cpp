#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    vector<int> alpha(26, 0);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        alpha[s[i] - 'A']++;
    }

    int oddct = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] % 2 == 1)
            oddct++;
    }

    if (oddct > 1)
        cout << "NO SOLUTION";
    else
    {
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans.push_back('_');
        }

        int i = 0, j = n - 1;
        for (int k = 0; k < 26; k++)
        {
            if (alpha[k] % 2 == 1)
            {
                ans[n / 2] = 'A' + k;
                for (int _ = 1; _ <= (alpha[k] - 1) / 2; _++)
                {
                    ans[i] = ans[j] = k + 'A';
                    i++;
                    j--;
                }
            }
            else
            {
                for (int _ = 1; _ <= alpha[k] / 2; _++)
                {
                    ans[i] = ans[j] = k + 'A';
                    i++;
                    j--;
                }
            }
        }

        cout << ans;
    }
}