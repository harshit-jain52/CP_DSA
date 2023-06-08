#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t, check = "";
    int i;

    cin >> s >> t;

    for (i = s.size() - 1; i >= 0; i--)
    {
        check.push_back(s[i]);
    }

    if (check == t)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}