#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, flag = 0, ct = 0;
    cin >> n;
    string s, t = "";
    cin >> s;

    for (i = 0; i < n; i++)
    {
        if (s[i] == 'b')
        {
            if (flag)
            {
                ct += t.size();
                flag = 0;
            }
            t = "";
        }
        else
        {
            t.push_back(s[i]);
            if (s[i] == 'a')
            {
                flag = 1;
            }
        }
    }
    if (flag)
        ct += t.size();


    cout << ct;
}