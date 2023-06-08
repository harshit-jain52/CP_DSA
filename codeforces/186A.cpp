#include <bits/stdc++.h>
using namespace std;

int main()
{
    string g1, g2, s1, s2;
    int length, i, count = 0;
    cin >> g1 >> g2;
    s1 = g1;
    s2 = g2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // cout << g1 << endl;
    // cout << g2 << endl;
    // cout << s1 << s1.size() << endl;
    // cout << s2 << s2.size() << endl;
    // cout << (int)(s1 == s2);
    
    if (s1 == s2)
    {
        length = g1.size();
        for (i = 0; i < length; i++)
        {
            if (g1[i] != g2[i])
            {
                count++;
            }
            if (count > 2)
                break;
        }

        if (count == 0 || count == 2)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
}