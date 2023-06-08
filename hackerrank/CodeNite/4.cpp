#include <bits/stdc++.h>
using namespace std;

int fn(string s, int start)
{
    int count0 = 0, count1 = 0;
    for (int i = start; i < s.size(); i += 4)
    {
        if (s[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }

    return min(count0, count1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, swch = 0;
        string s, s1 = "", s2 = "";
        cin >> n;
        cin >> s;

        for (i = 0; i < n; i++)
        {
            if ((i + 1) % 8 > 4 || (i + 1) % 8 == 0)
            {
                s2.push_back(s[i]);
            }
            else
            {
                s1.push_back(s[i]);
            }
        }

        for (i = 0; i < s1.size(); i++)
        {
            if ((i + 1) % 8 == 5)
            {
                swap(s1[i], s1[i + 3]);
                swap(s1[i + 1], s1[i + 2]);
            }
        }
        // cout << s1 << endl
        //      << s2 << endl
        //      << endl;
        for (i = 0; i < s2.size(); i++)
        {
            if ((i + 1) % 8 == 5)
            {
                swap(s2[i], s2[i + 3]);
                swap(s2[i + 1], s2[i + 2]);
            }
        }

        swch = fn(s1, 0) + fn(s1, 1) + fn(s1, 2) + fn(s1, 3) + fn(s2, 0) + fn(s2, 1) + fn(s2, 2) + fn(s2, 3);

        cout << swch << endl;
    }
}