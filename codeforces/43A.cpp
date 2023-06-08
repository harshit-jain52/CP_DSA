#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count1 = 0, count2 = 0, i;
    string s1, s2, temp;

    cin >> n;
    cin >> s1;
    count1++;

    for (i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp == s1)
        {
            count1++;
        }
        else
        {
            s2 = temp;
            count2++;
            i++;
            break;
        }
    }

    for (; i < n; i++)
    {
        cin >> temp;
        if (temp == s1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    // cout << count1 << "  " << count2 << endl;
    if (count1 > count2)
    {
        cout << s1;
    }
    else
    {
        cout << s2;
    }
}