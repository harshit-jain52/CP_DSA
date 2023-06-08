#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size(), idx;
        char c;

        c = '0';
        idx = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
            {
                c = s[i];
                idx = i;
                break;
            }
        }

        for (int i = 0; i <= idx; i++)
        {
            s[i] = c;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = s[i - 1];
            }
        }

        cout << s << endl;
    }
}