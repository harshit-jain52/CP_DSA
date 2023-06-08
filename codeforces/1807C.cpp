#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, isum, j;
        string s;
        vector<vector<int>> indices(26);

        cin >> n;
        cin >> s;

        for (i = 0; i < n; i++)
        {
            indices[s[i] - 'a'].push_back(i);
        }

        for (i = 0; i < 26; i++)
        {
            isum = 0;
            for (j = 0; j < indices[i].size(); j++)
            {
                isum += indices[i][j] % 2;
            }

            if (isum != 0 && isum != indices[i].size())
            {
                break;
            }
        }
        if (i == 26)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << endl;
    }
}