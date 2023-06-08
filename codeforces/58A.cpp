#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, msg = "hello";
    int i, j;

    cin >> s;

    for (i = 0, j = 0; i < s.size() && j < 5; i++)
    {
        if (s[i] == msg[j])
            j++;
    }

    if (j == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}