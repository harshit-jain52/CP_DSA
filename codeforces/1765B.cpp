#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
    int t, n, flag;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> s;
        flag = 1;

        for (int i = 0; i < n; i++)
        {
            if (i % 3 == 1)
            {
                if (s[i] != s[i + 1])
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << "\n";
    }

    return 0;
}