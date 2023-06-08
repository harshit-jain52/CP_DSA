#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> alpha(26, 0);
    int k, i, j;
    string s, part = "";

    cin >> k >> s;

    for (i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'a']++;
    }

    for (i = 0; i < 26; i++)
    {
        if (alpha[i] % k != 0)
        {
            break;
        }
    }

    if (i == 26)
    {
        for (i = 0; i < 26; i++)
        {
            for (j = 0; j < alpha[i] / k; j++)
            {
                part.push_back('a' + i);
            }
        }

        for (i = 0; i < k; i++)
        {
            cout << part;
        }
    }
    else
    {
        cout << -1;
    }
}