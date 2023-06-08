#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s, i;
    cin >> m >> s;

    if (s == 0)
    {
        if (m == 1)
        {
            cout << 0 << " " << 0;
        }
        else
        {
            cout << -1 << " " << -1;
        }
    }
    else if (9 * m < s)
    {
        cout << -1 << " " << -1;
    }
    else
    {
        // for max
        string t1;
        int num = s;
        while (num >= 10)
        {
            t1.push_back('9');
            num -= 9;
        }
        t1.push_back('0' + num);
        for (i = t1.size() + 1; i <= m; i++)
        {
            t1.push_back('0');
        }

        // for min
        string t2;

        for (i = 0; i < m; i++)
        {
            t2.push_back('0');
        }
        t2[0] = '1';

        num = 1;
        i = t2.size() - 1;
        while (s - num >= 10)
        {
            t2[i] += 9;
            num += 9;
            i--;
        }
        t2[i] += (s - num);

        cout << t2 << " " << t1;
    }
}