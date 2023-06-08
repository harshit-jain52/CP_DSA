#include <bits/stdc++.h>
using namespace std;

int alpha[26]; // globally declared arrays are initialized to 0
int main()
{
    string s;
    int i, oddcount = 0;

    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        alpha[s[i] - 'a']++;
    }

    for (i = 0; i < 26; i++)
    {
        if (alpha[i] % 2 == 1)
        {
            oddcount++;
        }
    }

    if (oddcount > 1)
    {
        if (oddcount % 2 == 0)
        {
            cout << "Second";
        }
        else
        {
            cout << "First";
        }
    }
    else
    {
        cout << "First";
    }
}