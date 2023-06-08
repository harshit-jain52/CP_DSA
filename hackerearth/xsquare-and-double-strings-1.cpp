/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i, alpha[26];
    string S;

    cin >> T;

    while (T--)
    {
        cin >> S;

        for (i = 0; i < 26; i++)
        {
            alpha[i] = 0;
        }

        for (i = 0; i < S.size(); i++)
        {
            alpha[S[i] - 'a']++;
        }

        for (i = 0; i < 26; i++)
        {
            if (alpha[i] > 1)
            {
                break;
            }
        }

        if (i == 26)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}