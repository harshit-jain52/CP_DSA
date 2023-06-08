#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    int i, j, flag;
    getline(cin, s1);
    getline(cin, s2);

    for (i = 0; i < s2.size(); i++)
    {
        if (s2[i] == ' ')
            continue;
        flag = 0;
        for (j = 0; j < s1.size(); j++)
        {
            if (s1[j] == ' ')
                continue;

            if (s1[j] == s2[i])
            {
                s1[j] = ' ';
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    if (i == s2.size())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}