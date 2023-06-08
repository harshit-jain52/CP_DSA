#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(string s)
{
    int flag = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        if (isBeautiful(s1) && isBeautiful(s2))
        {
            cout << "YES";
        }
        else if (!isBeautiful(s1) && !isBeautiful(s2))
        {
            cout << "NO";
        }
        else if (isBeautiful(s1) && !isBeautiful(s2))
        {
            if (s1[n - 1] == s2[m - 1])
            {
                cout << "NO";
            }
            else
            {
                int cnt = 0;
                for (int i = 1; i < m; i++)
                {
                    if (s2[i] == s2[i - 1])
                    {
                        cnt++;
                    }
                }
                if (cnt > 1)
                {
                    cout << "NO";
                }
                else
                {
                    cout << "YES";
                }
            }
        }
        else
        {
            if (s1[n - 1] == s2[m - 1])
            {
                cout << "NO";
            }
            else
            {
                int cnt = 0;
                for (int i = 1; i < n; i++)
                {
                    if (s1[i] == s1[i - 1])
                    {
                        cnt++;
                    }
                }
                if (cnt > 1)
                {
                    cout << "NO";
                }
                else
                {
                    cout << "YES";
                }
            }
        }
        cout << '\n';
    }
}