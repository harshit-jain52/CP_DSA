#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int i, n = s.size(), ct = 0;

    for (i = 0; i < n; i++)
    {
        if (s[i] == 'T')
        {
            ct++;
        }
        else if (s[i] == 'M')
        {
            if (ct > 0)
            {
                ct--;
            }
            else
            {
                break;
            }
        }
    }

    if (i == n && ct == n / 3)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        string s;
        cin >> s;
        bool flag1 = check(s);
        reverse(s.begin(), s.end());
        bool flag2 = check(s);

        if (flag1 && flag2)
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